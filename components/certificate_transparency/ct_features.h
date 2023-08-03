// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_CERTIFICATE_TRANSPARENCY_CT_FEATURES_H_
#define COMPONENTS_CERTIFICATE_TRANSPARENCY_CT_FEATURES_H_

#include "base/component_export.h"
#include "base/feature_list.h"

namespace certificate_transparency {
namespace features {

COMPONENT_EXPORT(CERTIFICATE_TRANSPARENCY)
BASE_DECLARE_FEATURE(kCertificateTransparencyComponentUpdater);

// If enabled, the 2022 CT policy which removes the one Google log
// requirement, introduces log operator diversity requirements, and increases
// the number of embedded SCTs required for certificates with a lifetime over
// 180 days (from 2 to 3) will be used for any certificate issued after February
// 1, 2022.
extern const base::Feature kCertificateTransparency2022Policy;

// If enabled, the 2022 CT policy which removes the one Google log
// requirement, introduces log operator diversity requirements, and increases
// the number of embedded SCTs required for certificates with a lifetime over
// 180 days (from 2 to 3) will be used for all certificates.
extern const base::Feature kCertificateTransparency2022PolicyAllCerts;

}  // namespace features
}  // namespace certificate_transparency

#endif  // COMPONENTS_CERTIFICATE_TRANSPARENCY_CT_FEATURES_H_
