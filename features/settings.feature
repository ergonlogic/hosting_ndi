@api
Feature: NDI inventory settings appear on a separate page.
  In order to determine which data are exposed to the site inventory
  as an Aegir administrator,
  I want to be able to set which fields appear in the NDI tab.

  Background:
    Given I am logged in as a "aegir administrator"
      And I am on "admin/hosting/ndi"

  Scenario: The NDI inventory settings page is only accessible by authorized roles.
    # TODO: This is currently too permissive, and just checks the "access
    # content" permission.
     Then I should get a 200 HTTP response

  Scenario Outline: The inventory fields visibility can be controlled individually.
     Then the "div[class='form-item form-type-checkbox form-item-ndi-inventory-fields-field-<CLASS>']" element should contain "<LABEL> (<FIELD>)"
    Given I uncheck the box "<LABEL>"
      And I press "Save configuration"
      And I am on "hosting/c/hostmaster"
     When I click "NDI"
     Then I should not see a "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element
     When I click "Edit"
     Then I should see a "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element
      And the "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element should contain "<LABEL>"
    Given I am on "admin/hosting/ndi"
      And I check the box "<LABEL>"
      And I press "Save configuration"
      And I am on "hosting/c/hostmaster"
     When I click "NDI"
     Then I should see a "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element
      And the "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element should contain "<LABEL>"
     When I click "Edit"
     Then I should not see a "div[class='form-item form-type-<TYPE> form-item-field-<CLASS>-und']" element
    Examples:
      | LABEL             | FIELD                   | CLASS             | TYPE     |
      | Inventory enabled | field_inventory_enabled | inventory-enabled | checkbox |
      | Environment       | field_ndi_environment   | ndi-environment   | select   |

