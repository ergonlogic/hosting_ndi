<?php
/**
 * @file
 *   The hosting feature definition for NDI CiviCRM extensions.
 */

/**
 * Register a hosting feature with Aegir.
 *
 * This will be used to generate the 'admin/hosting' page.
 *
 * @return
 *  associative array indexed by feature key.
 */
function hosting_ndi_hosting_feature() {
  $features['ndi'] = array(
    'title' => t('NDI CiviCRM extensions'),
    'description' => t('Controls for enabling CiviCRM extensions on provisioned sites.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_ndi',
    'group' => 'experimental'
    );
  return $features;
}
