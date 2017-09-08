NDI Site Inventory
==================

To support NDI operations, we've implemented a site inventory that provides meta-data about sites, and will support aggregation across many Aegir servers (as a future enhancement).


Configuration
-------------

You can find a configuration for the site inventory by visiting `hosting >> inventory` in the admin menu (`/hosting/inventory`).

### Site inventory fields

We add a number of non-Aegir fields to site nodes, in order to capture information useful to supporting and reporting on hosted sites. We've moved these fields to a separate "Inventory" tab. You can control which fields appear on the "Inventory" tab by visiting the `hosting >> inventory` in the admin menu (`/hosting/inventory`).

The main reason behind this is, apart from ease-of-use, is that saving the site edit form will trigger a "verify" task for the site. This is a core feature of Aegir, and allows, for example, setting new URL aliases. However, the site inventory is separate from core Aegir functionality, and we _don't_ want to trigger needless tasks. By moving these fields to a separate form, we can handle the submission in a custom fashion.

### Inventory API key

This module allows the capture and reporting of sites hosted on a given Aegir server. However, our goal is to be able to aggregate this data across multiple Aegir servers. As such, a separate site will poll for CSVs generated from the site inventory, and then aggregate this data. To secure access to these CSVs, we check for a shared API key, which can be set here.

