core = 7.x
api = 2

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;      NDI  Custom Modules         ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

projects[ndi-pushbutton-profile][download][type] = "git"
projects[ndi-pushbutton-profile][download][url] = "https://github.com/nditech/demtools_civisociety_profile.git"
projects[ndi-pushbutton-profile][type] = "profile"
projects[ndi-pushbutton-profile][subdir] = "."
projects[ndi-pushbutton-profile][directory_name] = "ndi_pushbutton"

projects[ndi-pushbutton-roles][download][type] = "git"
projects[ndi-pushbutton-roles][download][url] = "git://git.koumbit.net/ndi-pushbutton-roles.git"
projects[ndi-pushbutton-roles][type] = "module"
projects[ndi-pushbutton-roles][subdir] = "custom"
projects[ndi-pushbutton-roles][directory_name] = "ndi_civi_admin_role"

projects[ndi-pushbutton-config][download][type] = "git"
projects[ndi-pushbutton-config][download][url] = "git://git.koumbit.net/ndi-pushbutton-config.git"
projects[ndi-pushbutton-config][type] = "module"
projects[ndi-pushbutton-config][subdir] = "custom"
projects[ndi-pushbutton-config][directory_name] = "ndi_civi"

;; *N.B.* Since these extensions get placed inside the CiviCRM directory, we
;; need to ensure they come *after* CiviCRM.

libraries[ndipermissions][download][type] = "git"
libraries[ndipermissions][download][url] = "https://github.com/nditech/CiviLocalPermissionsExtension.git"
libraries[ndipermissions][destination] = "modules/civicrm/extensions"

libraries[ndimisc][download][type] = "git"
libraries[ndimisc][download][url] = "https://github.com/nditech/CiviCitizenCustomizerExtension.git"
libraries[ndimisc][destination] = "modules/civicrm/extensions"
