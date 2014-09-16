/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_
#define SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_

#include <string>

#include "HMDDevice.h"

class DefaultDevice : public HMDDevice {
 private:
    static const std::string displayDeviceName;
    static const std::string deviceName;
    static const std::string deviceManufacturer;

 public:
    static const std::string classToken;
    // void getDeviceInfo(HMDDeviceInfo* deviceInfo);
    void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
};

#endif  // SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_
