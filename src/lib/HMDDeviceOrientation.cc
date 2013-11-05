/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDeviceOrientation.h"

HMDDeviceOrientation::HMDDeviceOrientation() {

}

HMDDeviceOrientation::~HMDDeviceOrientation() {

}

HMDDeviceOrientation& HMDDeviceOrientation::operator= (const HMDDeviceOrientation &deviceOrientation) {
	this->yaw = deviceOrientation.yaw;
	this->pitch = deviceOrientation.pitch;
	this->roll = deviceOrientation.roll;
	
	return *this;	
}