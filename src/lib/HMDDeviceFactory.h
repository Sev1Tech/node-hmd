/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEFACTORY_H
#define HMDDEVICEFACTORY_H

#include "HMDDevice.h"
#include "HMDDeviceType.h"

/*! \class HMDDeviceFactory
 * 
 * Static factory class for generating supported HMDDevices which are defined in the HMDDeviceType enumeration.
 */
class HMDDeviceFactory {
	public:
		static HMDDevice* getInstance(HMDDeviceType deviceType);
};

#endif