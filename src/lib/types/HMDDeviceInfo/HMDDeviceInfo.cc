/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <map>
#include <string>
#include <vector>

#include "HMDDeviceInfo.h"

HMDDeviceInfo::HMDDeviceInfo() {
    this->_deviceInformation = std::map<std::string, HMDDeviceInfoElement*>();
}

HMDDeviceInfo::~HMDDeviceInfo() {
    for (std::map<std::string, HMDDeviceInfoElement*>::iterator iter = this->_deviceInformation.begin(); iter != this->_deviceInformation.end(); ++iter) {
        delete iter->second;
    }
}

std::map<std::string, HMDDeviceInfoElement*> HMDDeviceInfo::getDeviceInfo() const {
    return this->_deviceInformation;
}

HMDDeviceInfoElement* HMDDeviceInfo::getElement(std::string name) {
    if (this->_deviceInformation.find(name) != this->_deviceInformation.end()) {
        return this->_deviceInformation[name];
    } else {
        throw ElementNotFoundError();
    }
}

void HMDDeviceInfo::insertElement(std::string name, HMDDeviceInfoElement* element) {
    this->_deviceInformation[name] = element;
}

HMDDeviceInfo& HMDDeviceInfo::operator= (const HMDDeviceInfo &deviceInfo) {
    std::map<std::string, HMDDeviceInfoElement*> deviceInformation = deviceInfo.getDeviceInfo();
    for (std::map<std::string, HMDDeviceInfoElement*>::iterator iter = deviceInformation.begin(); iter != deviceInformation.end(); ++iter) {
        this->insertElement(iter->first, iter->second);
    }

    return *this;
}
