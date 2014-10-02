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

#if !defined(OVR_0_4_2) && !defined(OVR_0_3_2)
    #error Unsupported OVR version detected!
#endif

#ifdef OVR_0_4_2

    #define OVR_CONFIGURE_DEVICE ovrHmd_ConfigureTracking

    #define OVR_CAPABILITY_ORIENTATION ovrTrackingCap_Orientation
    #define OVR_CAPABILITY_CORRECTION ovrTrackingCap_MagYawCorrection
    #define OVR_CAPABILITY_POSITON ovrTrackingCap_Position

    #define OVR_DEVICE_STATE ovrTrackingState
    #define OVR_GET_DEVICE_STATE ovrHmd_GetTrackingState
    #define OVR_POSE_DECLARATION OVR::Posef
    #define OVR_POSE_ACCESSOR HeadPose.ThePose
#endif

#ifdef OVR_0_3_2

    #define OVR_CONFIGURE_DEVICE ovrHmd_StartSensor

    #define OVR_CAPABILITY_ORIENTATION ovrSensorCap_Orientation
    #define OVR_CAPABILITY_CORRECTION ovrSensorCap_YawCorrection
    #define OVR_CAPABILITY_POSITON ovrSensorCap_Position

    #define OVR_DEVICE_STATE ovrSensorState
    #define OVR_GET_DEVICE_STATE ovrHmd_GetSensorState
    #define OVR_POSE_DECLARATION OVR::Transformf
    #define OVR_POSE_ACCESSOR Predicted.Pose
#endif

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
