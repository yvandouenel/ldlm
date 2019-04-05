<?php

/**
 * Class for survey entities.
 */
class Survey extends Entity {

  /**
   * Get all question groups for this survey.
   */
  public function getQuestionGroups() {
    return entity_get_controller($this->entityType)->getQuestionGroups($this);
  }

}
