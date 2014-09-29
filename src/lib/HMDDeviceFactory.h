/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEFACTORY_H_
#define SRC_LIB_HMDDEVICEFACTORY_H_

#include <string>
#include <vector>

#include "HMDDevice.h"

/*! \class HMDDeviceFactory
 * 
 * Static factory class for generating supported HMDDevices which are defined in the HMDDeviceType enumeration.
 */
class HMDDeviceFactory {
 public:
    static std::vector<std::string> getSupportedDevices();
    static HMDDevice* getInstance(const char* token);
};

#endif  // SRC_LIB_HMDDEVICEFACTORY_H_
