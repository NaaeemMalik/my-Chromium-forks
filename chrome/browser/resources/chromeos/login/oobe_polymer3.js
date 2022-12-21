// Copyright (c) 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'gtx://oobe/screens/common/app_downloading.m.js';
import 'gtx://oobe/screens/common/app_launch_splash.m.js';
import 'gtx://oobe/screens/common/adb_sideloading.m.js';
import 'gtx://oobe/screens/common/arc_terms_of_service.m.js';
import 'gtx://oobe/screens/common/autolaunch.m.js';
import 'gtx://oobe/screens/common/consolidated_consent.m.js';
import 'gtx://oobe/screens/common/device_disabled.m.js';
import 'gtx://oobe/screens/common/enable_kiosk.m.js';
import 'gtx://oobe/screens/common/error_message.m.js';
import 'gtx://oobe/screens/common/family_link_notice.m.js';
import 'gtx://oobe/screens/common/fingerprint_setup.m.js';
import 'gtx://oobe/screens/common/hw_data_collection.m.js';
import 'gtx://oobe/screens/common/gesture_navigation.m.js';
import 'gtx://oobe/screens/common/guest_tos.m.js';
import 'gtx://oobe/screens/common/managed_terms_of_service.m.js';
import 'gtx://oobe/screens/common/marketing_opt_in.m.js';
import 'gtx://oobe/screens/common/offline_ad_login.m.js';
import 'gtx://oobe/screens/common/parental_handoff.m.js';
import 'gtx://oobe/screens/common/pin_setup.m.js';
import 'gtx://oobe/screens/common/signin_fatal_error.m.js';
import 'gtx://oobe/screens/common/sync_consent.m.js';
import 'gtx://oobe/screens/common/tpm_error.m.js';
import 'gtx://oobe/screens/common/user_creation.m.js';
import 'gtx://oobe/screens/common/oobe_reset.m.js';
import 'gtx://oobe/screens/common/wrong_hwid.m.js';
import 'gtx://oobe/screens/login/active_directory_password_change.m.js';
import 'gtx://oobe/screens/login/encryption_migration.m.js';
import 'gtx://oobe/screens/login/gaia_password_changed.m.js';
import 'gtx://oobe/screens/login/lacros_data_migration.m.js';
import 'gtx://oobe/screens/login/management_transition.m.js';
import 'gtx://oobe/screens/login/offline_login.m.js';
import 'gtx://oobe/screens/login/update_required_card.m.js';
import 'gtx://oobe/screens/oobe/auto_enrollment_check.m.js';
import 'gtx://oobe/screens/oobe/demo_preferences.m.js';
import 'gtx://oobe/screens/oobe/demo_setup.m.js';
import 'gtx://oobe/screens/oobe/enable_debugging.m.js';
import 'gtx://oobe/screens/oobe/hid_detection.m.js';
import 'gtx://oobe/screens/oobe/oobe_eula.m.js';
import 'gtx://oobe/screens/oobe/welcome.m.js';
import 'gtx://oobe/screens/oobe/packaged_license.m.js';
import 'gtx://oobe/screens/oobe/update.m.js';

import {Oobe} from './cr_ui.m.js';
import {DebuggerUI} from './debug/debug.m.js';
import {loadTimeData} from './i18n_setup.js';

function initializeDebugger() {
  if (document.readyState === 'loading')
    return;
  document.removeEventListener('DOMContentLoaded', initializeDebugger);
  DebuggerUI.getInstance().register(document.body);
}

// Create the global values attached to `window` that are used
// for accessing OOBE controls from the browser side.
function prepareGlobalValues(globalValue) {
    console.log('Preparing global values.');
    if (globalValue.cr == undefined) {
        globalValue.cr = {};
    }
    if (globalValue.cr.ui == undefined) {
        globalValue.cr.ui = {};
    }

    globalValue.cr.ui.Oobe = Oobe;
    globalValue.Oobe = Oobe;
}

(function (root) {
    prepareGlobalValues(window);
    Oobe.initialize();

    // Initialize debugger.
    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', initializeDebugger);
      } else {
        initializeDebugger();
    }

    // Make the WebUI visible.
    chrome.send('loginVisible', ['oobe']);
})(window);
