/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFO_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFO_H_

#include <boost/any.hpp>
#include <node.h>

#include <map>
#include <stdexcept>
#include <string>

#include "HMDDeviceInfoElement.h"

/*! \class HMDDeviceInfo
 * 
 * Basic property class containg information about the device.
 */
class HMDDeviceInfo {
 private:
    std::map<std::string, HMDDeviceInfoElement*> _deviceInformation;

 public:
    HMDDeviceInfo();
    ~HMDDeviceInfo();

    std::map<std::string, HMDDeviceInfoElement*> getDeviceInfo() const;
    HMDDeviceInfoElement* getElement(std::string name);
    void insertElement(std::string name, HMDDeviceInfoElement* element);
    HMDDeviceInfo& operator= (const HMDDeviceInfo &deviceInfo);
};

class ElementNotFoundError : public std::runtime_error {
 public:
    ElementNotFoundError(): runtime_error("Device information element not found.") {}
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFO_H_
