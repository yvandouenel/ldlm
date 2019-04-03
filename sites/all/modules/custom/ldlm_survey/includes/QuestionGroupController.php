<?php

/**
 * Question group controller.
 */
class QuestionGroupController extends LdlmSurveyController {

  /**
   * {@inheritdoc}
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Supprimer les questions liées avant de supprimer le groupe de questions.
    foreach ($this->load($ids) as $question_group) {
      foreach ($question_group->getQuestions() as $question) {
        $question->delete();
      }
    }

    parent::delete($ids, $transaction);
  }

  /**
   * Get all questions for this question group.
   */
  public function getQuestions($question_group) {
    $questions = [];

    if (isset($question_group->qgid)) {
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'question')
        ->propertyCondition('qgid', $question_group->qgid)
        ->execute();

      if (!empty($result['question'])) {
        $qids = array_keys($result['question']);
        $questions = entity_load('question', $qids);
      }
    }

    return $questions;
  }

}
