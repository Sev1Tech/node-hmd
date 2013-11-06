/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <list>
#include <string>

#include "HMDDevice.h"
#include "HMDDeviceFactory.h"

#include "DefaultDevice.h"
#include "TestDevice.h"

std::list<std::string> HMDDeviceFactory::getSupportedDevices() {
	std::list<std::string> devices;

	devices.push_back(DefaultDevice::classToken);

	return devices;
}

HMDDevice* HMDDeviceFactory::getInstance(const char* token) {
	if(DefaultDevice::classToken.compare(token) == 0) {
		return new DefaultDevice();
	}
	if(TestDevice::classToken.compare(token) == 0) {
		return new TestDevice();
	}
	else {
		return NULL;
	}
}