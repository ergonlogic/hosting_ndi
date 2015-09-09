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
 * Implements hook_drush_callback_list_alter().
 *
 * Ensure our hook_post_provision_install comes after provision_civicrm's. We
 * can't configure CiviCRM until it's installed.
 *
 * @see: https://github.com/drush-ops/drush/pull/223.
 */
function ndi_drush_callback_list_alter($callback_list, $var_hook, $command, $args) {
  drush_log('ndi_drush_callback_list_alter');
  if ($var_hook == 'post_provision_install') {
    // Retrieve the name of our callback.
    if ($callback_name = drush_get_option('ndi_civi_ext_callback', FALSE)) {
      // Find the index of our callback, and pull it out of the list.
      if ($index = array_search($callback_name, array_keys($callback_list))) {
        $callback = array_splice($callback_list, $index, 1);
        // Find where to insert our callback, and add it back to the list.
        $target = array_search('drush_provision_civicrm_post_provision_install', array_keys($callback_list));
        $tail = array_splice($callback_list, $target + 1);
        $callback_list += $callback + $tail;
      }
    }
    else {
//      drush_set_error('NDI CIVICRM EXTENSION','ERROR: Could not find an NDI CiviCRM extension callback.');
      // Test
      drush_log('ERROR: Could not find an NDI CiviCRM extension callback.');
    }
  }
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
    drush_invoke_process('@self', 'civicrm-api', array('System.flush'));

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

