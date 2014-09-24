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
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

float HMDDeviceQuat::getW() const {
    return this->w;
}

float HMDDeviceQuat::getX() const {
    return this->x;
}

float HMDDeviceQuat::getY() const {
    return this->y;
}

float HMDDeviceQuat::getZ() const {
    return this->z;
}

HMDDeviceQuat& HMDDeviceQuat::operator= (const HMDDeviceQuat &deviceQuat) {
    this->setQuat(deviceQuat.getW(), deviceQuat.getX(), deviceQuat.getY(), deviceQuat.getZ());

    return *this;
}
