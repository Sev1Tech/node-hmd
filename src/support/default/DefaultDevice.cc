/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "DefaultDevice.h"
#include "InfoTypePrimitive.h"


const std::string DefaultDevice::displayDeviceName = "node-hmd default device";
const std::string DefaultDevice::deviceName = "Default Device";
const std::string DefaultDevice::deviceManufacturer = "Geocent LLC";

const std::string DefaultDevice::classToken = "default";

void DefaultDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("displayDeviceName", new InfoTypeString(displayDeviceName));
    deviceInfo->insertElement("productName", new InfoTypeString(deviceName));
    deviceInfo->insertElement("manufacturer", new InfoTypeString(deviceManufacturer));
    deviceInfo->insertElement("version", new InfoTypeUInt(1));
}

void DefaultDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    deviceOrientation->setOrientation(0.0f, 0.0f, 0.0f);
}

void DefaultDevice::getDevicePosition(HMDDevicePosition* devicePosition) {
    devicePosition->setPosition(0.0f, 0.0f, 0.0f);
}

void DefaultDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    deviceQuat->setQuat(0.0f, 0.0f, 0.0f, 0.0f);
}
