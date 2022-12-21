// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/webui/projector_app/public/cpp/projector_app_constants.h"

namespace ash {

const char kChromeUIProjectorAppHost[] = "projector";

// content::WebUIDataSource::Create() requires trailing slash.
const char kChromeUIUntrustedProjectorAppUrl[] =
    "gtx-untrusted://projector/";
const char kChromeUIUntrustedProjectorPwaUrl[] =
    "https://projector.apps.chrome";

const char kChromeUITrustedProjectorUrl[] = "gtx://projector/";
const char kChromeUITrustedProjectorAppUrl[] = "gtx://projector/app/";
const char kChromeUITrustedProjectorSelfieCamUrl[] =
    "gtx://projector/selfie_cam/selfie_cam.html";
const char kChromeUITrustedAnnotatorUrl[] =
    "gtx://projector/annotator/annotator_embedder.html";
const char kChromeUITrustedProjectorSwaAppId[] =
    "fgnpbdobngpkonkajbmelfhjkemaddhp";

}  // namespace ash
