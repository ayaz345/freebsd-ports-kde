--- chrome/browser/prefs/browser_prefs.cc.orig	2023-04-08 11:38:38 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -455,13 +455,13 @@
 #include "components/os_crypt/os_crypt.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -494,7 +494,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -787,7 +787,7 @@ const char kPluginsPluginsList[] = "plugins.plugins_li
 const char kPluginsShowDetails[] = "plugins.show_details";
 
 // Deprecated 02/2023.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kWebAppsUrlHandlerInfo[] = "web_apps.url_handler_info";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -869,7 +869,7 @@ void RegisterLocalStatePrefsForMigration(PrefRegistryS
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
   // Deprecated 02/2023.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterDictionaryPref(kWebAppsUrlHandlerInfo);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
@@ -982,7 +982,7 @@ void RegisterProfilePrefsForMigration(
   registry->RegisterIntegerPref(kProfileAvatarTutorialShown, 0);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deprecated 08/2022.
   registry->RegisterBooleanPref(prefs::kUsesSystemThemeDeprecated, false);
 #endif
@@ -1616,11 +1616,11 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
   safe_browsing::PostCleanupSettingsResetter::RegisterProfilePrefs(registry);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
 #endif
 
@@ -1817,7 +1817,7 @@ void MigrateObsoleteLocalStatePrefs(PrefService* local
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
   // Added 02/2023
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state->ClearPref(kWebAppsUrlHandlerInfo);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1962,7 +1962,7 @@ void MigrateObsoleteProfilePrefs(Profile* profile) {
   profile_prefs->ClearPref(kProfileAvatarTutorialShown);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Added 08/2022.
   if (profile_prefs->HasPrefPath(prefs::kUsesSystemThemeDeprecated)) {
     auto migrated_theme =
