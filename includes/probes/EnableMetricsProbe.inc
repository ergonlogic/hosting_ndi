<?php

class EnableMetricsProbe extends SiteReportProbe {

  protected $name = 'enable_metrics';

  protected $label = 'Metrics extension enabled';

  protected $description = 'Metrics extension enabled';

  protected $probe = 'if (!module_exists("civicrm")) {drush_print("N/A"); return; } civicrm_initialize();$ext = civicrm_api3("Extension", "get", ["key" => "org.ndi.metrics"]); if ($ext["count"] == 1) {drush_print($ext["values"][$ext["id"]]["status"]);} else {drush_print("missing");}';

  protected $sections = array('DemTools');

  protected $analysis = [
    'uninstalled' => [
      '#message' => "Not installed",
      '#status' => RESULT_STATUS_WARNING,
    ],
    'installed' => [
      '#message' => "Installed",
      '#status' => RESULT_STATUS_OK,
    ],
    'missing' => [
      '#message' => "Extension missing",
      '#status' => RESULT_STATUS_WARNING,
    ],
    'N/A' => [
      '#message' => "Metrics extension missing",
      '#status' => RESULT_STATUS_INFO,
    ],
  ];

  /**
   * Callback to format a Drush PHP function call probe.
   *
   * @TODO: This overrides the DrushEvalCommand trait. That trait should use
   * this implementation instead, since it allows for the use of variables in
   * probe code. However, any probes currently using it will have to be
   * adapted.
   */
  function getCommand($alias) {
    return drush_find_drush() . ' ' . $alias . " php-eval '" . $this->probe . "'";
  }

}
