/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICE_H_
#define SRC_LIB_HMDDEVICE_H_

#include <string>

#include "HMDDeviceInfo.h"
#include "HMDDeviceOrientation.h"

/*! \class HMDDevice
 * 
 * Base HMD device from which all supported devices extend. 
 */
class HMDDevice {
 public:
    static const std::string classToken;

    virtual ~HMDDevice();
    virtual void getDeviceInfo(HMDDeviceInfo* deviceInfo) = 0;
    virtual void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation) = 0;
};

#endif  // SRC_LIB_HMDDEVICE_H_
