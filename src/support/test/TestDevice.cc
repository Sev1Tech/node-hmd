/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "TestDevice.h"

const std::string TestDevice::displayDeviceName = "node-hmd test device";
const std::string TestDevice::deviceName = "Test Device";
const std::string TestDevice::deviceManufacturer = "Geocent LLC";

const std::string TestDevice::classToken = "test";

void TestDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("hResolution", 800);
    deviceInfo->insertElement("vResolution", 600);
    deviceInfo->insertElement("hScreenSize", 0.8);
    deviceInfo->insertElement("vScreenSize", 0.64);
    deviceInfo->insertElement("vScreenCenter", 300);
    deviceInfo->insertElement("eyetoScreenDistance", 0.01);
    deviceInfo->insertElement("lensSeparationDistance", 0.02);
    deviceInfo->insertElement("interpuillaryDistance", 0.025);
    float distortionK[] = {1.1, 2.2, 3.3, 4.4};
    deviceInfo->insertElement("distortionK", distortionK, 4);
    deviceInfo->insertElement("desktopX", 1920);
    deviceInfo->insertElement("desktopY", 1080);
    deviceInfo->insertElement("displayDeviceName", displayDeviceName);
    deviceInfo->insertElement("displayId", 1234567890);
    deviceInfo->insertElement("productName", deviceName);
    deviceInfo->insertElement("manufacturer", deviceManufacturer);
    deviceInfo->insertElement("version", 5);
}

void TestDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    deviceOrientation->yaw = 0.75;
    deviceOrientation->pitch = 1.28;
    deviceOrientation->roll = 2.33;
}
