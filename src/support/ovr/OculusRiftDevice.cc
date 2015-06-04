/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <OculusRiftDevice.h>

#include <HMDDeviceInfoElement.h>
#include <OvrFovPort.h>
#include <OvrSizei.h>
#include <OvrVector2i.h>

const std::string OculusRiftDevice::classToken = "oculusrift";

void OculusRiftDevice::initializeModule(v8::Handle<v8::Object> exports) {
    OvrFovPortWrap::Initialize(exports);
    OvrSizeiWrap::Initialize(exports);
    OvrVector2iWrap::Initialize(exports);
}

OculusRiftDevice::~OculusRiftDevice() {
    ovrHmd_Destroy(this->_hmd);
    ovr_Shutdown();
}

#ifdef OVR_0_4_2

OculusRiftDevice::OculusRiftDevice() {
    ovr_Initialize();

    this->_hmd = ovrHmd_Create(0);
    ovrHmd_ConfigureTracking(this->_hmd, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, ovrTrackingCap_Orientation);
}

void OculusRiftDevice::updateDevice() {
    ovrTrackingState trackingState  = ovrHmd_GetTrackingState(this->_hmd, ovr_GetTimeInSeconds());

    if (trackingState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
        OVR::Posef pose = trackingState.HeadPose.ThePose;

        this->_deviceQuat.setQuat(pose.Rotation.w, pose.Rotation.x, pose.Rotation.y, pose.Rotation.z);
        pose.Rotation.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(this->_deviceOrientation.getYawReference(), this->_deviceOrientation.getPitchReference(), this->_deviceOrientation.getRollReference());

        this->_devicePosition.setPosition(pose.Translation.x, pose.Translation.y, pose.Translation.z);
    }
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
    deviceInfo->insertElement("Resolution", new OvrSizei(this->_hmd->Resolution));
    deviceInfo->insertElement("WindowsPos", new OvrVector2i(this->_hmd->WindowsPos));

    OvrFovPort* DefaultEyeFov[ovrEye_Count];
    OvrFovPort* MaxEyeFov[ovrEye_Count];
    int EyeRenderOrder[ovrEye_Count];

    for (int eyeIndex = 0; eyeIndex < ovrEye_Count; eyeIndex++) {
        DefaultEyeFov[eyeIndex] = new OvrFovPort(this->_hmd->DefaultEyeFov[eyeIndex]);
        MaxEyeFov[eyeIndex] = new OvrFovPort(this->_hmd->MaxEyeFov[eyeIndex]);
        EyeRenderOrder[eyeIndex] = this->_hmd->EyeRenderOrder[eyeIndex];
    }
    deviceInfo->insertElement("DefaultEyeFov", new InfoTypeArray<HMDDeviceInfoElement *>(reinterpret_cast<HMDDeviceInfoElement **>(DefaultEyeFov), ovrEye_Count));
    deviceInfo->insertElement("MaxEyeFov", new InfoTypeArray<HMDDeviceInfoElement *>(reinterpret_cast<HMDDeviceInfoElement **>(MaxEyeFov), ovrEye_Count));
    deviceInfo->insertElement("EyeRenderOrder", new InfoTypeArray<int>(EyeRenderOrder, ovrEye_Count));
    deviceInfo->insertElement("DisplayDeviceName", new InfoTypeString(this->_hmd->DisplayDeviceName));
    deviceInfo->insertElement("DisplayId", new InfoTypeUInt(this->_hmd->DisplayId));
}

#endif

#ifdef OVR_0_3_2

OculusRiftDevice::OculusRiftDevice() {
    ovr_Initialize();

    this->_hmd = ovrHmd_Create(0);
    ovrHmd_StartSensor(this->_hmd, ovrSensorCap_Orientation | ovrSensorCap_YawCorrection | ovrSensorCap_Position, ovrSensorCap_Orientation);
}

void OculusRiftDevice::updateDevice() {
    ovrSensorState trackingState  = ovrHmd_GetSensorState(this->_hmd, ovr_GetTimeInSeconds());

    if (trackingState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
        OVR::Transformf pose = trackingState.Predicted.Pose;

        this->_deviceQuat.setQuat(pose.Rotation.w, pose.Rotation.x, pose.Rotation.y, pose.Rotation.z);
        pose.Rotation.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(this->_deviceOrientation.getYawReference(), this->_deviceOrientation.getPitchReference(), this->_deviceOrientation.getRollReference());

        this->_devicePosition.setPosition(pose.Translation.x, pose.Translation.y, pose.Translation.z);
    }
}

void OculusRiftDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    ovrHmdDesc hmdDesc;
    ovrHmd_GetDesc(this->_hmd, &hmdDesc);

    deviceInfo->insertElement("ProductName", new InfoTypeString(hmdDesc.ProductName));
    deviceInfo->insertElement("Manufacturer", new InfoTypeString(hmdDesc.Manufacturer));
    deviceInfo->insertElement("HmdCaps", new InfoTypeUInt(hmdDesc.HmdCaps));
    deviceInfo->insertElement("SensorCaps", new InfoTypeUInt(hmdDesc.SensorCaps));
    deviceInfo->insertElement("DistortionCaps", new InfoTypeUInt(hmdDesc.DistortionCaps));
    deviceInfo->insertElement("Resolution", new OvrSizei(hmdDesc.Resolution));
    deviceInfo->insertElement("WindowsPos", new OvrVector2i(hmdDesc.WindowsPos));

    OvrFovPort* DefaultEyeFov[ovrEye_Count];
    OvrFovPort* MaxEyeFov[ovrEye_Count];
    int EyeRenderOrder[ovrEye_Count];

    for (int eyeIndex = 0; eyeIndex < ovrEye_Count; eyeIndex++) {
        DefaultEyeFov[eyeIndex] = new OvrFovPort(hmdDesc.DefaultEyeFov[eyeIndex]);
        MaxEyeFov[eyeIndex] = new OvrFovPort(hmdDesc.MaxEyeFov[eyeIndex]);
        EyeRenderOrder[eyeIndex] = hmdDesc.EyeRenderOrder[eyeIndex];
    }

    deviceInfo->insertElement("DefaultEyeFov", new InfoTypeArray<HMDDeviceInfoElement *>(reinterpret_cast<HMDDeviceInfoElement **>(DefaultEyeFov), ovrEye_Count));
    deviceInfo->insertElement("MaxEyeFov", new InfoTypeArray<HMDDeviceInfoElement *>(reinterpret_cast<HMDDeviceInfoElement **>(MaxEyeFov), ovrEye_Count));
    deviceInfo->insertElement("EyeRenderOrder", new InfoTypeArray<int>(EyeRenderOrder, ovrEye_Count));
    deviceInfo->insertElement("DisplayDeviceName", new InfoTypeString(hmdDesc.DisplayDeviceName));
    deviceInfo->insertElement("DisplayId", new InfoTypeUInt(hmdDesc.DisplayId));
}

#endif


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
    deviceQuat->setQuat((HMDDeviceQuat)this->_deviceQuat);
}
