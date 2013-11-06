/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICE_H
#define HMDDEVICE_H

#include <string>
 
#include "HMDDeviceInfo.h"
#include "HMDDeviceOrientation.h"

/*! \class HMDDevice
 * 
 * Base HMD device from which all supported devices extend. 
 */
class HMDDevice {
	public:
		static const std::string classToken;

		virtual ~HMDDevice();
		virtual void getDeviceInfo(HMDDeviceInfo* deviceInfo);
		virtual void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
};

#endif