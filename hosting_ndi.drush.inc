<?php

/**
 * Implementation of hook_hosting_site_context_options().
 */
function hosting_ndi_hosting_site_context_options(&$task) {
  if (isset($task->ref->ndi) && !empty($task->ref->ndi)) {
    $task->context_options['ndi'] = $task->ref->ndi;
  }
  else {
    $task->context_options['ndi'] = 'null';
  }
}

/**
 * Implementation of hook_drush_context_import().
 */
function hosting_ndi_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->ndi) && !empty($context->ndi)) {
      $node->ndi = $context->ndi;
    }
  }

}
