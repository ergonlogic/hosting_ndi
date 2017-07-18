<?php
/**
 * @file
 * hosting_ndi_inventory.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hosting_ndi_inventory_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-site-field_inventory_enabled'.
  $field_instances['node-site-field_inventory_enabled'] = array(
    'bundle' => 'site',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Include this site in the site inventory.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inventory_enabled',
    'label' => 'Inventory enabled',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-site-field_ndi_environment'.
  $field_instances['node-site-field_ndi_environment'] = array(
    'bundle' => 'site',
    'default_value' => array(
      0 => array(
        'value' => 'Development',
      ),
    ),
    'deleted' => 0,
    'description' => 'Specify the environment for this site.

This will affect the site\'s support status, and show up in the consolidated site inventory.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ndi_environment',
    'label' => 'Environment',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Environment');
  t('Include this site in the site inventory.');
  t('Inventory enabled');
  t('Specify the environment for this site.

This will affect the site\'s support status, and show up in the consolidated site inventory.');

  return $field_instances;
}
