<?php

/**
 * Implementation of hook_hosting_site_context_options().
 */
function hosting_ndi_hosting_site_context_options(&$task) {
  if (isset($task->ref->ndi_civi_ext) && !empty($task->ref->ndi_civi_ext)) {
    $task->context_options['ndi_civi_ext'] = $task->ref->ndi_civi_ext;
  }
  else {
    $task->context_options['ndi_civi_ext'] = 'null';
  }
}

/**
 * Implementation of hook_drush_context_import().
 */
function hosting_ndi_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->ndi_civi_ext) && !empty($context->ndi_civi_ext)) {
      $node->ndi_civi_ext = $context->ndi_civi_ext;
    }
  }
}
