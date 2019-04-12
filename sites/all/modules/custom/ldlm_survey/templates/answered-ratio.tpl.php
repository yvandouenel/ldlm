<?php

/**
 * @file
 * Taux de réponse à une campagne.
 *
 * Variables disponibles :
 * - $answers : nombre de réponses,
 * - $total : nombre de participants,
 * - $percent : pourcentage de réponses.
 */
?>

<?php if ($total == 0): ?>
  <?php print t('N/A'); ?>
<?php else: ?>
  <?php print $answers; ?>/<?php print $total; ?> (<?php print $percent; ?> %)
<?php endif; ?>
