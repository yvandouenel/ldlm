<?php
/**
 * @file
 * ressource_documentaire.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ressource_documentaire_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ressources_doc';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ressources doc';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ressources documentaires';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_scald_file' => 'field_scald_file',
  );
  $handler->display->display_options['style_options']['class'] = 'table-hover table-bordered';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scald_file' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Aucune ressource documentaire ne correspond à votre requête.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Titre de la ressource documentaire';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Fichiers attachés */
  $handler->display->display_options['fields']['field_scald_file']['id'] = 'field_scald_file';
  $handler->display->display_options['fields']['field_scald_file']['table'] = 'field_data_field_scald_file';
  $handler->display->display_options['fields']['field_scald_file']['field'] = 'field_scald_file';
  $handler->display->display_options['fields']['field_scald_file']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_scald_file']['type'] = 'full';
  $handler->display->display_options['fields']['field_scald_file']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_file']['group_column'] = 'sid';
  $handler->display->display_options['fields']['field_scald_file']['delta_offset'] = '0';
  /* Sort criterion: Contenu: Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenu: Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenu: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ressource_documentaire' => 'ressource_documentaire',
  );
  /* Filter criterion: Contenu: Type de document (field_type_de_document) */
  $handler->display->display_options['filters']['field_type_de_document_tid']['id'] = 'field_type_de_document_tid';
  $handler->display->display_options['filters']['field_type_de_document_tid']['table'] = 'field_data_field_type_de_document';
  $handler->display->display_options['filters']['field_type_de_document_tid']['field'] = 'field_type_de_document_tid';
  $handler->display->display_options['filters']['field_type_de_document_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_de_document_tid']['expose']['operator_id'] = 'field_type_de_document_tid_op';
  $handler->display->display_options['filters']['field_type_de_document_tid']['expose']['label'] = 'Type de document';
  $handler->display->display_options['filters']['field_type_de_document_tid']['expose']['operator'] = 'field_type_de_document_tid_op';
  $handler->display->display_options['filters']['field_type_de_document_tid']['expose']['identifier'] = 'field_type_de_document_tid';
  $handler->display->display_options['filters']['field_type_de_document_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    176168899 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_type_de_document_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_de_document_tid']['vocabulary'] = 'type_de_document';
  /* Filter criterion: Contenu: Format de document (field_format_de_document) */
  $handler->display->display_options['filters']['field_format_de_document_tid']['id'] = 'field_format_de_document_tid';
  $handler->display->display_options['filters']['field_format_de_document_tid']['table'] = 'field_data_field_format_de_document';
  $handler->display->display_options['filters']['field_format_de_document_tid']['field'] = 'field_format_de_document_tid';
  $handler->display->display_options['filters']['field_format_de_document_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_format_de_document_tid']['expose']['operator_id'] = 'field_format_de_document_tid_op';
  $handler->display->display_options['filters']['field_format_de_document_tid']['expose']['label'] = 'Format de document';
  $handler->display->display_options['filters']['field_format_de_document_tid']['expose']['operator'] = 'field_format_de_document_tid_op';
  $handler->display->display_options['filters']['field_format_de_document_tid']['expose']['identifier'] = 'field_format_de_document_tid';
  $handler->display->display_options['filters']['field_format_de_document_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    176168899 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_format_de_document_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_format_de_document_tid']['vocabulary'] = 'format_de_document';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ressources-documentaires';
  $translatables['ressources_doc'] = array(
    t('Master'),
    t('Ressources documentaires'),
    t('more'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Aucune ressource documentaire ne correspond à votre requête.'),
    t('Titre de la ressource documentaire'),
    t('Fichiers attachés'),
    t('Type de document'),
    t('Format de document'),
    t('Page'),
  );
  $export['ressources_doc'] = $view;

  return $export;
}
