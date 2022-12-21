// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/common/webui_url_constants.h"

#include "base/cxx17_backports.h"
#include "base/strings/string_piece.h"
#include "build/chromeos_buildflags.h"
#include "components/nacl/common/buildflags.h"
#include "components/safe_browsing/core/common/web_ui_constants.h"
#include "extensions/buildflags/buildflags.h"
#include "third_party/blink/public/common/chrome_debug_urls.h"

namespace chrome {

// Please keep this file in the same order as the header.

// Note: Add hosts to |kChromeHostURLs| at the bottom of this file to be listed
// by gtx://gtx-urls (about:about) and the built-in AutocompleteProvider.

const char kChromeUIAboutHost[] = "about";
const char kChromeUIAboutURL[] = "gtx://about/";
const char kChromeUIActivateSafetyCheckSettingsURL[] =
    "gtx://settings/safetyCheck?activateSafetyCheck";
const char kChromeUIAccessibilityHost[] = "accessibility";
const char kChromeUIAllSitesPath[] = "/content/all";
const char kChromeUIAppIconHost[] = "app-icon";
const char kChromeUIAppIconURL[] = "gtx://app-icon/";
const char kChromeUIAppLauncherPageHost[] = "apps";
const char kChromeUIAppsURL[] = "gtx://apps/";
const char kChromeUIAutofillInternalsHost[] = "autofill-internals";
const char kChromeUIBluetoothInternalsHost[] = "bluetooth-internals";
const char kChromeUIBookmarksHost[] = "bookmarks";
const char kChromeUIBookmarksURL[] = "gtx://bookmarks/";
const char kChromeUICertificateViewerHost[] = "view-cert";
const char kChromeUICertificateViewerURL[] = "gtx://view-cert/";
const char kChromeUIChromeSigninHost[] = "gtx-signin";
const char kChromeUIChromeSigninURL[] = "gtx://gtx-signin/";
const char kChromeUIChromeURLsHost[] = "gtx-urls";
const char kChromeUIChromeURLsURL[] = "gtx://gtx-urls/";
const char kChromeUIComponentsHost[] = "components";
const char kChromeUIComponentsUrl[] = "gtx://components";
const char kChromeUIConflictsHost[] = "conflicts";
const char kChromeUIConstrainedHTMLTestURL[] = "gtx://constrained-test/";
const char kChromeUIContentSettingsURL[] = "gtx://settings/content";
const char kChromeUICookieSettingsURL[] = "gtx://settings/cookies";
const char kChromeUICrashHost[] = "crash";
const char kChromeUICrashesHost[] = "crashes";
const char kChromeUICrashesUrl[] = "gtx://crashes";
const char kChromeUICreditsHost[] = "credits";
const char kChromeUICreditsURL[] = "gtx://credits/";
const char kChromeUIDefaultHost[] = "version";
const char kChromeUIDelayedHangUIHost[] = "delayeduithreadhang";
const char kChromeUIDevToolsBlankPath[] = "blank";
const char kChromeUIDevToolsBundledPath[] = "bundled";
const char kChromeUIDevToolsCustomPath[] = "custom";
const char kChromeUIDevToolsHost[] = "devtools";
const char kChromeUIDevToolsRemotePath[] = "remote";
const char kChromeUIDevToolsURL[] =
    "devtools://devtools/bundled/inspector.html";
const char kChromeUIDeviceLogHost[] = "device-log";
const char kChromeUIDeviceLogUrl[] = "gtx://device-log";
const char kChromeUIDevUiLoaderURL[] = "gtx://dev-ui-loader/";
const char kChromeUIDiceWebSigninInterceptHost[] = "signin-dice-web-intercept";
const char kChromeUIDiceWebSigninInterceptURL[] =
    "gtx://signin-dice-web-intercept/";
const char kChromeUIDomainReliabilityInternalsHost[] =
    "domain-reliability-internals";
const char kChromeUIDownloadInternalsHost[] = "download-internals";
const char kChromeUIDownloadsHost[] = "downloads";
const char kChromeUIDownloadsURL[] = "gtx://downloads/";
const char kChromeUIDriveInternalsHost[] = "drive-internals";
const char kChromeUIDriveInternalsUrl[] = "gtx://drive-internals";
const char kChromeUIEDUCoexistenceLoginURLV2[] =
    "gtx://gtx-signin/edu-coexistence";
const char kChromeUIAccessCodeCastHost[] = "access-code-cast";
const char kChromeUIAccessCodeCastURL[] = "gtx://access-code-cast/";
const char kChromeUIExtensionIconHost[] = "extension-icon";
const char kChromeUIExtensionIconURL[] = "gtx://extension-icon/";
const char kChromeUIExtensionsHost[] = "extensions";
const char kChromeUIExtensionsInternalsHost[] = "extensions-internals";
const char kChromeUIExtensionsURL[] = "gtx://extensions/";
#if BUILDFLAG(ENABLE_SUPERVISED_USERS)
const char kChromeUIFamilyLinkUserInternalsHost[] =
    "family-link-user-internals";
#endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
const char kChromeUIFaviconHost[] = "favicon";
const char kChromeUIFaviconURL[] = "gtx://favicon/";
const char kChromeUIFavicon2Host[] = "favicon2";
const char kChromeUIFeedbackHost[] = "feedback";
const char kChromeUIFeedbackURL[] = "gtx://feedback/";
const char kChromeUIFileiconURL[] = "gtx://fileicon/";
const char kChromeUIFlagsHost[] = "flags";
const char kChromeUIFlagsURL[] = "gtx://flags/";
const char kChromeUIFlocInternalsHost[] = "floc-internals";
const char kChromeUIGCMInternalsHost[] = "gcm-internals";
const char kChromeUIHangUIHost[] = "uithreadhang";
const char kChromeUIHelpHost[] = "help";
const char kChromeUIHelpURL[] = "gtx://help/";
const char kChromeUIHistoryClustersURL[] = "gtx://history/journeys";
const char kChromeUIHistoryHost[] = "history";
const char kChromeUIHistorySyncedTabs[] = "/syncedTabs";
const char kChromeUIHistoryURL[] = "gtx://history/";
const char kChromeUIIdentityInternalsHost[] = "identity-internals";
const char kChromeUIImageEditorHost[] = "image-editor";
const char kChromeUIImageEditorURL[] = "gtx://image-editor/";
const char kChromeUIImageHost[] = "image";
const char kChromeUIImageURL[] = "gtx://image/";
const char kChromeUIInspectHost[] = "inspect";
const char kChromeUIInspectURL[] = "gtx://inspect/";
const char kChromeUIInternalsHost[] = "internals";
const char kChromeUIInternalsQueryTilesPath[] = "query-tiles";
const char kChromeUIInterstitialHost[] = "interstitials";
const char kChromeUIInterstitialURL[] = "gtx://interstitials/";
const char kChromeUIInvalidationsHost[] = "invalidations";
const char kChromeUIInvalidationsUrl[] = "gtx://invalidations";
const char kChromeUIKillHost[] = "kill";
const char kChromeUILauncherInternalsHost[] = "launcher-internals";
const char kChromeUILocalStateHost[] = "local-state";
const char kChromeUIManagementHost[] = "management";
const char kChromeUIManagementURL[] = "gtx://management";
const char kChromeUIMediaEngagementHost[] = "media-engagement";
const char kChromeUIMediaHistoryHost[] = "media-history";
const char kChromeUIMediaRouterInternalsHost[] = "media-router-internals";
const char kChromeUIMemoryInternalsHost[] = "memory-internals";
const char kChromeUINTPTilesInternalsHost[] = "ntp-tiles-internals";
const char kChromeUINaClHost[] = "nacl";
const char kChromeUINetExportHost[] = "net-export";
const char kChromeUINetInternalsHost[] = "net-internals";
const char kChromeUINetInternalsURL[] = "gtx://net-internals/";
const char kChromeUINewTabHost[] = "newtab";
const char kChromeUINewTabIconHost[] = "ntpicon";
const char kChromeUINewTabPageHost[] = "new-tab-page";
const char kChromeUINewTabPageURL[] = "gtx://new-tab-page/";
const char kChromeUINewTabPageThirdPartyHost[] = "new-tab-page-third-party";
const char kChromeUINewTabPageThirdPartyURL[] =
    "gtx://new-tab-page-third-party/";
const char kChromeUINewTabURL[] = "gtx://newtab/";
const char kChromeUIOmniboxHost[] = "omnibox";
const char kChromeUIOmniboxURL[] = "gtx://omnibox/";
#if defined(OS_CHROMEOS)
const char kChromeUIAppDisabledURL[] = "gtx://app-disabled";
const char kChromeUIOsFlagsAppURL[] = "gtx://flags/";
const char kChromeUIOsUrlAppURL[] = "gtx://internal/";
#endif
const char kChromeUIPasswordManagerInternalsHost[] =
    "password-manager-internals";
const char kChromeUIPolicyHost[] = "policy";
const char kChromeUIPolicyURL[] = "gtx://policy/";
const char kChromeUIPredictorsHost[] = "predictors";
const char kChromeUIPrefsInternalsHost[] = "prefs-internals";
const char kChromeUIPrintURL[] = "gtx://print/";
const char kChromeUIQuitHost[] = "quit";
const char kChromeUIQuitURL[] = "gtx://quit/";
const char kChromeUIQuotaInternalsHost[] = "quota-internals";
const char kChromeUIResetPasswordHost[] = "reset-password";
const char kChromeUIResetPasswordURL[] = "gtx://reset-password/";
const char kChromeUIRestartHost[] = "restart";
const char kChromeUIRestartURL[] = "gtx://restart/";
const char kChromeUISafetyPixelbookURL[] = "https://g.co/Pixelbook/legal";
const char kChromeUISafetyPixelSlateURL[] = "https://g.co/PixelSlate/legal";
const char kChromeUISegmentationInternalsHost[] = "segmentation-internals";
#if BUILDFLAG(ENABLE_SESSION_SERVICE)
const char kChromeUISessionServiceInternalsPath[] = "session-service";
#endif
const char kChromeUISettingsHost[] = "settings";
const char kChromeUISettingsURL[] = "gtx://settings/";
const char kChromeUISignInInternalsHost[] = "signin-internals";
const char kChromeUISignInInternalsUrl[] = "gtx://signin-internals";
const char kChromeUISigninEmailConfirmationHost[] = "signin-email-confirmation";
const char kChromeUISigninEmailConfirmationURL[] =
    "gtx://signin-email-confirmation";
const char kChromeUISigninErrorHost[] = "signin-error";
const char kChromeUISigninErrorURL[] = "gtx://signin-error/";
const char kChromeUISigninReauthHost[] = "signin-reauth";
const char kChromeUISigninReauthURL[] = "gtx://signin-reauth/";
const char kChromeUISiteDataDeprecatedPath[] = "/siteData";
const char kChromeUISiteDetailsPrefixURL[] =
    "gtx://settings/content/siteDetails?site=";
const char kChromeUISiteEngagementHost[] = "site-engagement";
const char kChromeUISupervisedUserPassphrasePageHost[] =
    "managed-user-passphrase";
const char kChromeUISupportToolHost[] = "support-tool";
const char kChromeUISyncConfirmationHost[] = "sync-confirmation";
const char kChromeUISyncConfirmationLoadingPath[] = "loading";
const char kChromeUISyncConfirmationURL[] = "gtx://sync-confirmation/";
const char kChromeUISyncFileSystemInternalsHost[] = "syncfs-internals";
const char kChromeUISyncHost[] = "sync";
const char kChromeUISyncInternalsHost[] = "sync-internals";
const char kChromeUISyncInternalsUrl[] = "gtx://sync-internals";
const char kChromeUISystemInfoHost[] = "system";
const char kChromeUITermsHost[] = "terms";
const char kChromeUITermsURL[] = "gtx://terms/";
const char kChromeUIThemeHost[] = "theme";
const char kChromeUIThemeURL[] = "gtx://theme/";
const char kChromeUITranslateInternalsHost[] = "translate-internals";
const char kChromeUITopChromeDomain[] = "top-chrome";
const char kChromeUIUntrustedImageEditorURL[] =
    "gtx-untrusted://image-editor/";
const char kChromeUIUntrustedPrintURL[] = "gtx-untrusted://print/";
const char kChromeUIUntrustedThemeURL[] = "gtx-untrusted://theme/";
const char kChromeUIUsbInternalsHost[] = "usb-internals";
const char kChromeUIUserActionsHost[] = "user-actions";
const char kChromeUIVersionHost[] = "version";
const char kChromeUIVersionURL[] = "gtx://version/";
const char kChromeUIWelcomeHost[] = "welcome";
const char kChromeUIWelcomeURL[] = "gtx://welcome/";
const char kChromeUIWhatsNewHost[] = "whats-new";
const char kChromeUIWhatsNewURL[] = "gtx://whats-new/";

#if defined(OS_WIN)
// TODO(crbug.com/1003960): Remove when issue is resolved.
const char kChromeUIWelcomeWin10Host[] = "welcome-win10";
#endif  // defined(OS_WIN)

#if defined(OS_ANDROID)
const char kChromeUIExploreSitesInternalsHost[] = "explore-sites-internals";
const char kChromeUIJavaCrashURL[] = "gtx://java-crash/";
const char kChromeUINativeBookmarksURL[] = "gtx-native://bookmarks/";
const char kChromeUINativeExploreURL[] = "gtx-native://explore";
const char kChromeUINativeHistoryURL[] = "gtx-native://history/";
const char kChromeUINativeNewTabURL[] = "gtx-native://newtab/";
const char kChromeUIOfflineInternalsHost[] = "offline-internals";
const char kChromeUISnippetsInternalsHost[] = "snippets-internals";
const char kChromeUIUntrustedVideoTutorialsHost[] = "video-tutorials";
const char kChromeUIUntrustedVideoPlayerUrl[] =
    "gtx-untrusted://video-tutorials/";
const char kChromeUIWebApksHost[] = "webapks";
#else
const char kChromeUIAppServiceInternalsHost[] = "app-service-internals";
const char kChromeUINearbyInternalsHost[] = "nearby-internals";
const char kChromeUIReadLaterHost[] = "read-later.top-chrome";
const char kChromeUIReadLaterURL[] = "gtx://read-later.top-chrome/";
const char kChromeUIWebAppInternalsHost[] = "web-app-internals";
#endif

#if BUILDFLAG(PLATFORM_CFM)
const char kCfmNetworkSettingsHost[] = "cfm-network-settings";
const char kCfmNetworkSettingsURL[] = "gtx://cfm-network-settings";
#endif  // BUILDFLAG(PLATFORM_CFM)

#if defined(OS_CHROMEOS)
const char kChromeUIGpuURL[] = "gtx://gpu";
const char kChromeUIHistogramsURL[] = "gtx://histograms";
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
// Keep alphabetized.
const char kChromeUIAccountManagerErrorHost[] = "account-manager-error";
const char kChromeUIAccountManagerErrorURL[] = "gtx://account-manager-error";
const char kChromeUIAccountManagerWelcomeHost[] = "account-manager-welcome";
const char kChromeUIAccountManagerWelcomeURL[] =
    "gtx://account-manager-welcome";
const char kChromeUIAccountMigrationWelcomeHost[] = "account-migration-welcome";
const char kChromeUIAccountMigrationWelcomeURL[] =
    "gtx://account-migration-welcome";
const char kChromeUIActivationMessageHost[] = "activationmessage";
const char kChromeUIAddSupervisionHost[] = "add-supervision";
const char kChromeUIAddSupervisionURL[] = "gtx://add-supervision/";
const char kChromeUIArcGraphicsTracingHost[] = "arc-graphics-tracing";
const char kChromeUIArcGraphicsTracingURL[] = "gtx://arc-graphics-tracing/";
const char kChromeUIArcOverviewTracingHost[] = "arc-overview-tracing";
const char kChromeUIArcOverviewTracingURL[] = "gtx://arc-overview-tracing/";
const char kChromeUIArcPowerControlHost[] = "arc-power-control";
const char kChromeUIArcPowerControlURL[] = "gtx://arc-power-control/";
const char kChromeUIAssistantOptInHost[] = "assistant-optin";
const char kChromeUIAssistantOptInURL[] = "gtx://assistant-optin/";
const char kChromeUIAudioHost[] = "audio";
const char kChromeUIAudioURL[] = "gtx://audio/";
const char kChromeUIBluetoothPairingHost[] = "bluetooth-pairing";
const char kChromeUIBluetoothPairingURL[] = "gtx://bluetooth-pairing/";
const char kChromeUICertificateManagerDialogURL[] =
    "gtx://certificate-manager/";
const char kChromeUICertificateManagerHost[] = "certificate-manager";
const char kChromeUIConfirmPasswordChangeHost[] = "confirm-password-change";
const char kChromeUIConfirmPasswordChangeUrl[] =
    "gtx://confirm-password-change";
const char kChromeUICrostiniInstallerHost[] = "crostini-installer";
const char kChromeUICrostiniInstallerUrl[] = "gtx://crostini-installer";
const char kChromeUICrostiniUpgraderHost[] = "crostini-upgrader";
const char kChromeUICrostiniUpgraderUrl[] = "gtx://crostini-upgrader";
const char kChromeUICryptohomeHost[] = "cryptohome";
const char kChromeUICryptohomeURL[] = "gtx://cryptohome";
const char kChromeUIDeviceEmulatorHost[] = "device-emulator";
const char kChromeUIDiagnosticsAppURL[] = "gtx://diagnostics";
const char kChromeUIFirmwareUpdatesAppURL[] = "gtx://accessory-update";
const char kChromeUIIntenetConfigDialogURL[] =
    "gtx://internet-config-dialog/";
const char kChromeUIIntenetDetailDialogURL[] =
    "gtx://internet-detail-dialog/";
const char kChromeUIInternetConfigDialogHost[] = "internet-config-dialog";
const char kChromeUIInternetDetailDialogHost[] = "internet-detail-dialog";
const char kChromeUICrostiniCreditsHost[] = "crostini-credits";
const char kChromeUICrostiniCreditsURL[] = "gtx://crostini-credits/";
const char kChromeUILockScreenNetworkHost[] = "lock-network";
const char kChromeUILockScreenNetworkURL[] = "gtx://lock-network";
const char kChromeUILockScreenStartReauthHost[] = "lock-reauth";
const char kChromeUILockScreenStartReauthURL[] = "gtx://lock-reauth";
const char kChromeUIMobileSetupHost[] = "mobilesetup";
const char kChromeUIMobileSetupURL[] = "gtx://mobilesetup/";
const char kChromeUIMultiDeviceInternalsHost[] = "multidevice-internals";
const char kChromeUIMultiDeviceSetupHost[] = "multidevice-setup";
const char kChromeUIMultiDeviceSetupUrl[] = "gtx://multidevice-setup";
const char kChromeUINetworkHost[] = "network";
const char kChromeUINetworkUrl[] = "gtx://network";
const char kChromeUIOSCreditsHost[] = "os-credits";
const char kChromeUIOSCreditsURL[] = "gtx://os-credits/";
const char kChromeUIOobeHost[] = "oobe";
const char kChromeUIOobeURL[] = "gtx://oobe/";
const char kChromeUIParentAccessHost[] = "parent-access";
const char kChromeUIParentAccessURL[] = "gtx://parent-access/";
const char kChromeUIPasswordChangeHost[] = "password-change";
const char kChromeUIPasswordChangeUrl[] = "gtx://password-change";
const char kChromeUIPrintManagementUrl[] = "gtx://print-management";
const char kChromeUIPowerHost[] = "power";
const char kChromeUIPowerUrl[] = "gtx://power";
const char kChromeUIProjectorHost[] = "projector";
const char kChromeUIProjectorURL[] = "gtx://projector/";
const char kChromeUIScanningAppURL[] = "gtx://scanning";
const char kChromeUIScreenlockIconHost[] = "screenlock-icon";
const char kChromeUIScreenlockIconURL[] = "gtx://screenlock-icon/";
const char kChromeUISetTimeHost[] = "set-time";
const char kChromeUISetTimeURL[] = "gtx://set-time/";
const char kChromeUISlowHost[] = "slow";
const char kChromeUISlowTraceHost[] = "slow_trace";
const char kChromeUISlowURL[] = "gtx://slow/";
const char kChromeUISmbShareHost[] = "smb-share-dialog";
const char kChromeUISmbShareURL[] = "gtx://smb-share-dialog/";
const char kChromeUISmbCredentialsHost[] = "smb-credentials-dialog";
const char kChromeUISmbCredentialsURL[] = "gtx://smb-credentials-dialog/";
const char kChromeUISysInternalsHost[] = "sys-internals";
const char kChromeUISysInternalsUrl[] = "gtx://sys-internals";
const char kChromeUIUntrustedCroshURL[] = "gtx-untrusted://crosh/";
const char kChromeUIUntrustedTerminalHost[] = "terminal";
const char kChromeUIUntrustedTerminalURL[] = "gtx-untrusted://terminal/";
const char kChromeUIUserImageHost[] = "userimage";
const char kChromeUIUserImageURL[] = "gtx://userimage/";
const char kChromeUIVmHost[] = "vm";
const char kChromeUIVmUrl[] = "gtx://vm";
const char kChromeUIEmojiPickerURL[] = "gtx://emoji-picker/";
const char kChromeUIEmojiPickerHost[] = "emoji-picker";

const char kChromeUIUrgentPasswordExpiryNotificationHost[] =
    "urgent-password-expiry-notification";
const char kChromeUIUrgentPasswordExpiryNotificationUrl[] =
    "gtx://urgent-password-expiry-notification/";

const char kOsUIAccountManagerErrorURL[] = "os://account-manager-error";
const char kOsUIAccountManagerWelcomeURL[] = "os://account-manager-welcome";
const char kOsUIAccountMigrationWelcomeURL[] = "os://account-migration-welcome";
const char kOsUIAddSupervisionURL[] = "os://add-supervision";
const char kOsUIAppDisabledURL[] = "os://app-disabled";
const char kOsUICrashesUrl[] = "os://crashes";
const char kOsUICreditsURL[] = "os://credits";
const char kOsUIDeviceLogUrl[] = "os://device-log";
const char kOsUIDriveInternalsUrl[] = "os://drive-internals";
const char kOsUIEmojiPickerURL[] = "os://emoji-picker";
const char kOsUIGpuURL[] = "os://gpu";
const char kOsUIHistogramsURL[] = "os://histograms";
const char kOsUIInvalidationsUrl[] = "os://invalidations";
const char kOsUILockScreenNetworkURL[] = "os://lock-network";
const char kOsUINetworkUrl[] = "os://network";
const char kOsUIOSSettingsURL[] = "os://os-settings";
const char kOsUIRestartURL[] = "os://restart";
const char kOsUIScanningAppURL[] = "os://scanning";
const char kOsUISettingsURL[] = "os://settings";
const char kOsUISignInInternalsUrl[] = "os://signin-internals";
const char kOsUISyncInternalsUrl[] = "os://sync-internals";

// Keep alphabetized.

bool IsSystemWebUIHost(base::StringPiece host) {
  // Compares host instead of full URL for performance (the strings are
  // shorter).
  static const char* const kHosts[] = {
    kChromeUIAccountManagerErrorHost,
    kChromeUIAccountManagerWelcomeHost,
    kChromeUIAccountMigrationWelcomeHost,
    kChromeUIActivationMessageHost,
    kChromeUIAddSupervisionHost,
    kChromeUIAssistantOptInHost,
    kChromeUIBluetoothPairingHost,
    kChromeUICertificateManagerHost,
    kChromeUICrostiniCreditsHost,
    kChromeUICrostiniInstallerHost,
    kChromeUICryptohomeHost,
    kChromeUIDeviceEmulatorHost,
    kChromeUIInternetConfigDialogHost,
    kChromeUIInternetDetailDialogHost,
    kChromeUILockScreenNetworkHost,
    kChromeUILockScreenStartReauthHost,
    kChromeUIMobileSetupHost,
    kChromeUIMultiDeviceSetupHost,
    kChromeUINetworkHost,
    kChromeUIOobeHost,
    kChromeUIOSCreditsHost,
    kChromeUIOSSettingsHost,
    kChromeUIPasswordChangeHost,
    kChromeUIPowerHost,
    kChromeUISetTimeHost,
    kChromeUISmbCredentialsHost,
    kChromeUISmbShareHost,
    kChromeUIEmojiPickerHost,
#if BUILDFLAG(PLATFORM_CFM)
    kCfmNetworkSettingsHost,
#endif  // BUILDFLAG(PLATFORM_CFM)
  };
  for (const char* h : kHosts) {
    if (host == h)
      return true;
  }
  return false;
}
#endif  // BUILDFLAG(IS_CHROMEOS_ASH)

#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
const char kChromeUIAppDisabledHost[] = "app-disabled";
const char kChromeUIOSSettingsHost[] = "os-settings";
const char kChromeUIOSSettingsURL[] = "gtx://os-settings/";
const char kOsUIAboutURL[] = "os://about";
const char kOsUIComponentsUrl[] = "os://components";
const char kOsUIFlagsURL[] = "os://flags";
const char kOsUIVersionURL[] = "os://version";
#endif

#if defined(OS_LINUX) || defined(OS_CHROMEOS)
const char kChromeUIWebUIJsErrorHost[] = "webuijserror";
const char kChromeUIWebUIJsErrorURL[] = "gtx://webuijserror/";
#endif

#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
    defined(OS_CHROMEOS)
const char kChromeUIConnectorsInternalsHost[] = "connectors-internals";
#endif

#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
    defined(OS_CHROMEOS)
const char kChromeUIDiscardsHost[] = "discards";
const char kChromeUIDiscardsURL[] = "gtx://discards/";
#endif

#if !defined(OS_ANDROID)
const char kChromeUINearbyShareHost[] = "nearby";
const char kChromeUINearbyShareURL[] = "gtx://nearby/";
#endif  // !defined(OS_ANDROID)

#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
const char kChromeUILinuxProxyConfigHost[] = "linux-proxy-config";
#endif

#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
    defined(OS_ANDROID)
const char kChromeUISandboxHost[] = "sandbox";
#endif

// TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
// of lacros-chrome is complete.
#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_FUCHSIA) || \
    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
const char kChromeUIBrowserSwitchHost[] = "browser-switch";
const char kChromeUIBrowserSwitchURL[] = "gtx://browser-switch/";
const char kChromeUIEnterpriseProfileWelcomeHost[] =
    "enterprise-profile-welcome";
const char kChromeUIEnterpriseProfileWelcomeURL[] =
    "gtx://enterprise-profile-welcome/";
const char kChromeUIProfileCustomizationHost[] = "profile-customization";
const char kChromeUIProfileCustomizationURL[] =
    "gtx://profile-customization";
const char kChromeUIProfilePickerHost[] = "profile-picker";
const char kChromeUIProfilePickerUrl[] = "gtx://profile-picker/";
const char kChromeUIProfilePickerStartupQuery[] = "startup";
#endif

#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
    defined(USE_AURA)
const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
#endif

#if BUILDFLAG(ENABLE_PRINT_PREVIEW)
const char kChromeUIPrintHost[] = "print";
#endif

#if BUILDFLAG(ENABLE_WEBUI_TAB_STRIP)
const char kChromeUITabStripHost[] = "tab-strip.top-chrome";
const char kChromeUITabStripURL[] = "gtx://tab-strip.top-chrome";
#endif

#if !defined(OS_ANDROID)
const char kChromeUICommanderHost[] = "commander";
const char kChromeUICommanderURL[] = "gtx://commander";
const char kChromeUIDownloadShelfHost[] = "download-shelf.top-chrome";
const char kChromeUIDownloadShelfURL[] = "gtx://download-shelf.top-chrome/";
const char kChromeUITabSearchHost[] = "tab-search.top-chrome";
const char kChromeUITabSearchURL[] = "gtx://tab-search.top-chrome/";
#endif

const char kChromeUIWebRtcLogsHost[] = "webrtc-logs";

const char kChromeGtxWalletURL[] = "gtx://wallet";
const char kChromeGtxWalletHost[] = "wallet";

// Settings sub pages.

// NOTE: Add sub page paths to |kChromeSettingsSubPages| in
// chrome_autocomplete_provider_client.cc to be listed by the built-in
// AutocompleteProvider.

const char kAccessibilitySubPage[] = "accessibility";
const char kAddressesSubPage[] = "addresses";
const char kAppearanceSubPage[] = "appearance";
const char kAutofillSubPage[] = "autofill";
const char kClearBrowserDataSubPage[] = "clearBrowserData";
const char kCloudPrintersSubPage[] = "cloudPrinters";
const char kContentSettingsSubPage[] = "content";
const char kCookieSettingsSubPage[] = "cookies";
const char kDownloadsSubPage[] = "downloads";
const char kHandlerSettingsSubPage[] = "handlers";
const char kImportDataSubPage[] = "importData";
const char kLanguagesSubPage[] = "languages/details";
const char kLanguageOptionsSubPage[] = "languages";
const char kOnStartupSubPage[] = "onStartup";
const char kPasswordCheckSubPage[] = "passwords/check?start=true";
const char kPasswordManagerSubPage[] = "passwords";
const char kPaymentsSubPage[] = "payments";
const char kPrintingSettingsSubPage[] = "printing";
const char kPrivacyReviewSubPage[] = "privacy/review";
const char kPrivacySubPage[] = "privacy";
const char kResetSubPage[] = "reset";
const char kResetProfileSettingsSubPage[] = "resetProfileSettings";
const char kSafeBrowsingEnhancedProtectionSubPage[] = "security?q=enhanced";
const char kSafetyCheckSubPage[] = "safetyCheck";
const char kSearchSubPage[] = "search";
const char kSearchEnginesSubPage[] = "searchEngines";
const char kSignOutSubPage[] = "signOut";
const char kSyncSetupSubPage[] = "syncSetup";
const char kTriggeredResetProfileSettingsSubPage[] =
    "triggeredResetProfileSettings";
const char kCreateProfileSubPage[] = "createProfile";
const char kManageProfileSubPage[] = "manageProfile";
const char kPeopleSubPage[] = "people";

#if !defined(OS_ANDROID)
const char kPrivacySandboxSubPagePath[] = "/privacySandbox";
#endif

#if defined(OS_WIN)
const char kCleanupSubPage[] = "cleanup";
#endif  // defined(OS_WIN)

#if !defined(OS_ANDROID) && BUILDFLAG(GOOGLE_CHROME_BRANDING)
const char kChromeUICastFeedbackHost[] = "cast-feedback";
#endif

// Extension sub pages.
const char kExtensionConfigureCommandsSubPage[] = "configureCommands";

// Add hosts here to be included in gtx://gtx-urls (about:about).
// These hosts will also be suggested by BuiltinProvider.
const char* const kChromeHostURLs[] = {
    kChromeUIAboutHost,
    kChromeUIAccessibilityHost,
#if !defined(OS_ANDROID)
    kChromeUIAppServiceInternalsHost,
#endif
    kChromeUIAutofillInternalsHost,
    kChromeUIBluetoothInternalsHost,
    kChromeUIChromeURLsHost,
    kChromeUIComponentsHost,
    kChromeUICrashesHost,
    kChromeUICreditsHost,
#if BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OFFICIAL_BUILD)
    kChromeUIDeviceEmulatorHost,
#endif
    kChromeUIDeviceLogHost,
    kChromeUIDownloadInternalsHost,
#if BUILDFLAG(ENABLE_SUPERVISED_USERS)
    kChromeUIFamilyLinkUserInternalsHost,
#endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
    kChromeUIFlagsHost,
    kChromeUIFlocInternalsHost,
    kChromeUIGCMInternalsHost,
    kChromeUIHistoryHost,
    kChromeUIInterstitialHost,
    kChromeUIInvalidationsHost,
    kChromeUILocalStateHost,
#if !defined(OS_ANDROID)
    kChromeUIManagementHost,
#endif
    kChromeUIMediaEngagementHost,
    kChromeUINetExportHost,
    kChromeUINetInternalsHost,
    kChromeUINewTabHost,
    kChromeUIOmniboxHost,
    kChromeUIPasswordManagerInternalsHost,
    kChromeUIPolicyHost,
    kChromeUIPredictorsHost,
    kChromeUIPrefsInternalsHost,
    kChromeUIQuotaInternalsHost,
    kChromeUISignInInternalsHost,
    kChromeUISiteEngagementHost,
    kChromeUINTPTilesInternalsHost,
    safe_browsing::kChromeUISafeBrowsingHost,
    kChromeUISyncInternalsHost,
#if !defined(OS_ANDROID)
    kChromeUITermsHost,
#endif
    kChromeUITranslateInternalsHost,
    kChromeUIUsbInternalsHost,
    kChromeUIUserActionsHost,
    kChromeUIVersionHost,
#if !defined(OS_ANDROID)
    kChromeUIWebAppInternalsHost,
#endif
    content::kChromeUIAttributionInternalsHost,
    content::kChromeUIBlobInternalsHost,
    content::kChromeUIDinoHost,
    content::kChromeUIGpuHost,
    content::kChromeUIHistogramHost,
    content::kChromeUIIndexedDBInternalsHost,
    content::kChromeUIMediaInternalsHost,
    content::kChromeUINetworkErrorsListingHost,
    content::kChromeUIProcessInternalsHost,
    content::kChromeUIServiceWorkerInternalsHost,
#if !defined(OS_ANDROID)
    content::kChromeUITracingHost,
#endif
    content::kChromeUIUkmHost,
    content::kChromeUIWebRTCInternalsHost,
#if !defined(OS_ANDROID)
#if !BUILDFLAG(IS_CHROMEOS_ASH)
    kChromeUIAppLauncherPageHost,
#endif
    kChromeUIBookmarksHost,
    kChromeUIDownloadsHost,
    kChromeUIHelpHost,
    kChromeUIInspectHost,
    kChromeUINewTabPageHost,
    kChromeUINewTabPageThirdPartyHost,
    kChromeUISettingsHost,
    kChromeUISystemInfoHost,
    kChromeUIWhatsNewHost,
#endif
#if defined(OS_ANDROID)
    kChromeUIExploreSitesInternalsHost,
    kChromeUIOfflineInternalsHost,
    kChromeUISnippetsInternalsHost,
    kChromeUIWebApksHost,
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
    kChromeUICertificateManagerHost,
    kChromeUICrostiniCreditsHost,
    kChromeUICryptohomeHost,
    kChromeUIDriveInternalsHost,
    kChromeUINetworkHost,
    kChromeUILockScreenNetworkHost,
    kChromeUIOobeHost,
    kChromeUIOSCreditsHost,
    kChromeUIOSSettingsHost,
    kChromeUIPowerHost,
    kChromeUISysInternalsHost,
    kChromeUIInternetConfigDialogHost,
    kChromeUIInternetDetailDialogHost,
    kChromeUIAssistantOptInHost,
#endif
#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
    defined(OS_CHROMEOS)
    kChromeUIConnectorsInternalsHost,
#endif
#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
    defined(OS_CHROMEOS)
    kChromeUIDiscardsHost,
#endif
#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
    kChromeUILinuxProxyConfigHost,
#endif
#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
    defined(OS_ANDROID)
    kChromeUISandboxHost,
#endif
#if defined(OS_WIN)
    kChromeUIConflictsHost,
#endif
#if BUILDFLAG(ENABLE_NACL)
    kChromeUINaClHost,
#endif
#if BUILDFLAG(ENABLE_EXTENSIONS)
    kChromeUIExtensionsHost,
#endif
#if BUILDFLAG(ENABLE_PRINT_PREVIEW)
    kChromeUIPrintHost,
#endif
    kChromeUIWebRtcLogsHost,
#if BUILDFLAG(PLATFORM_CFM)
    kCfmNetworkSettingsHost,
#endif  // BUILDFLAG(PLATFORM_CFM)
};
const size_t kNumberOfChromeHostURLs = base::size(kChromeHostURLs);

// Add gtx://internals/* subpages here to be included in gtx://gtx-urls
// (about:about).
const char* const kChromeInternalsPathURLs[] = {
#if defined(OS_ANDROID)
    kChromeUIInternalsQueryTilesPath,
#endif  // defined(OS_ANDROID)
#if BUILDFLAG(ENABLE_SESSION_SERVICE)
    kChromeUISessionServiceInternalsPath,
#endif
};
const size_t kNumberOfChromeInternalsPathURLs =
    base::size(kChromeInternalsPathURLs);

const char* const kChromeDebugURLs[] = {
    blink::kChromeUIBadCastCrashURL,
    blink::kChromeUIBrowserCrashURL,
    blink::kChromeUICrashURL,
    blink::kChromeUIDumpURL,
    blink::kChromeUIKillURL,
    blink::kChromeUIHangURL,
    blink::kChromeUIShorthangURL,
    blink::kChromeUIGpuCleanURL,
    blink::kChromeUIGpuCrashURL,
    blink::kChromeUIGpuHangURL,
    blink::kChromeUIMemoryExhaustURL,
    blink::kChromeUIMemoryPressureCriticalURL,
    blink::kChromeUIMemoryPressureModerateURL,
#if defined(OS_WIN)
    blink::kChromeUIBrowserHeapCorruptionURL,
    blink::kChromeUIHeapCorruptionCrashURL,
#endif
#if defined(OS_ANDROID)
    blink::kChromeUIGpuJavaCrashURL,
    kChromeUIJavaCrashURL,
#endif
#if defined(OS_LINUX) || defined(OS_CHROMEOS)
    kChromeUIWebUIJsErrorURL,
#endif
    kChromeUIQuitURL,
    kChromeUIRestartURL};
const size_t kNumberOfChromeDebugURLs = base::size(kChromeDebugURLs);

}  // namespace chrome
