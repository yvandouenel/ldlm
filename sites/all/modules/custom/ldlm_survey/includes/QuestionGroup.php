<?php

/**
 * Class for question group entities.
 */
class QuestionGroup extends Entity {

  /**
   * Get all questions for this question group.
   */
  public function getQuestions() {
    return entity_get_controller($this->entityType)->getQuestions($this);
  }

}
