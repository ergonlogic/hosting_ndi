<?php

/**
 * Implements hook_drush_init().
 */
function ndi_drush_init() {
  ndi_provision_register_autoload();
}

/**
 * Register our directory as a place to find provision classes.
 */
function ndi_provision_register_autoload() {
  static $loaded = FALSE;
  if (!$loaded) {
    $loaded = TRUE;
    provision_autoload_register_prefix('Provision_', dirname(__FILE__));
  }
}

/**
 * Expose the service type this extension defines to provision.
 *
 * @return
 *   An array with the service type the key, and the default implementation the value.
 */
function ndi_provision_services() {
  ndi_provision_register_autoload();
  return array('ndi' => NULL);
}

/**
 * Enable a CiviCRM extension.
 *
 * Overkill. TODO: reduce this as CiviCRM allows.
 */
function ndi_enable_extensions($extensions) {

  civicrm_initialize();
  // Optional: Scan source tree for extensions
  civicrm_api3('Extension', 'refresh', array());
  civicrm_api3('System', 'flush', array());

  foreach ($extensions as $extension) {
    drush_log('Enabling NDI CiviCRM Extension: ' . $extension, 'ok');
    // Enable the extensions
    civicrm_api3('Extension', 'install', array(
      'key' => $extension,
    ));

    // Manually flush cache. This is currently a work-around for a bug,
    // according to @totten.
    // This appears to need to be in a separate PHP process, so we call it via
    // Drush. We clear all caches to also ensure menu settings are updated.
#    drush_invoke_process('@self', 'civicrm-api', array('System.flush'));

    // Clear cache so that our change to the frontpage takes effect. We do this
    // last, to ensure that the civi-case path exists.
    #drush_invoke_process('@self', 'cache-clear', array('registry'));
  }
}

/**
 * Enable/disable CiviCRM components.
 */
function ndi_enable_components($components) {
  drush_log('Enabling required CiviCRM components, and disabling unsused components.', 'ok');
  civicrm_api3('setting', 'create', array(
    'domain_id' => CRM_Core_Config::domainID(),
    'enable_components' => $components,
    )
  );
}

/**
 * Enable Drupal modules.
 */
function ndi_enable_modules($modules) {
  // Turn off strict option checking temporarily, if enabled.
  $strict = drush_get_option('strict', FALSE);
  drush_set_option('strict', FALSE);

  foreach ($modules as $module) {
    drush_log("Enabling ${module} module.", 'ok');
    drush_invoke('pm-enable', array($module));
  }

  // Set strict option checking back to previous setting.
  drush_set_option('strict', $strict);

}

/**
 * Set the API key for the 'admin' user on the master server.
 */
function _ndi_civicrm_set_api_key($site, $key) {
  $args = [
    'Contact.create',
    'contact_type=Individual',
    'id=2',
    "api_key=$key",
  ];
  $opts = [];
  $result = drush_invoke_process($site, 'cvapi', $args, $opts, array('method' => 'POST', 'integrate' => FALSE));
  return $result['object'];
}

/**
 * Implements hook_civicrm_settings_template_alter().
 *
 * @see provision_civicrm_civicrm_settings_parameters_alter().
 */
function ndi_civicrm_settings_template_alter(&$template) {
  $master_site_url = 'https://civisociet-170b.demcloud.org';
  $site_key = d()->civicrm_sitekey;
  // We use the generated sitekey for the master server as the API key.
  $api_key = d($master_site_url)->civicrm_sitekey;
  // If the current site is the master, then we also set the API key for the 'admin' user.
  if (d()->uri == $master_site_url) {
    _ndi_civicrm_set_api_key($master_site_url, $api_key);
  }
  $master_reporting_url = "https://{$master_site_url}/sites/all/modules/contrib/civicrm/extern/rest.php?entity=Metrics&action=report&key={$site_key}&api_key={$api_key}";

  $site_name = ndi_execute(d()->name, 'drush_backend_set_result(variable_get("site_name"));');

  $replacements = array();

  if (version_compare(d()->civicrm_version, '4.7', 'lt')) {
    $replacements['insert NDI metrics settings.'] = array(
      'search_regex' => '/^.*?civicrm_setting.*versionAlert.*\n?/m',
      'replace_line' => " // \$civicrm_setting['CiviCRM Preferences']['versionAlert']; = false;\n",
    );
  }
  else {
    $replacements['insert NDI metrics settings.'] = array(
      'search_regex' => '/^.*?civicrm_setting.*logging_no_trigger_permission.*\n?/m',
      'replace_line' => " // \$civicrm_setting['CiviCRM Preferences']['logging_no_trigger_permission'] = 1;\n",
    );
  }

  $replacements['insert NDI metrics settings.']['replace_line'] .= "
    // Configuration added in ndi_civicrm_settings_template_alter()
    \$civicrm_setting['metrics']['metrics_reporting_url'] = '{$master_reporting_url}';\n
    \$civicrm_setting['metrics']['metrics_site_name'] = '{$site_name}';\n
    \$civicrm_setting['metrics']['metrics_ca_path'] = '';\n
    \$civicrm_setting['metrics']['metrics_ignore_verify_peer'] = TRUE;\n
    \$civicrm_setting['metrics']['metrics_ignore_verify_host'] = TRUE;\n
  ";

  foreach ($replacements as $desc => $line) {
    // Throw a warning if any of our replacements cannot be found.
    if (!preg_match($line['search_regex'], $template)) {
      drush_log(dt('CiviCRM: Failed to ' . $desc), 'warning');
    }
    else {
      $count = 0;
      $template = preg_replace($line['search_regex'], $line['replace_line'], $template, -1, $count);
      if ($count > 0) {
        drush_log(dt('CiviCRM: Succeeded to ' . $desc), 'success');
      }
    }
  }
}

function ndi_execute($site, $code) {
  $result = drush_invoke_process($site, ' php-eval \'' . $code . '\'', array(), array(), array('method' => 'POST', 'integrate' => TRUE));
  return $result['object'];
}

