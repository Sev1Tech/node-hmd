/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "TestDevice.h"

#include "HMDDeviceInfoElement.h"
#include "InfoTypeArray.h"
#include "InfoTypePrimitive.h"

const std::string TestDevice::displayDeviceName = "node-hmd test device";
const std::string TestDevice::deviceName = "Test Device";
const std::string TestDevice::deviceManufacturer = "Geocent LLC";

const std::string TestDevice::classToken = "test";

void TestDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("hResolution", new InfoTypeUInt(800));
    deviceInfo->insertElement("vResolution", new InfoTypeUInt(600));
    deviceInfo->insertElement("hScreenSize", new InfoTypeFloat(0.8));
    deviceInfo->insertElement("vScreenSize", new InfoTypeFloat(0.64));
    deviceInfo->insertElement("vScreenCenter", new InfoTypeFloat(300));
    deviceInfo->insertElement("eyetoScreenDistance", new InfoTypeFloat(0.01));
    deviceInfo->insertElement("lensSeparationDistance", new InfoTypeFloat(0.02));
    deviceInfo->insertElement("interpuillaryDistance", new InfoTypeFloat(0.025));
    deviceInfo->insertElement("distortionK", new InfoTypeArray<double>(4, 1.1, 2.2, 3.3, 4.4));
    deviceInfo->insertElement("desktopX", new InfoTypeInt(1920));
    deviceInfo->insertElement("desktopY", new InfoTypeInt(1080));
    deviceInfo->insertElement("displayDeviceName", new InfoTypeString(displayDeviceName));
    deviceInfo->insertElement("displayId", new InfoTypeUInt(1234567890));
    deviceInfo->insertElement("productName", new InfoTypeString(deviceName));
    deviceInfo->insertElement("manufacturer", new InfoTypeString(deviceManufacturer));
    deviceInfo->insertElement("version", new InfoTypeUInt(5));

    deviceInfo->insertElement("mixedData", new InfoTypeArray<HMDDeviceInfoElement *>(2, new InfoTypeShort(42), new InfoTypeString("test token")));
}

void TestDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    deviceOrientation->setOrientation(0.75, 1.28, 2.33);
}

void TestDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    deviceQuat->setQuat(0.11, 0.22, 0.33, 0.44);
}
