<?php
/**
 * @file
 * ldlm_survey.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ldlm_survey_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enquetes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ldlm_campaign';
  $view->human_name = 'Enquêtes de satisfaction';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Enquêtes de satisfaction';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer surveys';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'status' => 'status',
    'begin' => 'begin',
    'end' => 'end',
    'created' => 'created',
    'changed' => 'changed',
    'title_1' => 'title_1',
    'field_campaign_actions' => 'field_campaign_actions',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'begin' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'end' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_campaign_actions' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'Aucune campagne ne correspond à ces critères.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Enquête de satisfaction: Groupe de campagnes associé */
  $handler->display->display_options['relationships']['cgid']['id'] = 'cgid';
  $handler->display->display_options['relationships']['cgid']['table'] = 'ldlm_campaign';
  $handler->display->display_options['relationships']['cgid']['field'] = 'cgid';
  /* Champ: Enquête de satisfaction: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Titre';
  /* Champ: Enquête de satisfaction: État de la campagne */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'État';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Champ: Enquête de satisfaction: Date d'ouverture */
  $handler->display->display_options['fields']['begin']['id'] = 'begin';
  $handler->display->display_options['fields']['begin']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['begin']['field'] = 'begin';
  $handler->display->display_options['fields']['begin']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['begin']['date_format'] = 'custom';
  $handler->display->display_options['fields']['begin']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['begin']['second_date_format'] = 'long';
  /* Champ: Enquête de satisfaction: Date de fermeture */
  $handler->display->display_options['fields']['end']['id'] = 'end';
  $handler->display->display_options['fields']['end']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['end']['field'] = 'end';
  $handler->display->display_options['fields']['end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['end']['date_format'] = 'custom';
  $handler->display->display_options['fields']['end']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['end']['second_date_format'] = 'long';
  /* Champ: Enquête de satisfaction: Date de création */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Champ: Enquête de satisfaction: Date de modification */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'ldlm_campaign';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Champ: Groupe de campagnes de satisfaction.: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'ldlm_campaign_group';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'cgid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Groupe de campagnes';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Champ: Global: Liens d'administration des campagnes */
  $handler->display->display_options['fields']['field_campaign_actions']['id'] = 'field_campaign_actions';
  $handler->display->display_options['fields']['field_campaign_actions']['table'] = 'views';
  $handler->display->display_options['fields']['field_campaign_actions']['field'] = 'field_campaign_actions';
  $handler->display->display_options['fields']['field_campaign_actions']['label'] = 'Opérations';
  $handler->display->display_options['fields']['field_campaign_actions']['element_label_colon'] = FALSE;
  /* Filter criterion: Enquête de satisfaction: État de la campagne */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'ldlm_campaign';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'État de la campagne';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    8 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/survey/campaign';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Enquêtes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['enquetes'] = array(
    t('Master'),
    t('Enquêtes de satisfaction'),
    t('more'),
    t('Apply'),
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
    t('Aucune campagne ne correspond à ces critères.'),
    t('Groupe de campagnes de satisfaction.'),
    t('Titre'),
    t('État'),
    t('Date d\'ouverture'),
    t('Date de fermeture'),
    t('Date de création'),
    t('Date de modification'),
    t('Groupe de campagnes'),
    t('Opérations'),
    t('État de la campagne'),
    t('Page'),
  );
  $export['enquetes'] = $view;

  $view = new view();
  $view->name = 'questionnaires';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ldlm_survey';
  $view->human_name = 'Questionnaires';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questionnaires';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer surveys';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
  $handler->display->display_options['empty']['area']['content'] = 'Aucun questionnaire n\'a été créé.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Champ: Questionnaire: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ldlm_survey';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Titre';
  /* Champ: Questionnaire: Date de création */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ldlm_survey';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Champ: Questionnaire: Date de modification */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'ldlm_survey';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Champ: Global: Liens d'administration des questionnaires */
  $handler->display->display_options['fields']['field_survey_actions']['id'] = 'field_survey_actions';
  $handler->display->display_options['fields']['field_survey_actions']['table'] = 'views';
  $handler->display->display_options['fields']['field_survey_actions']['field'] = 'field_survey_actions';
  $handler->display->display_options['fields']['field_survey_actions']['label'] = 'Opérations';
  $handler->display->display_options['fields']['field_survey_actions']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/survey/survey';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Questionnaires';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['questionnaires'] = array(
    t('Master'),
    t('Questionnaires'),
    t('more'),
    t('Apply'),
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
    t('Aucun questionnaire n\'a été créé.'),
    t('Titre'),
    t('Date de création'),
    t('Date de modification'),
    t('Opérations'),
    t('Page'),
  );
  $export['questionnaires'] = $view;

  return $export;
}
