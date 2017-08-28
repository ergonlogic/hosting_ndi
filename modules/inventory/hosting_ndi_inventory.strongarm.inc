<?php
/**
 * @file
 * hosting_ndi_inventory.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hosting_ndi_inventory_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ndi_inventory_fields';
  $strongarm->value = array(
    'field_ndi_environment' => 'field_ndi_environment',
    'field_inventory_enabled' => 'field_inventory_enabled',
    'field_client_organization_team' => 'field_client_organization_team',
    'field_client_country' => 'field_client_country',
    'field_client_poc1_first_name' => 'field_client_poc1_first_name',
    'field_client_poc1_last_name' => 'field_client_poc1_last_name',
    'field_client_poc1_email' => 'field_client_poc1_email',
    'field_client_poc1_phone' => 'field_client_poc1_phone',
    'field_client_poc2_first_name' => 'field_client_poc2_first_name',
    'field_client_poc2_last_name' => 'field_client_poc2_last_name',
    'field_client_poc2_email' => 'field_client_poc2_email',
    'field_client_poc2_phone' => 'field_client_poc2_phone',
    'field_ndi_poc_first_name' => 'field_ndi_poc_first_name',
    'field_ndi_poc_last_name' => 'field_ndi_poc_last_name',
    'field_ndi_poc_phone' => 'field_ndi_poc_phone',
    'field_ndi_poc_email' => 'field_ndi_poc_email',
    'field_nditech_poc_first_name' => 'field_nditech_poc_first_name',
    'field_nditech_poc_last_name' => 'field_nditech_poc_last_name',
    'field_nditech_manager_email' => 'field_nditech_manager_email',
    'field_client_type' => 'field_client_type',
    'field_site_status' => 'field_site_status',
    'field_ndi_region' => 'field_ndi_region',
  );
  $export['ndi_inventory_fields'] = $strongarm;

  return $export;
}
