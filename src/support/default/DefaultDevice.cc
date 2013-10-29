#include <iostream>
#include <string>

#include "DefaultDevice.h"

const std::string DefaultDevice::deviceName = "Default Device";
const std::string DefaultDevice::deviceManufacturer = "Geocent LLC";

void DefaultDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
	deviceName.copy(deviceInfo->productName, 32);
	deviceManufacturer.copy(deviceInfo->manufacturer, 32);
}