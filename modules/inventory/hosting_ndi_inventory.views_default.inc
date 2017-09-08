<?php
/**
 * @file
 * hosting_ndi_inventory.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hosting_ndi_inventory_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ndi_site_inventory';
  $view->description = 'Display a list of sites hosted in Aegir.';
  $view->tag = 'hosting_site';
  $view->base_table = 'node';
  $view->human_name = 'NDI Site Inventory';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Site inventory';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'status' => 'status',
    'title' => 'title',
    'title_3' => 'title_3',
    'created' => 'created',
    'title_2' => 'title_2',
    'verified' => 'verified',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'verified' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Relationship: Hosting Site: Install Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: Hosting Site: Platform */
  $handler->display->display_options['relationships']['platform']['id'] = 'platform';
  $handler->display->display_options['relationships']['platform']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['platform']['field'] = 'platform';
  /* Relationship: Content: Country (field_client_country) */
  $handler->display->display_options['relationships']['field_client_country_iso2']['id'] = 'field_client_country_iso2';
  $handler->display->display_options['relationships']['field_client_country_iso2']['table'] = 'field_data_field_client_country';
  $handler->display->display_options['relationships']['field_client_country_iso2']['field'] = 'field_client_country_iso2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/node/[nid]/inventory';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Site status */
  $handler->display->display_options['fields']['field_site_status']['id'] = 'field_site_status';
  $handler->display->display_options['fields']['field_site_status']['table'] = 'field_data_field_site_status';
  $handler->display->display_options['fields']['field_site_status']['field'] = 'field_site_status';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'platform';
  $handler->display->display_options['fields']['title_2']['label'] = 'Platform';
  $handler->display->display_options['fields']['title_2']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_2']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_3']['id'] = 'title_3';
  $handler->display->display_options['fields']['title_3']['table'] = 'node';
  $handler->display->display_options['fields']['title_3']['field'] = 'title';
  $handler->display->display_options['fields']['title_3']['relationship'] = 'profile';
  $handler->display->display_options['fields']['title_3']['label'] = 'Install Profile';
  $handler->display->display_options['fields']['title_3']['link_to_node'] = FALSE;
  /* Field: Content: Client type */
  $handler->display->display_options['fields']['field_client_type']['id'] = 'field_client_type';
  $handler->display->display_options['fields']['field_client_type']['table'] = 'field_data_field_client_type';
  $handler->display->display_options['fields']['field_client_type']['field'] = 'field_client_type';
  /* Field: Content: Client (Organization/Team) */
  $handler->display->display_options['fields']['field_client_organization_team']['id'] = 'field_client_organization_team';
  $handler->display->display_options['fields']['field_client_organization_team']['table'] = 'field_data_field_client_organization_team';
  $handler->display->display_options['fields']['field_client_organization_team']['field'] = 'field_client_organization_team';
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_ndi_region']['id'] = 'field_ndi_region';
  $handler->display->display_options['fields']['field_ndi_region']['table'] = 'field_data_field_ndi_region';
  $handler->display->display_options['fields']['field_ndi_region']['field'] = 'field_ndi_region';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_client_country']['id'] = 'field_client_country';
  $handler->display->display_options['fields']['field_client_country']['table'] = 'field_data_field_client_country';
  $handler->display->display_options['fields']['field_client_country']['field'] = 'field_client_country';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_client_poc1_first_name']['id'] = 'field_client_poc1_first_name';
  $handler->display->display_options['fields']['field_client_poc1_first_name']['table'] = 'field_data_field_client_poc1_first_name';
  $handler->display->display_options['fields']['field_client_poc1_first_name']['field'] = 'field_client_poc1_first_name';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_client_poc1_last_name']['id'] = 'field_client_poc1_last_name';
  $handler->display->display_options['fields']['field_client_poc1_last_name']['table'] = 'field_data_field_client_poc1_last_name';
  $handler->display->display_options['fields']['field_client_poc1_last_name']['field'] = 'field_client_poc1_last_name';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_client_poc1_phone']['id'] = 'field_client_poc1_phone';
  $handler->display->display_options['fields']['field_client_poc1_phone']['table'] = 'field_data_field_client_poc1_phone';
  $handler->display->display_options['fields']['field_client_poc1_phone']['field'] = 'field_client_poc1_phone';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_client_poc1_email']['id'] = 'field_client_poc1_email';
  $handler->display->display_options['fields']['field_client_poc1_email']['table'] = 'field_data_field_client_poc1_email';
  $handler->display->display_options['fields']['field_client_poc1_email']['field'] = 'field_client_poc1_email';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_client_poc2_first_name']['id'] = 'field_client_poc2_first_name';
  $handler->display->display_options['fields']['field_client_poc2_first_name']['table'] = 'field_data_field_client_poc2_first_name';
  $handler->display->display_options['fields']['field_client_poc2_first_name']['field'] = 'field_client_poc2_first_name';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_client_poc2_last_name']['id'] = 'field_client_poc2_last_name';
  $handler->display->display_options['fields']['field_client_poc2_last_name']['table'] = 'field_data_field_client_poc2_last_name';
  $handler->display->display_options['fields']['field_client_poc2_last_name']['field'] = 'field_client_poc2_last_name';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_client_poc2_email']['id'] = 'field_client_poc2_email';
  $handler->display->display_options['fields']['field_client_poc2_email']['table'] = 'field_data_field_client_poc2_email';
  $handler->display->display_options['fields']['field_client_poc2_email']['field'] = 'field_client_poc2_email';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_client_poc2_phone']['id'] = 'field_client_poc2_phone';
  $handler->display->display_options['fields']['field_client_poc2_phone']['table'] = 'field_data_field_client_poc2_phone';
  $handler->display->display_options['fields']['field_client_poc2_phone']['field'] = 'field_client_poc2_phone';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_ndi_poc_first_name']['id'] = 'field_ndi_poc_first_name';
  $handler->display->display_options['fields']['field_ndi_poc_first_name']['table'] = 'field_data_field_ndi_poc_first_name';
  $handler->display->display_options['fields']['field_ndi_poc_first_name']['field'] = 'field_ndi_poc_first_name';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_ndi_poc_last_name']['id'] = 'field_ndi_poc_last_name';
  $handler->display->display_options['fields']['field_ndi_poc_last_name']['table'] = 'field_data_field_ndi_poc_last_name';
  $handler->display->display_options['fields']['field_ndi_poc_last_name']['field'] = 'field_ndi_poc_last_name';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_ndi_poc_phone']['id'] = 'field_ndi_poc_phone';
  $handler->display->display_options['fields']['field_ndi_poc_phone']['table'] = 'field_data_field_ndi_poc_phone';
  $handler->display->display_options['fields']['field_ndi_poc_phone']['field'] = 'field_ndi_poc_phone';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_ndi_poc_email']['id'] = 'field_ndi_poc_email';
  $handler->display->display_options['fields']['field_ndi_poc_email']['table'] = 'field_data_field_ndi_poc_email';
  $handler->display->display_options['fields']['field_ndi_poc_email']['field'] = 'field_ndi_poc_email';
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_nditech_poc_first_name']['id'] = 'field_nditech_poc_first_name';
  $handler->display->display_options['fields']['field_nditech_poc_first_name']['table'] = 'field_data_field_nditech_poc_first_name';
  $handler->display->display_options['fields']['field_nditech_poc_first_name']['field'] = 'field_nditech_poc_first_name';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_nditech_poc_last_name']['id'] = 'field_nditech_poc_last_name';
  $handler->display->display_options['fields']['field_nditech_poc_last_name']['table'] = 'field_data_field_nditech_poc_last_name';
  $handler->display->display_options['fields']['field_nditech_poc_last_name']['field'] = 'field_nditech_poc_last_name';
  /* Field: Content: Manager email */
  $handler->display->display_options['fields']['field_nditech_manager_email']['id'] = 'field_nditech_manager_email';
  $handler->display->display_options['fields']['field_nditech_manager_email']['table'] = 'field_data_field_nditech_manager_email';
  $handler->display->display_options['fields']['field_nditech_manager_email']['field'] = 'field_nditech_manager_email';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Inventory enabled (field_inventory_enabled) */
  $handler->display->display_options['filters']['field_inventory_enabled_value']['id'] = 'field_inventory_enabled_value';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['table'] = 'field_data_field_inventory_enabled';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['field'] = 'field_inventory_enabled_value';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['value'] = array(
    1 => '1',
  );

  /* Display: Site inventory */
  $handler = $view->new_display('page', 'Site inventory', 'page_sites');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create site';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'title_3' => 'title_3',
    'created' => 'created',
    'title_2' => 'title_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created. <a href="/node/add/site">Click here</a> to add one.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['path'] = 'hosting/inventory/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Inventory';
  $handler->display->display_options['menu']['description'] = 'NDI site inventory';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Inventory';
  $handler->display->display_options['tab_options']['description'] = 'Site inventory';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'hosting/ndi/inventory/csv';
  $handler->display->display_options['displays'] = array(
    'page_sites' => 'page_sites',
    'default' => 0,
  );
  $export['ndi_site_inventory'] = $view;

  $view = new view();
  $view->name = 'ndi_site_inventory_exclusions';
  $view->description = 'Display a list of sites hosted in Aegir.';
  $view->tag = 'hosting_site';
  $view->base_table = 'node';
  $view->human_name = 'NDI Site Inventory exclusions';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Site inventory exclusions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'status' => 'status',
    'title' => 'title',
    'title_3' => 'title_3',
    'created' => 'created',
    'title_2' => 'title_2',
    'verified' => 'verified',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'verified' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Relationship: Hosting Site: Install Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Relationship: Hosting Site: Platform */
  $handler->display->display_options['relationships']['platform']['id'] = 'platform';
  $handler->display->display_options['relationships']['platform']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['platform']['field'] = 'platform';
  /* Relationship: Content: Country (field_client_country) */
  $handler->display->display_options['relationships']['field_client_country_iso2']['id'] = 'field_client_country_iso2';
  $handler->display->display_options['relationships']['field_client_country_iso2']['table'] = 'field_data_field_client_country';
  $handler->display->display_options['relationships']['field_client_country_iso2']['field'] = 'field_client_country_iso2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/node/[nid]/inventory';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Inventory enabled (field_inventory_enabled) */
  $handler->display->display_options['filters']['field_inventory_enabled_value']['id'] = 'field_inventory_enabled_value';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['table'] = 'field_data_field_inventory_enabled';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['field'] = 'field_inventory_enabled_value';
  $handler->display->display_options['filters']['field_inventory_enabled_value']['value'] = array(
    1 => '1',
  );

  /* Display: Site inventory */
  $handler = $view->new_display('page', 'Site inventory', 'page_sites');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create site';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'title_3' => 'title_3',
    'created' => 'created',
    'title_2' => 'title_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created. <a href="/node/add/site">Click here</a> to add one.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['path'] = 'hosting/inventory/exclusions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Exclusions';
  $handler->display->display_options['menu']['description'] = 'NDI site inventory exclusions';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['ndi_site_inventory_exclusions'] = $view;

  return $export;
}
