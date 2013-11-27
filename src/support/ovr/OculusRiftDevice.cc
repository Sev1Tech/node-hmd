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
	   pHMD->GetDeviceInfo(&this->DeviceInfo);
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
	std::cout << this->DeviceInfo.HResolution << std::endl;

	deviceInfo->hResolution = this->DeviceInfo.HResolution;
	deviceInfo->vResolution = this->DeviceInfo.VResolution;
	deviceInfo->hScreenSize = this->DeviceInfo.HScreenSize;
	deviceInfo->vScreenSize = this->DeviceInfo.VScreenSize;
	deviceInfo->vScreenCenter = this->DeviceInfo.VScreenCenter;
	deviceInfo->eyetoScreenDistance = this->DeviceInfo.EyeToScreenDistance;;
	deviceInfo->lensSeparationDistance = this->DeviceInfo.LensSeparationDistance;
	deviceInfo->interpuillaryDistance = this->DeviceInfo.InterpupillaryDistance;
	deviceInfo->distortionK[0] = this->DeviceInfo.DistortionK[0];
	deviceInfo->distortionK[1] = this->DeviceInfo.DistortionK[1];
	deviceInfo->distortionK[2] = this->DeviceInfo.DistortionK[2];
	deviceInfo->distortionK[3] = this->DeviceInfo.DistortionK[3];
	deviceInfo->desktopX = this->DeviceInfo.DesktopX;
	deviceInfo->desktopY = this->DeviceInfo.DesktopY;
	strcpy(deviceInfo->displayDeviceName, "Oculus Rift");
	deviceInfo->displayId = this->DeviceInfo.DisplayId;
	strcpy(deviceInfo->productName, this->DeviceInfo.ProductName);
	strcpy(deviceInfo->manufacturer, this->DeviceInfo.Manufacturer);
	deviceInfo->version = this->DeviceInfo.Version;
}

void OculusRiftDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
	OVR::Quatf quaternion = pFusionResult->GetOrientation();

	float yaw, pitch, roll;
	quaternion.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);

	deviceOrientation->yaw = yaw;
	deviceOrientation->pitch = pitch;
	deviceOrientation->roll = roll;
}