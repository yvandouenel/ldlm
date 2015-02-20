<?php
/**
 * @file
 * news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_all_home_zoom|node|news|zoom';
  $field_group->group_name = 'group_all_home_zoom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'zoom';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'groupe_all',
    'weight' => '24',
    'children' => array(
      0 => 'body',
      1 => 'field_scald_image',
      2 => 'field_images',
      3 => 'over_zoom_small',
      4 => 'zoom_sur',
      5 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'groupe_all',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-all-home-zoom field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_all_home_zoom|node|news|zoom'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_summa_dates|node|news|zoom';
  $field_group->group_name = 'group_event_summa_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'zoom';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group event summary and dates',
    'weight' => '10',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group event summary and dates',
      'instance_settings' => array(
        'classes' => 'group-event-summa-dates field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_event_summa_dates|node|news|zoom'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_img|node|news|teaser';
  $field_group->group_name = 'group_title_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'groupe titre et image',
    'weight' => '0',
    'children' => array(
      0 => 'field_scald_image',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'groupe titre et image',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-title-img field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_title_img|node|news|teaser'] = $field_group;

  return $export;
}
