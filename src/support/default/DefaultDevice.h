/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef DEFAULTDEVICE_H
#define DEFAULTDEVICE_H

#include <iostream>
#include <string>

#include "HMDDevice.h"

class DefaultDevice : public HMDDevice {
	private:
		static const std::string displayDeviceName;
		static const std::string deviceName;
		static const std::string deviceManufacturer;
	public:
		void getDeviceInfo(HMDDeviceInfo* deviceInfo);
		void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
};

#endif