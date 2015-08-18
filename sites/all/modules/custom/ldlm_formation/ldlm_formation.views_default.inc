<?php
/**
 * @file
 * ldlm_formation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ldlm_formation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'formations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Formations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Formations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formations continues</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'formations:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'formation' => 'formation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Block supérieures */
  $handler = $view->new_display('block', 'Block supérieures', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Formations supérieures';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formations supérieures</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Niveau (field_niveau) */
  $handler->display->display_options['filters']['field_niveau_tid']['id'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['table'] = 'field_data_field_niveau';
  $handler->display->display_options['filters']['field_niveau_tid']['field'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['value'] = array(
    24 => '24',
  );
  $handler->display->display_options['filters']['field_niveau_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_niveau_tid']['vocabulary'] = 'niveau_de_formation';
  $handler->display->display_options['block_description'] = 'Formations supérieures';

  /* Display: Block initiales */
  $handler = $view->new_display('block', 'Block initiales', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Formations initiales';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formations initiales</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Niveau (field_niveau) */
  $handler->display->display_options['filters']['field_niveau_tid']['id'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['table'] = 'field_data_field_niveau';
  $handler->display->display_options['filters']['field_niveau_tid']['field'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['value'] = array(
    27 => '27',
  );
  $handler->display->display_options['filters']['field_niveau_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_niveau_tid']['vocabulary'] = 'niveau_de_formation';
  $handler->display->display_options['block_description'] = 'Formations initiales';

  /* Display: Classement formations */
  $handler = $view->new_display('page', 'Classement formations', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Draggableviews: Contenu */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Sort criterion: Contenu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'formations-classement';

  /* Display: Block intermédiaires */
  $handler = $view->new_display('block', 'Block intermédiaires', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Certifications intermédiaires';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Certifications intermédiaires</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Niveau (field_niveau) */
  $handler->display->display_options['filters']['field_niveau_tid']['id'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['table'] = 'field_data_field_niveau';
  $handler->display->display_options['filters']['field_niveau_tid']['field'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['value'] = array(
    25 => '25',
  );
  $handler->display->display_options['filters']['field_niveau_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_niveau_tid']['vocabulary'] = 'niveau_de_formation';
  $handler->display->display_options['block_description'] = 'Certifications intermédiaires';

  /* Display: Block Apprentissage */
  $handler = $view->new_display('block', 'Block Apprentissage', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apprentissage';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Apprentissage</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Niveau (field_niveau) */
  $handler->display->display_options['filters']['field_niveau_tid']['id'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['table'] = 'field_data_field_niveau';
  $handler->display->display_options['filters']['field_niveau_tid']['field'] = 'field_niveau_tid';
  $handler->display->display_options['filters']['field_niveau_tid']['value'] = array(
    26 => '26',
  );
  $handler->display->display_options['filters']['field_niveau_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_niveau_tid']['vocabulary'] = 'niveau_de_formation';
  $handler->display->display_options['block_description'] = 'Apprentissage';

  /* Display: Block Pro */
  $handler = $view->new_display('block', 'Block Pro', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Formations continues';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Pro (field_pro) */
  $handler->display->display_options['filters']['field_pro_value']['id'] = 'field_pro_value';
  $handler->display->display_options['filters']['field_pro_value']['table'] = 'field_data_field_pro';
  $handler->display->display_options['filters']['field_pro_value']['field'] = 'field_pro_value';
  $handler->display->display_options['filters']['field_pro_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Formations continues';

  /* Display: Page sommaire */
  $handler = $view->new_display('page', 'Page sommaire', 'page_index_formation');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formation initiale</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Type de formation (field_type_formation) */
  $handler->display->display_options['filters']['field_type_formation_tid']['id'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['table'] = 'field_data_field_type_formation';
  $handler->display->display_options['filters']['field_type_formation_tid']['field'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['field_type_formation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_formation_tid']['vocabulary'] = 'types_de_formation';
  $handler->display->display_options['path'] = 'index-formations';

  /* Display: Attachement continue */
  $handler = $view->new_display('attachment', 'Attachement continue', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formation continue</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Type de formation (field_type_formation) */
  $handler->display->display_options['filters']['field_type_formation_tid']['id'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['table'] = 'field_data_field_type_formation';
  $handler->display->display_options['filters']['field_type_formation_tid']['field'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['field_type_formation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_formation_tid']['vocabulary'] = 'types_de_formation';
  $handler->display->display_options['displays'] = array(
    'page_index_formation' => 'page_index_formation',
    'default' => 0,
    'block' => 0,
    'block_3' => 0,
    'block_2' => 0,
    'page_1' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachement apprentissage */
  $handler = $view->new_display('attachment', 'Attachement apprentissage', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="h3-formation-home">Formation par apprentissage</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'formation' => 'formation',
  );
  /* Filter criterion: Contenu: Type de formation (field_type_formation) */
  $handler->display->display_options['filters']['field_type_formation_tid']['id'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['table'] = 'field_data_field_type_formation';
  $handler->display->display_options['filters']['field_type_formation_tid']['field'] = 'field_type_formation_tid';
  $handler->display->display_options['filters']['field_type_formation_tid']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['filters']['field_type_formation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_formation_tid']['vocabulary'] = 'types_de_formation';
  $handler->display->display_options['displays'] = array(
    'page_index_formation' => 'page_index_formation',
    'default' => 0,
    'block' => 0,
    'block_3' => 0,
    'block_2' => 0,
    'page_1' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['formations'] = array(
    t('Master'),
    t('Formations'),
    t('more'),
    t('Apply'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h3 class="h3-formation-home">Formations continues</h3>'),
    t('Block'),
    t('Block supérieures'),
    t('Formations supérieures'),
    t('<h3 class="h3-formation-home">Formations supérieures</h3>'),
    t('Block initiales'),
    t('Formations initiales'),
    t('<h3 class="h3-formation-home">Formations initiales</h3>'),
    t('Classement formations'),
    t('Block intermédiaires'),
    t('Certifications intermédiaires'),
    t('<h3 class="h3-formation-home">Certifications intermédiaires</h3>'),
    t('Block Apprentissage'),
    t('Apprentissage'),
    t('<h3 class="h3-formation-home">Apprentissage</h3>'),
    t('Block Pro'),
    t('Formations continues'),
    t('Page sommaire'),
    t('<h3 class="h3-formation-home">Formation initiale</h3>'),
    t('Attachement continue'),
    t('<h3 class="h3-formation-home">Formation continue</h3>'),
    t('Attachement apprentissage'),
    t('<h3 class="h3-formation-home">Formation par apprentissage</h3>'),
  );
  $export['formations'] = $view;

  return $export;
}
