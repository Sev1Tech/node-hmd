#ifndef DEFAULTDEVICE_H
#define DEFAULTDEVICE_H

#include <iostream>
#include <string>

#include "HMDDevice.h"

class DefaultDevice : public HMDDevice {
	private:
		static const std::string deviceName;
		static const std::string deviceManufacturer;
	public:
		void getDeviceInfo(HMDDeviceInfo* deviceInfo);
};

#endif