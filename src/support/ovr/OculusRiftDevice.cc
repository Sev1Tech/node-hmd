/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "OculusRiftDevice.h"

const std::string OculusRiftDevice::classToken = "oculusrift";

OculusRiftDevice::OculusRiftDevice() {
    ovr_Initialize();

    this->_hmd = ovrHmd_Create(0);
    ovrHmd_ConfigureTracking(this->_hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 0);
}

OculusRiftDevice::~OculusRiftDevice() {
    ovrHmd_Destroy(this->_hmd);
    ovr_Shutdown();
}

void OculusRiftDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    // deviceInfo->insertElement("ProductName", std::string(this->_hmd->ProductName));
    // deviceInfo->insertElement("Manufacturer", std::string(this->_hmd->Manufacturer));
    // deviceInfo->insertElement("VendorId", this->_hmd->VendorId);
    // deviceInfo->insertElement("ProductId", this->_hmd->ProductId);
    // deviceInfo->insertElement("SerialNumber", std::string(this->_hmd->SerialNumber));
    // deviceInfo->insertElement("FirmwareMajor", this->_hmd->FirmwareMajor);
    // deviceInfo->insertElement("FirmwareMinor", this->_hmd->FirmwareMinor);
    // deviceInfo->insertElement("CameraFrustumHFovInRadians", this->_hmd->CameraFrustumHFovInRadians);
    // deviceInfo->insertElement("CameraFrustumVFovInRadians", this->_hmd->CameraFrustumVFovInRadians);
    // deviceInfo->insertElement("CameraFrustumNearZInMeters", this->_hmd->CameraFrustumNearZInMeters);
    // deviceInfo->insertElement("CameraFrustumFarZInMeters", this->_hmd->CameraFrustumFarZInMeters);
    // deviceInfo->insertElement("HmdCaps", this->_hmd->HmdCaps);
    // deviceInfo->insertElement("TrackingCaps", this->_hmd->TrackingCaps);
    // deviceInfo->insertElement("DistortionCaps", this->_hmd->DistortionCaps);

    // int Resolution[2] = { this->_hmd->Resolution.w, this->_hmd->Resolution.h };
    // deviceInfo->insertElement("Resolution", Resolution, 2);

    // int WindowsPos[2] = { this->_hmd->WindowsPos.x, this->_hmd->WindowsPos.y };
    // deviceInfo->insertElement("WindowsPos", WindowsPos, 2);

    // // TODO(GeoJosh): DefaultEyeFov
    // // TODO(GeoJosh): MaxEyeFov
    // // TODO(GeoJosh): EyeRenderOrder

    // deviceInfo->insertElement("DisplayDeviceName", std::string(this->_hmd->DisplayDeviceName));
    // deviceInfo->insertElement("DisplayId", this->_hmd->DisplayId);
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    ovrTrackingState trackingState = ovrHmd_GetTrackingState(this->_hmd, ovr_GetTimeInSeconds());

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
