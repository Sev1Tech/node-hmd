/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
#define SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_

#include <string>

#include "HMDDevice.h"
#include "OVR.h"

class OculusRiftDevice : public HMDDevice {
 private:
    ovrHmd _hmd;
 public:
    static const std::string classToken;

    OculusRiftDevice();
    ~OculusRiftDevice();
    void getDeviceInfo(HMDDeviceInfo* deviceInfo);
    void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
    void getDeviceQuat(HMDDeviceQuat* deviceQuat);
};

#endif  // SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
