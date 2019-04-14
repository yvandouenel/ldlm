<?php

/**
 * @file
 * Affichage des résultats (moyenne ou écart type).
 *
 * Variables disponibles :
 * - $value : valeur à afficher,
 * - $quality : chaîne de caractère indiquant dans quel intervalle se trouve
 * la valeur ('good', 'normal', 'bad').
 */
?>

<span class="survey-value <?php print $quality; ?>"><?php print $value; ?></span>
