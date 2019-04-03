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
    t('Titre'),
    t('Date de création'),
    t('Date de modification'),
    t('Opérations'),
    t('Page'),
  );
  $export['questionnaires'] = $view;

  return $export;
}
