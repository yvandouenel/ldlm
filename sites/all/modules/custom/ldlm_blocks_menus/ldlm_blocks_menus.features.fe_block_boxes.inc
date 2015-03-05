<?php
/**
 * @file
 * ldlm_blocks_menus.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ldlm_blocks_menus_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'titre Formations accueil';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'titre_formations';
  $fe_block_boxes->body = '<h2 class="h2-formation-home">Formations</h2>
';

  $export['titre_formations'] = $fe_block_boxes;

  return $export;
}
