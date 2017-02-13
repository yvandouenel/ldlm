<?php
/**
 * @file
 *   Default theme implementation for Scald File Render.
 */
?>
<img src="/sites/all/modules/contrib/scald_file/icons/application_pdf.png" class="scald-file-icon" alt="file type icon">
<a href="<?php print file_create_url($vars['file_source']); ?>" title="<?php print $vars['file_title']; ?>">
  <?php print $vars['file_title']; ?>
</a>
