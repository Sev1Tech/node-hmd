/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <algorithm>
#include <string>

#include "HMDDeviceInfo.h"

HMDDeviceInfo::HMDDeviceInfo() {
	std::fill(this->displayDeviceName, this->displayDeviceName + MAX_DESCRIPTION_LENGTH, '\0');
	std::fill(this->productName, this->productName + MAX_DESCRIPTION_LENGTH, '\0');
	std::fill(this->manufacturer, this->manufacturer + MAX_DESCRIPTION_LENGTH, '\0');
}

HMDDeviceInfo::~HMDDeviceInfo() {
}

HMDDeviceInfo& HMDDeviceInfo::operator= (const HMDDeviceInfo &deviceInfo) {
	this->hResolution = deviceInfo.hResolution;
	this->vResolution = deviceInfo.vResolution;
	this->hScreenSize = deviceInfo.hScreenSize;
	this->vScreenSize = deviceInfo.vScreenSize;
	this->vScreenCenter = deviceInfo.vScreenCenter;
	this->eyetoScreenDistance = deviceInfo.eyetoScreenDistance;
	this->lensSeparationDistance = deviceInfo.lensSeparationDistance;
	this->interpuillaryDistance = deviceInfo.interpuillaryDistance;
	this->distortionK[0] = deviceInfo.distortionK[0];
	this->distortionK[1] = deviceInfo.distortionK[1];
	this->distortionK[2] = deviceInfo.distortionK[2];
	this->distortionK[3] = deviceInfo.distortionK[3];
	this->desktopX = deviceInfo.desktopX;
	this->desktopY = deviceInfo.desktopY;
	std::copy(deviceInfo.displayDeviceName, deviceInfo.displayDeviceName + MAX_DESCRIPTION_LENGTH, this->displayDeviceName);
	this->displayId = deviceInfo.displayId;
	std::string productName(this->productName);
	std::copy(deviceInfo.productName, deviceInfo.productName + MAX_DESCRIPTION_LENGTH, this->productName);
	std::copy(deviceInfo.manufacturer, deviceInfo.manufacturer + MAX_DESCRIPTION_LENGTH, this->manufacturer);
	this->version = deviceInfo.version;

	return *this;	
}
