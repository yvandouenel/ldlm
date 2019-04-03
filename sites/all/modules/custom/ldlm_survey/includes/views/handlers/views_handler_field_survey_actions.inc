<?php

/**
 * Liens d'administration des questionnaires.
 */
class views_handler_field_survey_actions extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->add_additional_fields(['sid']);
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $sid = $this->view->result[$this->view->row_index]->sid;
    $links = [
      l(t('edit'), 'admin/content/survey/survey/' . $sid . '/edit'),
      l(t('delete'), 'admin/content/survey/survey/' . $sid . '/delete'),
    ];
    return [
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => [
        'class' => ['inline'],
      ],
      '#items' => $links,
    ];
  }

}
