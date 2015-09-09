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
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
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
  /* Champ: Contenu: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';

  /* Display: Page-evenement */
  $handler = $view->new_display('page', 'Page-evenement', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actualités';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Chemin */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'teaser';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_news_url_target']['alter']['text'] = '<div class="group-title-img ">
<a href="[field_news_url_target]" target="[field_new_window]">[field_scald_image]</a>
  <h3 class="h3-event"><a href="[field_news_url_target]" target="[field_new_window]">[title]</a></h3>
</div>';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_url_target']['empty'] = '<div class="group-title-img ">
<a href="[path]">[field_scald_image] </a>
  <h3 class="h3-event"><a href="[path]">[title]</a></h3>
</div>';
  $handler->display->display_options['fields']['field_news_url_target']['hide_alter_empty'] = FALSE;
  /* Champ: Contenu: Body */
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
  /* Sort criterion: Contenu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'evenements';

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
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
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
  /* Champ: Contenu: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Champ: Draggableviews: Contenu */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['path'] = 'admin/settings/sort-events';

  /* Display: Block home events */
  $handler = $view->new_display('block', 'Block home events', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actualités ';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les événements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Pied de page: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/evenements" class="see-all-events"> >> Voir l\'historique de tous les événements</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Chemin */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['alter']['text'] = '_blank';
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_new_window']['empty'] = '_self';
  $handler->display->display_options['fields']['field_new_window']['hide_empty'] = TRUE;
  /* Champ: Contenu: Image */
  $handler->display->display_options['fields']['field_scald_image']['id'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['table'] = 'field_data_field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['field'] = 'field_scald_image';
  $handler->display->display_options['fields']['field_scald_image']['label'] = '';
  $handler->display->display_options['fields']['field_scald_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_scald_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scald_image']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_scald_image']['type'] = 'teaser';
  $handler->display->display_options['fields']['field_scald_image']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_scald_image']['delta_offset'] = '0';
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_news_url_target']['alter']['text'] = '<div class="group-title-img ">
<a href="[field_news_url_target]" target="[field_new_window]">[field_scald_image]</a>
  <h3 class="h3-event"><a href="[field_news_url_target]" target="[field_new_window]">[title]</a></h3>
</div>';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_url_target']['empty'] = '<div class="group-title-img ">
<a href="[path]">[field_scald_image] </a>
  <h3 class="h3-event"><a href="[path]">[title]</a></h3>
</div>';
  $handler->display->display_options['fields']['field_news_url_target']['hide_alter_empty'] = FALSE;
  /* Champ: Contenu: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'home-news-text';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  /* Filter criterion: Contenu: Visible bas accueil (field_visible_bas_accueil) */
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['id'] = 'field_visible_bas_accueil_value';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['table'] = 'field_data_field_visible_bas_accueil';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['field'] = 'field_visible_bas_accueil_value';
  $handler->display->display_options['filters']['field_visible_bas_accueil_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'block home events';

  /* Display: Block home zoom */
  $handler = $view->new_display('block', 'Block home zoom', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Zoom';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les événements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'zoom';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'zoom';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
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
  /* Champ: Contenu: Body */
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  /* Filter criterion: Contenu: Zoom sur (field_zoom) */
  $handler->display->display_options['filters']['field_zoom_value']['id'] = 'field_zoom_value';
  $handler->display->display_options['filters']['field_zoom_value']['table'] = 'field_data_field_zoom';
  $handler->display->display_options['filters']['field_zoom_value']['field'] = 'field_zoom_value';
  $handler->display->display_options['filters']['field_zoom_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'block home zoom';

  /* Display: Block vie formation adulte */
  $handler = $view->new_display('block', 'Block vie formation adulte', 'block_vie_adulte');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actualités ';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les événements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'vie';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'vie';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Pied de page: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/evenements" class="see-all-events">>> Voir l\'historique de tous les événements</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
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
  /* Champ: Contenu: Body */
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  /* Filter criterion: Contenu: Visible vie formation adulte  (field_visible_vie_formation_adul) */
  $handler->display->display_options['filters']['field_visible_vie_formation_adul_value']['id'] = 'field_visible_vie_formation_adul_value';
  $handler->display->display_options['filters']['field_visible_vie_formation_adul_value']['table'] = 'field_data_field_visible_vie_formation_adul';
  $handler->display->display_options['filters']['field_visible_vie_formation_adul_value']['field'] = 'field_visible_vie_formation_adul_value';
  $handler->display->display_options['filters']['field_visible_vie_formation_adul_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'block adults events';

  /* Display: Block vie lyceenne */
  $handler = $view->new_display('block', 'Block vie lyceenne', 'block_vie_lycee');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actualités ';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Voir tous les événements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'vie';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'vie';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Pied de page: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/evenements" class="see-all-events">>> Voir l\'historique de tous les événements</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Lien vers nouvelle fenêtre */
  $handler->display->display_options['fields']['field_new_window']['id'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['table'] = 'field_data_field_new_window';
  $handler->display->display_options['fields']['field_new_window']['field'] = 'field_new_window';
  $handler->display->display_options['fields']['field_new_window']['label'] = '';
  $handler->display->display_options['fields']['field_new_window']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_window']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Url de destination */
  $handler->display->display_options['fields']['field_news_url_target']['id'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['table'] = 'field_data_field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['field'] = 'field_news_url_target';
  $handler->display->display_options['fields']['field_news_url_target']['label'] = '';
  $handler->display->display_options['fields']['field_news_url_target']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
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
  /* Champ: Contenu: Body */
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'news' => 'news',
  );
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date) */
  $handler->display->display_options['filters']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['filters']['field_news_publication_date_value']['operator'] = '<';
  /* Filter criterion: Contenu: Date de parution (field_news_publication_date:value2) */
  $handler->display->display_options['filters']['field_news_publication_date_value2']['id'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['field'] = 'field_news_publication_date_value2';
  $handler->display->display_options['filters']['field_news_publication_date_value2']['operator'] = '>=';
  /* Filter criterion: Contenu: Visible vie lycéenne (field_visible_vie_lyc_enne) */
  $handler->display->display_options['filters']['field_visible_vie_lyc_enne_value']['id'] = 'field_visible_vie_lyc_enne_value';
  $handler->display->display_options['filters']['field_visible_vie_lyc_enne_value']['table'] = 'field_data_field_visible_vie_lyc_enne';
  $handler->display->display_options['filters']['field_visible_vie_lyc_enne_value']['field'] = 'field_visible_vie_lyc_enne_value';
  $handler->display->display_options['filters']['field_visible_vie_lyc_enne_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'block vie lycee';
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
    t('Actualités'),
    t('more'),
    t('<div class="group-title-img ">
<a href="[field_news_url_target]" target="[field_new_window]">[field_scald_image]</a>
  <h3 class="h3-event"><a href="[field_news_url_target]" target="[field_new_window]">[title]</a></h3>
</div>'),
    t('<div class="group-title-img ">
<a href="[path]">[field_scald_image] </a>
  <h3 class="h3-event"><a href="[path]">[title]</a></h3>
</div>'),
    t('Page-evenement-draggable'),
    t('Classement des événements'),
    t('Block home events'),
    t('Actualités '),
    t('Voir tous les événements'),
    t('<a href="/evenements" class="see-all-events"> >> Voir l\'historique de tous les événements</a>'),
    t('_blank'),
    t('_self'),
    t('block home events'),
    t('Block home zoom'),
    t('Zoom'),
    t('block home zoom'),
    t('Block vie formation adulte'),
    t('<a href="/evenements" class="see-all-events">>> Voir l\'historique de tous les événements</a>'),
    t('block adults events'),
    t('Block vie lyceenne'),
    t('block vie lycee'),
  );
  $export['evenements'] = $view;

  return $export;
}
