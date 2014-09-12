/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef OCULUSRIFTDEVICE_H
#define OCULUSRIFTDEVICE_H

#include <iostream>
#include <string>

#include "HMDDevice.h"
#include "OVR.h"

class OculusRiftDevice : public HMDDevice {
	private:
		ovrHmd hmd;
		// ovrFrameTiming frameTiming;
	public:
		static const std::string classToken;

		OculusRiftDevice();
		~OculusRiftDevice();
		void getDeviceInfo(HMDDeviceInfo* deviceInfo);
		void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
};

#endif