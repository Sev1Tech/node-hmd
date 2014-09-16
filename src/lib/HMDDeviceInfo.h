/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEINFO_H_
#define SRC_LIB_HMDDEVICEINFO_H_

#define MAX_DESCRIPTION_LENGTH 32

/*! \class HMDDeviceInfo
 * 
 * Basic property class containg information about the device.
 */
class HMDDeviceInfo {
 public:
    unsigned int hResolution;
    unsigned int vResolution;
    float hScreenSize;
    float vScreenSize;
    float vScreenCenter;
    float eyetoScreenDistance;
    float lensSeparationDistance;
    float interpuillaryDistance;
    float distortionK[4];
    int desktopX;
    int desktopY;
    char displayDeviceName[MAX_DESCRIPTION_LENGTH];
    long displayId;
    char productName[MAX_DESCRIPTION_LENGTH];
    char manufacturer[MAX_DESCRIPTION_LENGTH];
    unsigned int version;

    HMDDeviceInfo();
    ~HMDDeviceInfo();

    HMDDeviceInfo& operator= (const HMDDeviceInfo &deviceInfo);
};

#endif  // SRC_LIB_HMDDEVICEINFO_H_
