@api
Feature: NDI inventory view and associated menu item
  In order to gain insights about hosted sites
  as an Aegir administrator,
  I want to be able to view the site inventory.

  Background:
    Given I am logged in as a "aegir administrator" 

  Scenario: The inventory menu item is only accessible by authorized roles.
    # TODO: This is currently too permissive, and just checks the "access
    # content" permission.
    Given I am on the homepage
     Then I should see the link "Inventory" in the "navigation" region
     When I click "Inventory" in the "navigation" region
     Then I should be on "hosting/ndi/inventory"

