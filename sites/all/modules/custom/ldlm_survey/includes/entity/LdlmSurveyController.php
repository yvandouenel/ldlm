<?php

/**
 * Generic survey controller.
 */
class LdlmSurveyController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    return parent::save($entity, $transaction);
  }

}
