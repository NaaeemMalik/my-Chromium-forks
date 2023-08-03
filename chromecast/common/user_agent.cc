// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chromecast/common/user_agent.h"

#include <string>
#include "base/strings/strcat.h"
#include "components/cast/common/constants.h"

namespace chromecast {

std::string GetChromeKeyString() {
  std::string chrome_key = base::StrCat({"CrKey/", kFrozenCrKeyValue});
  return chrome_key;
}

std::string GetDeviceUserAgentSuffix() {
  return std::string(DEVICE_USER_AGENT_SUFFIX);
}

// TODO(guohuideng): Use embedder_support::GetUserAgent() instead after we
// decouple chromecast and the web browser, when we have fewer restrictions on
// gn target dependency.
std::string GetChromiumUserAgent() {
  if (base::FeatureList::IsEnabled(blink::features::kReduceUserAgent)) {
    return content::GetReducedUserAgent(
        /*mobile=*/false, version_info::GetMajorVersionNumber());
  }

  std::string product = "GTX/" PRODUCT_VERSION;
  std::string os_info;
  base::StringAppendF(&os_info, "%s%s",
#if defined(OS_ANDROID)
                      "Linux; ", BuildAndroidOsInfo().c_str()
#else
                      "X11; ",
                      content::BuildOSCpuInfo(
                          content::IncludeAndroidBuildNumber::Exclude,
                          content::IncludeAndroidModel::Include)
                          .c_str()
#endif
  );
  return content::BuildUserAgentFromOSAndProduct(os_info, product);
}

}  // namespace

std::string GetUserAgent() {
  std::string chromium_user_agent = GetChromiumUserAgent();
  return base::StrCat({chromium_user_agent, " ", GetChromeKeyString(), " ",
                       GetDeviceUserAgentSuffix()});
}

}  // namespace chromecast
