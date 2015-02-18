<?php
/**
 * @file
 * domainedo_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function domainedo_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_actions_powers';
  $strongarm->value = array(
    'fetch' => 0,
    'edit' => 1,
    'view' => 2,
    'delete' => 3,
  );
  $export['scald_actions_powers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_author_vocabulary';
  $strongarm->value = 'scald_authors';
  $export['scald_author_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_context_fallbacks';
  $strongarm->value = array(
    '@default' => array(
      0 => 'title',
    ),
  );
  $export['scald_context_fallbacks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scald_tags_vocabulary';
  $strongarm->value = 'scald_tags';
  $export['scald_tags_vocabulary'] = $strongarm;

  return $export;
}
