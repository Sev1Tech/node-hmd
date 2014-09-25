/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <map>
#include <string>
#include <vector>

#include "HMDDeviceInfo.h"


HMDDeviceInfo::HMDDeviceInfo() {
    this->_deviceInformation = std::map<std::string, boost::any >();
}

HMDDeviceInfo::~HMDDeviceInfo() {
}

std::map<std::string, boost::any > HMDDeviceInfo::getDeviceInfo() const {
    return this->_deviceInformation;
}

boost::any HMDDeviceInfo::getElement(std::string name) {
    if (this->_deviceInformation.find(name) != this->_deviceInformation.end()) {
        return this->_deviceInformation[name];
    } else {
        throw ElementNotFoundError();
    }
}

void HMDDeviceInfo::insertElement(std::string name, boost::any element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, int element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, unsigned int element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, float element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, double element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, std::string element) {
    this->_deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, int* elements, int size) {
    std::vector<int> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->_deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, unsigned int* elements, int size) {
    std::vector<unsigned int> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->_deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, float* elements, int size) {
    std::vector<float> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->_deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, double* elements, int size) {
    std::vector<double> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->_deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, std::string* elements, int size) {
    std::vector<std::string> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->_deviceInformation[name] = vector;
}

HMDDeviceInfo& HMDDeviceInfo::operator= (const HMDDeviceInfo &deviceInfo) {
    std::map<std::string, boost::any > deviceInformation = deviceInfo.getDeviceInfo();
    for (std::map<std::string, boost::any>::iterator iter = deviceInformation.begin(); iter != deviceInformation.end(); ++iter) {
        this->insertElement(iter->first, iter->second);
    }

    return *this;
}
