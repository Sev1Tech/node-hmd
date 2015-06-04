/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_
#define SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_

#include <node.h>

#include <HMDDevice.h>

#include <string>

class DefaultDevice : public HMDDevice {
 private:
    static const std::string displayDeviceName;
    static const std::string deviceName;
    static const std::string deviceManufacturer;

 public:
    static const std::string classToken;

    static void initializeModule(v8::Handle<v8::Object> exports);
    void getDeviceInfo(HMDDeviceInfo* deviceInfo);
    void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
    void getDevicePosition(HMDDevicePosition* devicePosition);
    void getDeviceQuat(HMDDeviceQuat* deviceQuat);
};

#endif  // SRC_SUPPORT_DEFAULT_DEFAULTDEVICE_H_
