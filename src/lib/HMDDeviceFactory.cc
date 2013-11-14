/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <list>
#include <string>

#include "HMDDevice.h"
#include "HMDDeviceFactory.h"

#include "DefaultDevice.h"
#include "OculusRiftDevice.h"
#include "TestDevice.h"

std::list<std::string> HMDDeviceFactory::getSupportedDevices() {
	std::list<std::string> devices;

	devices.push_back(DefaultDevice::classToken);
	devices.push_back(OculusRiftDevice::classToken);

	return devices;
}

HMDDevice* HMDDeviceFactory::getInstance(const char* token) {
	if(DefaultDevice::classToken.compare(token) == 0) {
		return new DefaultDevice();
	}
	else if(OculusRiftDevice::classToken.compare(token) == 0) {
		return new OculusRiftDevice();
	}
	else if(TestDevice::classToken.compare(token) == 0) {
		return new TestDevice();
	}
	else {
		return NULL;
	}
}