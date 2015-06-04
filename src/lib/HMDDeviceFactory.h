/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEFACTORY_H_
#define SRC_LIB_HMDDEVICEFACTORY_H_

#include <node.h>

#include <HMDDevice.h>

#include <string>
#include <vector>

/*! \class HMDDeviceFactory
 * 
 * Static factory class for generating supported HMDDevices which are defined in the HMDDeviceType enumeration.
 */
class HMDDeviceFactory {
 public:
    static void initializeModule(v8::Handle<v8::Object> exports);

    static std::vector<std::string> getSupportedDevices();
    static HMDDevice* getInstance(const char* token);
};

#endif  // SRC_LIB_HMDDEVICEFACTORY_H_
