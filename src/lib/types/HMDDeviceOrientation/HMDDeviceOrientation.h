/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEORIENTATION_HMDDEVICEORIENTATION_H_
#define SRC_LIB_TYPES_HMDDEVICEORIENTATION_HMDDEVICEORIENTATION_H_

/*! \class HMDDeviceOrientation
 * 
 * Basic property class containg orientation state about the device.
 */
class HMDDeviceOrientation {
 protected:
    float _yaw;
    float _pitch;
    float _roll;

 public:
    HMDDeviceOrientation();
    ~HMDDeviceOrientation();

    void setOrientation(float yaw, float pitch, float roll);
    void setOrientation(HMDDeviceOrientation deviceOrientation);

    float getYaw() const;
    float getPitch() const;
    float getRoll() const;

    HMDDeviceOrientation& operator= (const HMDDeviceOrientation &deviceOrientation);
};

#endif  // SRC_LIB_TYPES_HMDDEVICEORIENTATION_HMDDEVICEORIENTATION_H_
