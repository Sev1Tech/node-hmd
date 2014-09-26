/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "OculusRiftDevice.h"

#include "HMDDeviceInfoElement.h"
#include "InfoTypeArray.h"
#include "InfoTypePrimitive.h"

const std::string OculusRiftDevice::classToken = "oculusrift";

OculusRiftDevice::OculusRiftDevice() {
    ovr_Initialize();

    this->_hmd = ovrHmd_Create(0);
    ovrHmd_ConfigureTracking(this->_hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, ovrTrackingCap_Orientation);
}

OculusRiftDevice::~OculusRiftDevice() {
    ovrHmd_Destroy(this->_hmd);
    ovr_Shutdown();
}

void OculusRiftDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("ProductName", new InfoTypeString(this->_hmd->ProductName));
    deviceInfo->insertElement("Manufacturer", new InfoTypeString(this->_hmd->Manufacturer));
    deviceInfo->insertElement("VendorId", new InfoTypeShort(this->_hmd->VendorId));
    deviceInfo->insertElement("ProductId", new InfoTypeShort(this->_hmd->ProductId));
    deviceInfo->insertElement("SerialNumber", new InfoTypeString(this->_hmd->SerialNumber));
    deviceInfo->insertElement("FirmwareMajor", new InfoTypeShort(this->_hmd->FirmwareMajor));
    deviceInfo->insertElement("FirmwareMinor", new InfoTypeShort(this->_hmd->FirmwareMinor));
    deviceInfo->insertElement("CameraFrustumHFovInRadians", new InfoTypeFloat(this->_hmd->CameraFrustumHFovInRadians));
    deviceInfo->insertElement("CameraFrustumVFovInRadians", new InfoTypeFloat(this->_hmd->CameraFrustumVFovInRadians));
    deviceInfo->insertElement("CameraFrustumNearZInMeters", new InfoTypeFloat(this->_hmd->CameraFrustumNearZInMeters));
    deviceInfo->insertElement("CameraFrustumFarZInMeters", new InfoTypeFloat(this->_hmd->CameraFrustumFarZInMeters));
    deviceInfo->insertElement("HmdCaps", new InfoTypeUInt(this->_hmd->HmdCaps));
    deviceInfo->insertElement("TrackingCaps", new InfoTypeUInt(this->_hmd->TrackingCaps));
    deviceInfo->insertElement("DistortionCaps", new InfoTypeUInt(this->_hmd->DistortionCaps));

    // int Resolution[2] = { this->_hmd->Resolution.w, this->_hmd->Resolution.h };
    // deviceInfo->insertElement("Resolution", Resolution, 2);

    // int WindowsPos[2] = { this->_hmd->WindowsPos.x, this->_hmd->WindowsPos.y };
    // deviceInfo->insertElement("WindowsPos", WindowsPos, 2);

    // // TODO(GeoJosh): DefaultEyeFov
    // // TODO(GeoJosh): MaxEyeFov
    // // TODO(GeoJosh): EyeRenderOrder

    deviceInfo->insertElement("DisplayDeviceName", new InfoTypeString(this->_hmd->DisplayDeviceName));
    deviceInfo->insertElement("DisplayId", new InfoTypeUInt(this->_hmd->DisplayId));
}

void OculusRiftDevice::updateDevice() {
    ovrTrackingState trackingState = ovrHmd_GetTrackingState(this->_hmd, ovr_GetTimeInSeconds());

    if (trackingState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
        OVR::Posef pose = trackingState.HeadPose.ThePose;
        pose.Rotation.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(this->_deviceOrientation.getYawReference(), this->_deviceOrientation.getPitchReference(), this->_deviceOrientation.getRollReference());

        this->_devicePosition.setPosition(pose.Translation.x, pose.Translation.y, pose.Translation.z);
    }
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    this->updateDevice();
    deviceOrientation->setOrientation((HMDDeviceOrientation)this->_deviceOrientation);
}

void OculusRiftDevice::getDevicePosition(HMDDevicePosition* devicePosition) {
    this->updateDevice();
    devicePosition->setPosition((HMDDevicePosition)this->_devicePosition);
}

void OculusRiftDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    this->updateDevice();

    // TODO(GeoJosh): Implement Me
}
