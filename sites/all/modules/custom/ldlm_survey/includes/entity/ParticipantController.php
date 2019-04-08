<?php

/**
 * Participant controller.
 */
class ParticipantController extends LdlmSurveyController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = []) {
    $key = drupal_get_hash_salt();
    $hash_helper = 0;

    do {
      $data = microtime(TRUE) . $hash_helper;
      $hash = drupal_hmac_base64($data, $key);

      // S'assurer que le condensat est unique.
      $result = db_select('ldlm_participant', 'p')
        ->fields('p', ['hash'])
        ->condition('hash', $hash)
        ->execute()
        ->rowCount();

      // Incrémenter au cas où le condensat existait déjà et une nouvelle
      // itération est nécessaire.
      $hash_helper++;
    } while ($result != 0);

    $values += ['hash' => $hash];

    return parent::create($values);
  }

}
