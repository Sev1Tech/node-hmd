/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDDeviceFactory.h>

#include <DefaultDevice.h>
#include <HMDDevice.h>
#include <OculusRiftDevice.h>
#include <TestDevice.h>

#include <string>
#include <vector>

void HMDDeviceFactory::initializeModule(v8::Handle<v8::Object> exports) {
    DefaultDevice::initializeModule(exports);
    OculusRiftDevice::initializeModule(exports);
    TestDevice::initializeModule(exports);
}

std::vector<std::string> HMDDeviceFactory::getSupportedDevices() {
    std::vector<std::string> devices;

    devices.push_back(DefaultDevice::classToken);
    devices.push_back(OculusRiftDevice::classToken);

    return devices;
}

HMDDevice* HMDDeviceFactory::getInstance(const char* token) {
    if (DefaultDevice::classToken.compare(token) == 0) {
        return new DefaultDevice();
    } else if (OculusRiftDevice::classToken.compare(token) == 0) {
        return new OculusRiftDevice();
    } else if (TestDevice::classToken.compare(token) == 0) {
        return new TestDevice();
    } else {
        return NULL;
    }
}
