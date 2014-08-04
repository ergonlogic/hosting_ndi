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
      drush_set_error('NDI CIVICRM EXTENSION','ERROR: Could not find an NDI CiviCRM extension callback.');
    }
  }
}
