<?php

/**
* Cookieless Admin Settings
*
*/
function cookieless_admin_settings_form($form, &$form_state) {
  $form['cookieless_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Full Subdomain Hostname'),
    '#default_value' => variable_get('cookieless_host', ''),
    '#size' => 64,
    '#maxlength' => 32,
    '#description' => t('The hostname including your subdomain js and css will be loaded from. Leave blank to disable. ( static.example.com )'),
    '#required' => FALSE,
  );
	
	// Clear the cache bins on submit.
  $form['#submit'][] = 'cookieless_admin_settings_form_submit';
  return system_settings_form($form);
}

// Submit callback.
/**
 * Clear out the page cache bin when the save configuration button is pressed.
 */
function cookieless_admin_settings_form_submit($form, &$form_state) {
  cache_clear_all(NULL, 'cache_page');
}