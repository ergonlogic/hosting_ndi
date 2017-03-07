<?php

class EnableMetricsClientProbe extends EnableNdiMetricsProbe {

  protected $name = 'enable_metrics_client';

  protected $label = 'Metrics client extension';

  protected $description = 'Metrics client extension enabled';

  protected $probe = 'if (!module_exists("civicrm")) { drush_print("N/A"); return; } civicrm_initialize(); $return = "missing"; $exts = civicrm_api3("Extension", "get"); foreach ($exts["values"] as $ext) { if ($ext["key"] == "com.ginkgostreet.metricclient") { $return = $ext["status"];}} drush_print($return);';

}
