<?php
/**
 * @file
 * feature_page_extranet.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_page_extranet_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_page_extranet';
  $strongarm->value = 0;
  $export['comment_anonymous_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_page_extranet';
  $strongarm->value = 1;
  $export['comment_default_mode_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_page_extranet';
  $strongarm->value = '50';
  $export['comment_default_per_page_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_page_extranet';
  $strongarm->value = 1;
  $export['comment_form_location_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page_extranet';
  $strongarm->value = '2';
  $export['comment_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_page_extranet';
  $strongarm->value = '1';
  $export['comment_preview_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_page_extranet';
  $strongarm->value = 1;
  $export['comment_subject_field_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_page_extranet';
  $strongarm->value = array(
    'view_own' => array(
      0 => 2,
      1 => 4,
      2 => 3,
    ),
    'view' => array(
      0 => 2,
      1 => 4,
      2 => 3,
    ),
  );
  $export['content_access_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_page_extranet';
  $strongarm->value = '0';
  $export['language_content_type_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page_extranet';
  $strongarm->value = array(
    0 => 'menu-top',
  );
  $export['menu_options_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page_extranet';
  $strongarm->value = 'menu-top:0';
  $export['menu_parent_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page_extranet';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_page_extranet';
  $strongarm->value = '1';
  $export['node_preview_page_extranet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page_extranet';
  $strongarm->value = 0;
  $export['node_submitted_page_extranet'] = $strongarm;

  return $export;
}
