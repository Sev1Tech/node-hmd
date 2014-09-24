/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDeviceOrientation.h"

HMDDeviceOrientation::HMDDeviceOrientation() {
}

HMDDeviceOrientation::~HMDDeviceOrientation() {
}

void HMDDeviceOrientation::setOrientation(float yaw, float pitch, float roll) {
    this->yaw = yaw;
    this->pitch = pitch;
    this->roll = roll;
}

float HMDDeviceOrientation::getYaw() const {
    return this->yaw;
}

float HMDDeviceOrientation::getPitch() const {
    return this->pitch;
}

float HMDDeviceOrientation::getRoll() const {
    return this->roll;
}

HMDDeviceOrientation& HMDDeviceOrientation::operator= (const HMDDeviceOrientation &deviceOrientation) {
	this->setOrientation(deviceOrientation.getYaw(), deviceOrientation.getPitch(), deviceOrientation.getRoll());

	return *this;
}