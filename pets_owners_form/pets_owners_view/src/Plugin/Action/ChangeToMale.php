<?php

namespace Drupal\pets_owners_view\Plugin\Action;

use Drupal\Core\Action\ActionBase;
use Drupal\Core\Session\AccountInterface;

use Drupal\views_bulk_operations\Action\ViewsBulkOperationsActionBase;
use Drupal\Core\StringTranslation\StringTranslationTrait;

/**
* Push term in front.
*
* @Action(
*   id = "change_to_male",
*   label = @Translation("Change selected pets owners gender to male"),
*   type = "",
*   confirm = TRUE,
* )
*/
class ChangeToMale extends ActionBase {

  /**
   * {@inheritdoc}
   */
  public function execute($entity = NULL) {
    /** @var \Drupal\taxonomy\TermInterface $entity */
    if ($entity->hasField('field_push')) {
      $entity->field_push->value = 1;
      $entity->save();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function access($object, AccountInterface $account = NULL, $return_as_object = FALSE) {
    /** @var \Drupal\taxonomy\TermInterface $object */
    $result = $object->access('update', $account, TRUE)
      ->andIf($object->field_push->access('edit', $account, TRUE));

    return $return_as_object ? $result : $result->isAllowed();
  }

}
