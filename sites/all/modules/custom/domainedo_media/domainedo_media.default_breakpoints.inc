<?php
/**
 * @file
 * domainedo_media.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function domainedo_media_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.domainedo.wide';
  $breakpoint->name = 'wide';
  $breakpoint->breakpoint = '(min-width: 960px)';
  $breakpoint->source = 'domainedo';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.domainedo.wide'] = $breakpoint;

  return $export;
}
