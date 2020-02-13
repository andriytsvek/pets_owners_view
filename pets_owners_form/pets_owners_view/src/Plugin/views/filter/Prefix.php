<?php

namespace Drupal\pets_owners_view\Plugin\views\filter;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\filter\FilterPluginBase;

/**
 * Simple filter to handle filtering Pets Owners results by gender.
 * @ViewsFilter("prefix_filter")
 */
class Prefix extends FilterPluginBase {

  /**
   * {@inheritdoc}
   */
  protected function valueForm(&$form, FormStateInterface $form_state) {
    $form['value'] = [
      '#type' => 'select',
      '#title' => $this->t('Gender select'),
      '#options' => [
        'male' => $this->t('Male'),
        'female' => $this->t('Female'),
        ],
    ];
  }

  public function query() {
    $this->ensureMyTable();
    $filter_values = [];

    if ($this->value == 'male') {
      $filter_values = ['1'];
    }
    if ($this->value == 'female') {
      $filter_values = ['2','3'];
    }

    $this->query->addWhere($this->options['group'], "$this->tableAlias.$this->realField", $filter_values, 'IN');
  }
}
