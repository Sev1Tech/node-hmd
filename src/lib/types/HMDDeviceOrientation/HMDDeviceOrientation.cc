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
    this->_yaw = yaw;
    this->_pitch = pitch;
    this->_roll = roll;
}

float HMDDeviceOrientation::getYaw() const {
    return this->_yaw;
}

float HMDDeviceOrientation::getPitch() const {
    return this->_pitch;
}

float HMDDeviceOrientation::getRoll() const {
    return this->_roll;
}

HMDDeviceOrientation& HMDDeviceOrientation::operator= (const HMDDeviceOrientation &deviceOrientation) {
    this->setOrientation(deviceOrientation.getYaw(), deviceOrientation.getPitch(), deviceOrientation.getRoll());

    return *this;
}
