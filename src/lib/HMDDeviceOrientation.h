/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEORIENTATION_H
#define HMDDEVICEORIENTATION_H

class HMDDeviceOrientation {
	public:
		float yaw;
		float pitch;
		float roll;

		HMDDeviceOrientation();
		~HMDDeviceOrientation();
		
		HMDDeviceOrientation& operator= (const HMDDeviceOrientation &deviceOrientation);

};

#endif