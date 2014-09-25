/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include "HMDDeviceQuat.h"

HMDDeviceQuat::HMDDeviceQuat() {
}

HMDDeviceQuat::~HMDDeviceQuat() {
}

void HMDDeviceQuat::setQuat(float w, float x, float y, float z) {
    this->_w = w;
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

float HMDDeviceQuat::getW() const {
    return this->_w;
}

float HMDDeviceQuat::getX() const {
    return this->_x;
}

float HMDDeviceQuat::getY() const {
    return this->_y;
}

float HMDDeviceQuat::getZ() const {
    return this->_z;
}

HMDDeviceQuat& HMDDeviceQuat::operator= (const HMDDeviceQuat &deviceQuat) {
    this->setQuat(deviceQuat.getW(), deviceQuat.getX(), deviceQuat.getY(), deviceQuat.getZ());

    return *this;
}
