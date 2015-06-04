/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <TestDevice.h>

#include <HMDDeviceInfoElement.h>
#include <OvrFovPort.h>
#include <OvrSizei.h>
#include <OvrVector2i.h>

#include <string>

const std::string TestDevice::displayDeviceName = "node-hmd test device";
const std::string TestDevice::deviceName = "Test Device";
const std::string TestDevice::deviceManufacturer = "Geocent LLC";

const std::string TestDevice::classToken = "test";

void TestDevice::initializeModule(v8::Handle<v8::Object> exports) {
}

void TestDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
    deviceInfo->insertElement("hResolution", new InfoTypeUInt(800));
    deviceInfo->insertElement("vResolution", new InfoTypeUInt(600));
    deviceInfo->insertElement("hScreenSize", new InfoTypeFloat(0.8f));
    deviceInfo->insertElement("vScreenSize", new InfoTypeFloat(0.64f));
    deviceInfo->insertElement("vScreenCenter", new InfoTypeFloat(300));
    deviceInfo->insertElement("eyetoScreenDistance", new InfoTypeFloat(0.01f));
    deviceInfo->insertElement("lensSeparationDistance", new InfoTypeFloat(0.02f));
    deviceInfo->insertElement("interpuillaryDistance", new InfoTypeFloat(0.025f));
    deviceInfo->insertElement("distortionK", new InfoTypeArray<double>(4, 1.1, 2.2, 3.3, 4.4));
    deviceInfo->insertElement("desktopX", new InfoTypeInt(1920));
    deviceInfo->insertElement("desktopY", new InfoTypeInt(1080));
    deviceInfo->insertElement("displayDeviceName", new InfoTypeString(displayDeviceName));
    deviceInfo->insertElement("displayId", new InfoTypeLong(1234567890));
    deviceInfo->insertElement("productName", new InfoTypeString(deviceName));
    deviceInfo->insertElement("manufacturer", new InfoTypeString(deviceManufacturer));
    deviceInfo->insertElement("version", new InfoTypeUInt(5));

    deviceInfo->insertElement("mixedData", new InfoTypeArray<HMDDeviceInfoElement *>(2, new InfoTypeShort(42), new InfoTypeString("test token")));


    // Oculus Rift specific device information types test
    OvrFovPort* ovrFovPortTest[2];
    ovrFovPort testOvrFovPort = { 2.1, 4.3, 6.5, 8.7 };
    ovrFovPortTest[0] = new OvrFovPort(testOvrFovPort);
    ovrFovPortTest[1] = new OvrFovPort(testOvrFovPort);
    deviceInfo->insertElement("ovrFovPort", new InfoTypeArray<HMDDeviceInfoElement *>(reinterpret_cast<HMDDeviceInfoElement **>(ovrFovPortTest), 2));

    ovrSizei testOvrSizei = { 44, 55 };
    deviceInfo->insertElement("ovrSizei", new OvrSizei(testOvrSizei));

    ovrVector2i testOvrVector2i = { 787, 989 };
    deviceInfo->insertElement("ovrVector2i", new OvrVector2i(testOvrVector2i));
}

void TestDevice::getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) {
    deviceOrientation->setOrientation(0.75f, 1.28f, 2.33f);
}

void TestDevice::getDevicePosition(HMDDevicePosition* devicePosition) {
    devicePosition->setPosition(1.2f, 3.4f, 5.6f);
}

void TestDevice::getDeviceQuat(HMDDeviceQuat* deviceQuat) {
    deviceQuat->setQuat(0.11f, 0.22f, 0.33f, 0.44f);
}
