/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
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
    // deviceInfo->hResolution = this->hmd->Resolution.w;
    // deviceInfo->vResolution = this->hmd->Resolution.h;
    // deviceInfo->hScreenSize = this->DeviceInfo.HScreenSize;
    // deviceInfo->vScreenSize = this->DeviceInfo.VScreenSize;
    // deviceInfo->vScreenCenter = this->DeviceInfo.VScreenCenter;
    // deviceInfo->eyetoScreenDistance = this->DeviceInfo.EyeToScreenDistance;;
    // deviceInfo->lensSeparationDistance = this->DeviceInfo.LensSeparationDistance;
    // deviceInfo->interpuillaryDistance = this->DeviceInfo.InterpupillaryDistance;
    // deviceInfo->distortionK[0] = this->DeviceInfo.DistortionK[0];
    // deviceInfo->distortionK[1] = this->DeviceInfo.DistortionK[1];
    // deviceInfo->distortionK[2] = this->DeviceInfo.DistortionK[2];
    // deviceInfo->distortionK[3] = this->DeviceInfo.DistortionK[3];
    // deviceInfo->desktopX = this->DeviceInfo.DesktopX;
    // deviceInfo->desktopY = this->DeviceInfo.DesktopY;
    // strcpy(deviceInfo->displayDeviceName, this->hmd->DisplayDeviceName);
    // deviceInfo->displayId = this->hmd->DisplayId;
    // strcpy(deviceInfo->productName, this->hmd->ProductName);
    // strcpy(deviceInfo->manufacturer, this->hmd->Manufacturer);
    // deviceInfo->version = this->DeviceInfo.Version;
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    ovrTrackingState trackingState  = ovrHmd_GetTrackingState(hmd, ovr_GetTimeInSeconds());

    if (trackingState.StatusFlags & ovrStatus_OrientationTracked) {
        OVR::Posef pose = trackingState.HeadPose.ThePose;
        pose.Rotation.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&(deviceOrientation->yaw), &(deviceOrientation->pitch), &(deviceOrientation->roll));
    }
}
