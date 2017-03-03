<?php
/**
 * @file
 * news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_news';
  $strongarm->value = 0;
  $export['comment_anonymous_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_news';
  $strongarm->value = 1;
  $export['comment_default_mode_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_news';
  $strongarm->value = '50';
  $export['comment_default_per_page_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_news';
  $strongarm->value = 0;
  $export['comment_form_location_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_news';
  $strongarm->value = '1';
  $export['comment_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_news';
  $strongarm->value = '1';
  $export['comment_preview_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_news';
  $strongarm->value = 0;
  $export['comment_subject_field_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'zoom' => array(
        'custom_settings' => TRUE,
      ),
      'frontpage_block' => array(
        'custom_settings' => FALSE,
      ),
      'frontpage_block_mobile' => array(
        'custom_settings' => FALSE,
      ),
      'list' => array(
        'custom_settings' => FALSE,
      ),
      'date_portes_ouvertes' => array(
        'custom_settings' => TRUE,
      ),
      'vie' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '14',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '16',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'full' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'zoom' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'date_portes_ouvertes' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'vie' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_scald_atom__image';
  $strongarm->value = array(
    'view_modes' => array(
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'tv_img' => array(
        'custom_settings' => FALSE,
      ),
      'home_zoom' => array(
        'custom_settings' => FALSE,
      ),
      'formation' => array(
        'custom_settings' => FALSE,
      ),
      'small' => array(
        'custom_settings' => FALSE,
      ),
      'partner_1' => array(
        'custom_settings' => FALSE,
      ),
      'partner_2' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'en_tete_page_classique' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'atom' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_scald_atom__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_news';
  $strongarm->value = '0';
  $export['language_content_type_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news';
  $strongarm->value = array();
  $export['menu_options_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news';
  $strongarm->value = '1';
  $export['node_preview_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news';
  $strongarm->value = 0;
  $export['node_submitted_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_custom_contexts';
  $strongarm->value = array(
    'teaser' => array(
      'name' => 'teaser',
      'title' => 'teaser',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'tv_img' => array(
      'name' => 'tv_img',
      'title' => 'tv_img',
      'description' => 'Les grandes images qui sont utilisées sur la page d\'accueil',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'home_zoom' => array(
      'name' => 'home_zoom',
      'title' => 'home_zoom',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'formation' => array(
      'name' => 'formation',
      'title' => 'Formation',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'small' => array(
      'name' => 'small',
      'title' => 'small',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'partner_1' => array(
      'name' => 'partner_1',
      'title' => 'partner 1',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'partner_2' => array(
      'name' => 'partner_2',
      'title' => 'partner 2',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
    'en_tete_page_classique' => array(
      'name' => 'en_tete_page_classique',
      'title' => 'en-tete-page-classique',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    ),
  );
  $export['scald_custom_contexts'] = $strongarm;

  return $export;
}
