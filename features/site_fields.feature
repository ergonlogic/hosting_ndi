@api
Feature: NDI inventory fields appear on a separate tab.
  In order to provide data for a consolidated site inventory
  as an Aegir administrator,
  I want to be able to record extra data about sites.

  Background:
    Given I am logged in as a "aegir administrator" 
      And I am on "hosting/c/hostmaster"
     When I click "NDI"

  Scenario: The NDI inventory tab is only accessible by authorized roles.
    # TODO: This is currently too permissive, and just checks the "access
    # content" permission.
     Then the url should match "/node/[0-9]*/ndi"

  Scenario: The inventory fields appear on the "NDI" tab.
     Then the "div[class='form-item form-type-checkbox form-item-field-inventory-enabled-und']" element should contain "Inventory enabled"
      And the "div[class='form-item form-type-select form-item-field-ndi-environment-und']" element should contain "Environment"

  Scenario: Save some data to our custom fields.
    Given I check the box "Inventory enabled"
      And I select "Testing/QA" from "Environment"
     When I press "Save"
     Then the checkbox "Inventory enabled" should be checked
      And the "Environment" field should contain "Testing/QA"


