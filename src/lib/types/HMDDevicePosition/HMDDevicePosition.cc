/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDevicePosition.h"

HMDDevicePosition::HMDDevicePosition() : _x(0.0f), _y(0.0f), _z(0.0f) {
}

HMDDevicePosition::~HMDDevicePosition() {
}

void HMDDevicePosition::setPosition(float x, float y, float z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

void HMDDevicePosition::setPosition(HMDDevicePosition devicePosition) {
    this->setPosition(devicePosition.getX(), devicePosition.getY(), devicePosition.getZ());
}

float HMDDevicePosition::getX() const {
    return this->_x;
}

float HMDDevicePosition::getY() const {
    return this->_y;
}

float HMDDevicePosition::getZ() const {
    return this->_z;
}

HMDDevicePosition& HMDDevicePosition::operator= (const HMDDevicePosition &devicePosition) {
    this->setPosition(devicePosition);

    return *this;
}
