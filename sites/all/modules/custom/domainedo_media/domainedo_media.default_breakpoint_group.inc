<?php
/**
 * @file
 * domainedo_media.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function domainedo_media_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.domainedo.mobile';
  $breakpoints[] = 'breakpoints.theme.domainedo.narrow';
  $breakpoints[] = 'breakpoints.theme.domainedo.wide';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'max';
  $breakpoint_group->name = 'max';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['max'] = $breakpoint_group;

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.domainedo.mobile';
  $breakpoints[] = 'breakpoints.theme.domainedo.narrow';
  $breakpoints[] = 'breakpoints.theme.domainedo.wide';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'zoom';
  $breakpoint_group->name = 'zoom';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['zoom'] = $breakpoint_group;

  return $export;
}
