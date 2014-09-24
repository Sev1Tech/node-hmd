/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEQUAT_H_
#define SRC_LIB_HMDDEVICEQUAT_H_

/*! \class HMDDeviceOrientation
 * 
 * Basic property class containg quaternion state about the device.
 */
class HMDDeviceQuat {
 public:
    HMDDeviceQuat();
    ~HMDDeviceQuat();

    void setQuat(float w, float x, float y, float z);

    float getW() const;
    float getX() const;
    float getY() const;
    float getZ() const;

    HMDDeviceQuat& operator= (const HMDDeviceQuat &deviceQuat);

 private:
    float w;
    float x;
    float y;
    float z;
};

#endif  // SRC_LIB_HMDDEVICEQUAT_H_
