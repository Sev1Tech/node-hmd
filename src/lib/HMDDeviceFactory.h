/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEFACTORY_H
#define HMDDEVICEFACTORY_H

#include "HMDDevice.h"
#include "HMDDeviceType.h"

class HMDDeviceFactory {
	public:
		static HMDDevice* getInstance(HMDDeviceType deviceType);
};

#endif