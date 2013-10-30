/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEINFO_H
#define HMDDEVICEINFO_H

#define MAX_DESCRIPTION_LENGTH 32

class HMDDeviceInfo {
	public:
		unsigned int hResolution;
		unsigned int vResolution;
		float hScreenSize;
		float vScreenSize;
		float vScreenCenter;
		float eyetoScreenDistance;
		float lensSeparationDistance;
		float interpuillaryDistance;
		float distortionK[4];
		int desktopX;
		int desktopY;
		char displayDeviceName[MAX_DESCRIPTION_LENGTH];
		long displayId;
		char productName[MAX_DESCRIPTION_LENGTH];
		char manufacturer[MAX_DESCRIPTION_LENGTH];
		unsigned int version;

		HMDDeviceInfo();
		~HMDDeviceInfo();
};

#endif