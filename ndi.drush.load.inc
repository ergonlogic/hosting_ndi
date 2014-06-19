<?php

/**
 * Implements hook_drush_load().
 *
 * Checks if the corresponsing Hosting Feature is enabled.
 */
function ndi_drush_load() {
  $features = drush_get_option('hosting_features', array());
  return array_key_exists('ndi', $features) && $features['ndi'];
}
