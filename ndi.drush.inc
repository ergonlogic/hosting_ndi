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
 * Implements drush_hook_post_COMMAND().
 */
function drush_ndi_post_provision_install() {
  drush_log('Registered NDI CiviCRM extension: ' . d()->ndi_civi_ext);
}
