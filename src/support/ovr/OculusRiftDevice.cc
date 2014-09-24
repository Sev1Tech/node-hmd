/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "OculusRiftDevice.h"

const std::string OculusRiftDevice::classToken = "oculusrift";

OculusRiftDevice::OculusRiftDevice() {
    ovr_Initialize();

    this->hmd = ovrHmd_Create(0);
    ovrHmd_ConfigureTracking(this->hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 0);
}

OculusRiftDevice::~OculusRiftDevice() {
    ovrHmd_Destroy(this->hmd);
    ovr_Shutdown();
}

void OculusRiftDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    // TODO(GeoJosh): Reimplement me for 0.4.2
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    ovrTrackingState trackingState  = ovrHmd_GetTrackingState(hmd, ovr_GetTimeInSeconds());

    float yaw, pitch, roll;

    if (trackingState.StatusFlags & ovrStatus_OrientationTracked) {
        OVR::Posef pose = trackingState.HeadPose.ThePose;
        pose.Rotation.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);
        deviceOrientation->setOrientation(yaw, pitch, roll);
    }
}

void OculusRiftDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    // TODO(GeoJosh): Implement Me
}
