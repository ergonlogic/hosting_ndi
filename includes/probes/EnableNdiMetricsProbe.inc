<?php

class EnableNdiMetricsProbe extends SiteReportProbe {

  protected $name = 'enable_ndi_metrics';

  protected $label = 'NDI metrics extension';

  protected $description = 'NDI metrics extension enabled';

  # TODO: This probe is duplicated for each extension. We should be able to
  # reduce duplication by adding an $extension param, and altering the
  # getCommand() method to interpolate it into the $probe.
  protected $probe = 'if (!module_exists("civicrm")) { drush_print("N/A"); return; } civicrm_initialize(); $return = "missing"; $exts = civicrm_api3("Extension", "get"); foreach ($exts["values"] as $ext) { if ($ext["key"] == "org.ndi.metrics") { $return = $ext["status"];}} drush_print($return);';

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
      '#message' => "Missing",
      '#status' => RESULT_STATUS_WARNING,
    ],
    'N/A' => [
      '#message' => "This probe is only relevant on CiviCRM sites.",
      '#status' => RESULT_STATUS_OK,
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
