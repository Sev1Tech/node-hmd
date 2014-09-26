/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDeviceOrientation.h"

HMDDeviceOrientation::HMDDeviceOrientation() : _yaw(0.0f), _pitch(0.0f), _roll(0.0f) {
}

HMDDeviceOrientation::~HMDDeviceOrientation() {
}

void HMDDeviceOrientation::setOrientation(float yaw, float pitch, float roll) {
    this->_yaw = yaw;
    this->_pitch = pitch;
    this->_roll = roll;
}

void HMDDeviceOrientation::setOrientation(HMDDeviceOrientation deviceOrientation) {
    this->setOrientation(deviceOrientation.getYaw(), deviceOrientation.getPitch(), deviceOrientation.getRoll());
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
    this->setOrientation(deviceOrientation);

    return *this;
}
