<?php

/**
 * Add a google font
 */
function ldlm_preprocess_html(&$variables) {
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans',array('type' => 'external'));
  
  /* Ajoute une class à body si c'est une page pro */
  $node = menu_get_object();
  if ($node && isset($node->field_pro)) {
    if($node->field_pro['und'][0]['value']) $variables['classes_array'][] = 'pro';   
  }
  
}

function ldlm_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {
  
   unset($variables[$key]);
   unset($variables[$key]);
 }
}