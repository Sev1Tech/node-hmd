/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "TestDevice.h"

#include "InfoTypeArray.h"
#include "InfoTypeNumber.h"
#include "InfoTypeString.h"

const std::string TestDevice::displayDeviceName = "node-hmd test device";
const std::string TestDevice::deviceName = "Test Device";
const std::string TestDevice::deviceManufacturer = "Geocent LLC";

const std::string TestDevice::classToken = "test";

void TestDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("hResolution", new InfoTypeNumber(800));
    deviceInfo->insertElement("vResolution", new InfoTypeNumber(600));
    deviceInfo->insertElement("hScreenSize", new InfoTypeNumber(0.8));
    deviceInfo->insertElement("vScreenSize", new InfoTypeNumber(0.64));
    deviceInfo->insertElement("vScreenCenter", new InfoTypeNumber(300));
    deviceInfo->insertElement("eyetoScreenDistance", new InfoTypeNumber(0.01));
    deviceInfo->insertElement("lensSeparationDistance", new InfoTypeNumber(0.02));
    deviceInfo->insertElement("interpuillaryDistance", new InfoTypeNumber(0.025));
    deviceInfo->insertElement("distortionK", new InfoTypeArray<double>(4, 1.1, 2.2, 3.3, 4.4));
    deviceInfo->insertElement("desktopX", new InfoTypeNumber(1920));
    deviceInfo->insertElement("desktopY", new InfoTypeNumber(1080));
    deviceInfo->insertElement("displayDeviceName", new InfoTypeString(displayDeviceName));
    deviceInfo->insertElement("displayId", new InfoTypeNumber(1234567890));
    deviceInfo->insertElement("productName", new InfoTypeString(deviceName));
    deviceInfo->insertElement("manufacturer", new InfoTypeString(deviceManufacturer));
    deviceInfo->insertElement("hResolution", new InfoTypeNumber(800));
    deviceInfo->insertElement("version", new InfoTypeNumber(5));
}

void TestDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    deviceOrientation->setOrientation(0.75, 1.28, 2.33);
}

void TestDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    deviceQuat->setQuat(0.11, 0.22, 0.33, 0.44);
}
