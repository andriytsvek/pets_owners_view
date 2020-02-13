<?php

use Drupal\views\ViewExecutable;
use Drupal\pets_owners_storage\Controller\ShowOwners;

/**
 * Implements hook_views_data().
 */

function pets_owners_view_views_data() {
  $data = [];
  // Base data.
  $data['pets_owners_storage']['table']['group'] = t('Pets Owners');
  $data['pets_owners_storage']['table']['base'] = [
    'title' => t('Pets Owners'),
    'help' => t('Pets Owners storage'),
    //'query_id' => 'pets_owners_storage',
    'field' => 'id'
  ];

  // Fields.
  $data['pets_owners_storage']['id'] = [
    'title' => t('ID'),
    'help' => t('Pet owner id'),
    'field' => [
      'id' => 'numeric',
    ],
  ];
  $data['pets_owners_storage']['name'] = [
    'title' => t('Name'),
    'help' => t('Pet owner name'),
    'field' => [
      'id' => 'standard',
    ],
  ];
  $data['pets_owners_storage']['gender'] = [
    'title' => t('Gender'),
    'help' => t('Gender of the pet owner (male, female, unknown).'),
    'field' => [
      'id' => 'standard',
    ],
  ];
  $data['pets_owners_storage']['prefix'] = [
    'title' => t('Prefix'),
    'help' => t('Honorifics of the pet owner.'),
    'field' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'prefix_filter',
      'prefix_column' => 'prefix',
    ],
  ];
  $data['pets_owners_storage']['age'] = [
    'title' => t('Age'),
    'help' => t('Age of pet owner.'),
    'field' => [
      'id' => 'numeric',
    ],
  ];
  $data['pets_owners_storage']['father_name'] = [
    'title' => t('Father name'),
    'help' => t('The pet owner fathers name.'),
    'field' => [
      'id' => 'standard',
    ],
  ];
  $data['pets_owners_storage']['mother_name'] = [
    'title' => t('Mother name'),
    'help' => t('The pet owner mothers name.'),
    'field' => [
      'id' => 'standard',
    ],
  ];
  $data['pets_owners_storage']['pets_bool'] = [
    'title' => t('Have some pets?'),
    'help' => t('If pet owner have some pets'),
    'field' => [
      'id' => 'boolean',
    ],
  ];
  $data['pets_owners_storage']['pets_names'] = [
    'title' => t('Pets names'),
    'help' => t('Names of the pet owner pets.'),
    'field' => [
      'id' => 'standard',
    ],
  ];
  $data['pets_owners_storage']['email'] = [
    'title' => t('Email'),
    'help' => t('Email of the pet owner.'),
    'field' => [
      'id' => 'standard',
    ],
  ];

  return $data;
}

function pets_owners_view_views_pre_render(ViewExecutable $view){
  if ($view->id() == "pets_owners") {
    foreach ($view->result as $value) {
      $value->pets_owners_storage_prefix = ShowOwners::PREFIX[$value->pets_owners_storage_prefix];
      $value->pets_owners_storage_gender = ShowOwners::GENDER[$value->pets_owners_storage_gender];
    }
  }
}
