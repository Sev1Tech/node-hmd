/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <iostream>
#include <string>

#include "OculusRiftDevice.h"

const std::string OculusRiftDevice::classToken = "oculusrift";

OculusRiftDevice::OculusRiftDevice() {
	OVR::System::Init();

	this->pFusionResult = new OVR::SensorFusion();
	this->pManager = *OVR::DeviceManager::Create();

	this->pHMD = *pManager->EnumerateDevices<OVR::HMDDevice>().CreateDevice();

	if (this->pHMD) {
	   pSensor = *pHMD->GetSensor();
	}
	else {
	   pSensor = *pManager->EnumerateDevices<OVR::SensorDevice>().CreateDevice();
	}

	if (pSensor) {
	   pFusionResult->AttachToSensor(pSensor);
	}
}

OculusRiftDevice::~OculusRiftDevice() {
	this->pSensor.Clear();
    this->pHMD.Clear();
	this->pManager.Clear();

	delete this->pFusionResult;

	OVR::System::Destroy();
}

void OculusRiftDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
	OVR::HMDInfo DeviceInfo;
	this->pHMD->GetDeviceInfo(&DeviceInfo);

	deviceInfo->hResolution = DeviceInfo.HResolution;
	deviceInfo->vResolution = DeviceInfo.VResolution;
	deviceInfo->hScreenSize = DeviceInfo.HScreenSize;
	deviceInfo->vScreenSize = DeviceInfo.VScreenSize;
	deviceInfo->vScreenCenter = DeviceInfo.VScreenCenter;
	deviceInfo->eyetoScreenDistance = DeviceInfo.EyeToScreenDistance;;
	deviceInfo->lensSeparationDistance = DeviceInfo.LensSeparationDistance;
	deviceInfo->interpuillaryDistance = DeviceInfo.InterpupillaryDistance;
	deviceInfo->distortionK[0] = DeviceInfo.DistortionK[0];
	deviceInfo->distortionK[1] = DeviceInfo.DistortionK[1];
	deviceInfo->distortionK[2] = DeviceInfo.DistortionK[2];
	deviceInfo->distortionK[3] = DeviceInfo.DistortionK[3];
	deviceInfo->desktopX = DeviceInfo.DesktopX;
	deviceInfo->desktopY = DeviceInfo.DesktopY;
	strcpy(deviceInfo->displayDeviceName, "Oculus Rift");
	deviceInfo->displayId = DeviceInfo.DisplayId;
	strcpy(deviceInfo->productName, DeviceInfo.ProductName);
	strcpy(deviceInfo->manufacturer, DeviceInfo.Manufacturer);
	deviceInfo->version = DeviceInfo.Version;
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
	OVR::Quatf quaternion = pFusionResult->GetOrientation();

	float yaw, pitch, roll;
	quaternion.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);

	deviceOrientation->yaw = yaw;
	deviceOrientation->pitch = pitch;
	deviceOrientation->roll = roll;
}