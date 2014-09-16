/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEORIENTATION_H_
#define SRC_LIB_HMDDEVICEORIENTATION_H_

/*! \class HMDDeviceOrientation
 * 
 * Basic property class containg orientation state about the device.
 */
class HMDDeviceOrientation {
 public:
    float yaw;
    float pitch;
    float roll;

    HMDDeviceOrientation();
    ~HMDDeviceOrientation();

    HMDDeviceOrientation& operator= (const HMDDeviceOrientation &deviceOrientation);
};

#endif  // SRC_LIB_HMDDEVICEORIENTATION_H_
