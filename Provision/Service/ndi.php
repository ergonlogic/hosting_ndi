<?php

/**
 * The ndi service class.
 */
class Provision_Service_ndi extends Provision_Service {
  public $service = 'ndi';

  /**
   * Add the needed properties to the site context.
   */
  static function subscribe_site($context) {
    $context->setProperty('ndi_civi_ext');
    drush_log('Registered NDI CiviCRM extension: ' . implode(', ' , d()->ndi_civi_ext));
  }
}
