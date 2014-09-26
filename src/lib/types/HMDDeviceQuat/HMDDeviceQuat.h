/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEQUAT_HMDDEVICEQUAT_H_
#define SRC_LIB_TYPES_HMDDEVICEQUAT_HMDDEVICEQUAT_H_

/*! \class HMDDeviceOrientation
 * 
 * Basic property class containg quaternion state about the device.
 */
class HMDDeviceQuat {
 private:
    float _w;
    float _x;
    float _y;
    float _z;

 public:
    HMDDeviceQuat();
    ~HMDDeviceQuat();

    void setQuat(float w, float x, float y, float z);

    float getW() const;
    float getX() const;
    float getY() const;
    float getZ() const;

    HMDDeviceQuat& operator= (const HMDDeviceQuat &deviceQuat);
};

#endif  // SRC_LIB_TYPES_HMDDEVICEQUAT_HMDDEVICEQUAT_H_
