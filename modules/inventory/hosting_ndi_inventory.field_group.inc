<?php
/**
 * @file
 * hosting_ndi_inventory.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hosting_ndi_inventory_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_client_poc1|node|site|default';
  $field_group->group_name = 'group_client_poc1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_inventory';
  $field_group->data = array(
    'label' => 'Client POC 1',
    'weight' => '10',
    'children' => array(
      0 => 'field_client_poc1_first_name',
      1 => 'field_client_poc1_last_name',
      2 => 'field_client_poc1_email',
      3 => 'field_client_poc1_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Client POC 1',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-client-poc1 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_client_poc2|node|site|default';
  $field_group->group_name = 'group_client_poc2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_inventory';
  $field_group->data = array(
    'label' => 'Client POC 2',
    'weight' => '11',
    'children' => array(
      0 => 'field_client_poc2_first_name',
      1 => 'field_client_poc2_last_name',
      2 => 'field_client_poc2_email',
      3 => 'field_client_poc2_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Client POC 2',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-client-poc2 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inventory|node|site|default';
  $field_group->group_name = 'group_inventory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inventory information',
    'weight' => '0',
    'children' => array(
      0 => 'field_ndi_environment',
      1 => 'field_inventory_enabled',
      2 => 'field_client_organization_team',
      3 => 'field_client_country',
      4 => 'field_client_type',
      5 => 'field_site_status',
      6 => 'field_ndi_region',
      7 => 'group_client_poc1',
      8 => 'group_client_poc2',
      9 => 'group_ndi_poc',
      10 => 'group_nditech_poc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Inventory information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-inventory field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ndi_poc|node|site|default';
  $field_group->group_name = 'group_ndi_poc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_inventory';
  $field_group->data = array(
    'label' => 'NDI POC',
    'weight' => '12',
    'children' => array(
      0 => 'field_ndi_poc_first_name',
      1 => 'field_ndi_poc_last_name',
      2 => 'field_ndi_poc_phone',
      3 => 'field_ndi_poc_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'NDI POC',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-ndi-poc field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nditech_poc|node|site|default';
  $field_group->group_name = 'group_nditech_poc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_inventory';
  $field_group->data = array(
    'label' => 'NDItech POC',
    'weight' => '13',
    'children' => array(
      0 => 'field_nditech_poc_first_name',
      1 => 'field_nditech_poc_last_name',
      2 => 'field_nditech_manager_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'NDItech POC',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-nditech-poc field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Client POC 1');
  t('Client POC 2');
  t('Inventory information');
  t('NDI POC');
  t('NDItech POC');

  return $field_groups;
}
