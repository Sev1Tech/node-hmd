/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
#define SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_

#include <node.h>

#include <HMDDevice.h>
#include <OVR.h>

#include <string>

class OculusDeviceOrientation : public HMDDeviceOrientation {
 public:
    float* getYawReference() { return &this->_yaw; }
    float* getPitchReference() { return &this->_pitch; }
    float* getRollReference() { return &this->_roll; }
};

class OculusRiftDevice : public HMDDevice {
 private:
    ovrHmd _hmd;
    OculusDeviceOrientation _deviceOrientation;
    HMDDevicePosition _devicePosition;
    HMDDeviceQuat _deviceQuat;

    void updateDevice();
 public:
    static const std::string classToken;

    OculusRiftDevice();
    ~OculusRiftDevice();
    static void initializeModule(v8::Handle<v8::Object> exports);
    void getDeviceInfo(HMDDeviceInfo* deviceInfo);
    void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
    void getDevicePosition(HMDDevicePosition* devicePosition);
    void getDeviceQuat(HMDDeviceQuat* deviceQuat);
};

#endif  // SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
