/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <iostream>
#include <string>

#include "DefaultDevice.h"

const std::string DefaultDevice::displayDeviceName = "node-hmd default device";
const std::string DefaultDevice::deviceName = "Default Device";
const std::string DefaultDevice::deviceManufacturer = "Geocent LLC";

const std::string DefaultDevice::classToken = "default";

// void DefaultDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
// 	deviceInfo->hResolution = 0;
// 	deviceInfo->vResolution = 0;
// 	deviceInfo->hScreenSize = 0.0;
// 	deviceInfo->vScreenSize = 0.0;
// 	deviceInfo->vScreenCenter = 0;
// 	deviceInfo->eyetoScreenDistance = 0.0;
// 	deviceInfo->lensSeparationDistance = 0.0;
// 	deviceInfo->interpuillaryDistance = 0.0;
// 	deviceInfo->distortionK[0] = 0.0;
// 	deviceInfo->distortionK[1] = 0.0;
// 	deviceInfo->distortionK[2] = 0.0;
// 	deviceInfo->distortionK[3] = 0.0;
// 	deviceInfo->desktopX = 0;
// 	deviceInfo->desktopY = 0;
// 	displayDeviceName.copy(deviceInfo->displayDeviceName, MAX_DESCRIPTION_LENGTH);
// 	deviceInfo->displayId = 0;
// 	deviceName.copy(deviceInfo->productName, MAX_DESCRIPTION_LENGTH);
// 	deviceManufacturer.copy(deviceInfo->manufacturer, MAX_DESCRIPTION_LENGTH);
// 	deviceInfo->version = 0;
// }

void DefaultDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
	deviceOrientation->yaw = 0.0;
	deviceOrientation->pitch = 0.0;
	deviceOrientation->roll = 0.0;
}