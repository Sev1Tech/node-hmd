/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDevice.h"
#include "HMDDeviceFactory.h"
#include "HMDDeviceType.h"

#include "DefaultDevice.h"

HMDDevice* HMDDeviceFactory::getInstance(HMDDeviceType deviceType) {
	switch(deviceType) {
		case DEVICETYPE_OCULUS_RIFT:
			return 0;
			break;
		default:
			return new DefaultDevice();
			break;
	}
}