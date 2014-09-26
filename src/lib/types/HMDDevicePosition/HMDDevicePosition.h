/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITION_H_
#define SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITION_H_

/*! \class HMDDevicePosition
 * 
 * Basic property class containg position state about the device.
 */
class HMDDevicePosition {
 protected:
    float _x;
    float _y;
    float _z;

 public:
    HMDDevicePosition();
    ~HMDDevicePosition();

    void setPosition(float x, float y, float z);
    void setPosition(HMDDevicePosition deviceOrientation);

    float getX() const;
    float getY() const;
    float getZ() const;

    HMDDevicePosition& operator= (const HMDDevicePosition &devicePosition);
};

#endif  // SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITION_H_
