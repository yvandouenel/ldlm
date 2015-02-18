<?php
/**
 * @file
 * news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'evenements';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evénements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evénements au domaine d\'O';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Field: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'list';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Filter criterion: Contenu: Published */
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution - date de dÃ©but (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_news_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Contenu: Date de parution - date de fin (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['default_date'] = 'now';

  /* Display: Page-evenement */
  $handler = $view->new_display('page', 'Page-evenement', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Field: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'list';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'evenements:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['path'] = 'evenements';

  /* Display: Block Flash Info */
  $handler = $view->new_display('block', 'Block Flash Info', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Info Flash';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'Tous les événements';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<p class="all_home_events"><a href="evenements">Tous les événements</a></p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="title-flash-info">[title]</h2>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'evenements:page_2';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Contenu: Published */
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Promu en page d&#039;accueil (field_promoted) */
  $handler->display->display_options['filters']['field_promoted_value']['id'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['table'] = 'field_data_field_promoted';
  $handler->display->display_options['filters']['field_promoted_value']['field'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Contenu: Date de parution - date de dÃ©but (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_news_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Contenu: Date de parution - date de fin (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['default_date'] = 'now';

  /* Display: Page-evenement-draggable */
  $handler = $view->new_display('page', 'Page-evenement-draggable', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Classement des événements';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_news_url_target' => 'field_news_url_target',
    'field_new_window' => 'field_new_window',
    'field_scald_image' => 'field_scald_image',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_news_url_target' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_new_window' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scald_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Field: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'list';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Draggableviews: Contenu */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Enregistrer l\'ordre';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['path'] = 'admin/settings/sort-events';

  /* Display: Page-Flash-draggable */
  $handler = $view->new_display('page', 'Page-Flash-draggable', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'FLASH INFO';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Draggableviews: Contenu */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Enregistrer l\'ordre';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Contenu: Published */
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Promu en page d&#039;accueil (field_promoted) */
  $handler->display->display_options['filters']['field_promoted_value']['id'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['table'] = 'field_data_field_promoted';
  $handler->display->display_options['filters']['field_promoted_value']['field'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/settings/sort-flash';

  /* Display: Block home events */
  $handler = $view->new_display('block', 'Block home events', 'block_2');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les événements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="h2-event" id="h2-event-home"><a href="evenements">Autres événements</a></h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Field: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'event_home';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Field: Contenu: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Contenu: Published */
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution - date de dÃ©but (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_news_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Contenu: Date de parution - date de fin (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['default_date'] = 'now';
  /* Filter criterion: Contenu: Visible bas accueil (field_visible_bas_accueil) */
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['id'] = 'field_visible_bas_accueil_value';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['table'] = 'field_data_field_visible_bas_accueil';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['field'] = 'field_visible_bas_accueil_value';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'block home events';
  $translatables['evenements'] = array(
    t('Master'),
    t('Evénements au domaine d\'O'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Page-evenement'),
    t('Block Flash Info'),
    t('Info Flash'),
    t('Tous les événements'),
    t('<p class="all_home_events"><a href="evenements">Tous les événements</a></p>'),
    t('<h2 class="title-flash-info">[title]</h2>'),
    t('Page-evenement-draggable'),
    t('Classement des événements'),
    t('Page-Flash-draggable'),
    t('FLASH INFO'),
    t('Contenu'),
    t('Block home events'),
    t('Voir tous les événements'),
    t('<h2 class="h2-event" id="h2-event-home"><a href="evenements">Autres événements</a></h2>'),
    t('block home events'),
  );
  $export['evenements'] = $view;

  return $export;
}
