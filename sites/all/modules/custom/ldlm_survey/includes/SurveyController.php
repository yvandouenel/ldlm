<?php

/**
 * Survey controller.
 */
class SurveyController extends LdlmSurveyController {

  /**
   * {@inheritdoc}
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    // Supprimer les groupes de question liés avant de supprimer le formulaire
    // d'enquête.
    foreach ($this->load($ids) as $survey) {
      foreach ($survey->getQuestionGroups() as $question_group) {
        $question_group->delete();
      }
    }

    parent::delete($ids, $transaction);
  }

  /**
   * Get all question groups for this survey.
   */
  public function getQuestionGroups($survey) {
    $question_groups = [];

    if (isset($survey->sid)) {
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'question_group')
        ->propertyCondition('sid', $survey->sid)
        ->execute();

      if (!empty($result['question_group'])) {
        $qgids = array_keys($result['question_group']);
        $question_groups = entity_load('question_group', $qgids);
      }
    }

    return $question_groups;
  }

}
