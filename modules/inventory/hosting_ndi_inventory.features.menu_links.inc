<?php
/**
 * @file
 * hosting_ndi_inventory.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hosting_ndi_inventory_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_site-inventory:hosting/ndi_site_list/inventory.
  $menu_links['management_site-inventory:hosting/ndi_site_list/inventory'] = array(
    'menu_name' => 'management',
    'link_path' => 'hosting/ndi_site_list/inventory',
    'router_path' => 'hosting/ndi_site_list/inventory',
    'link_title' => 'Site Inventory',
    'options' => array(
      'attributes' => array(
        'title' => 'NDI Site Inventory',
      ),
      'identifier' => 'management_site-inventory:hosting/ndi_site_list/inventory',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_ndi:admin/hosting/ndi',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Site Inventory');

  return $menu_links;
}
