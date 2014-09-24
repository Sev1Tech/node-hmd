/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <map>
#include <string>
#include <vector>

#include "HMDDeviceInfo.h"


HMDDeviceInfo::HMDDeviceInfo() {
    this->deviceInformation = std::map<std::string, boost::any >();
}

HMDDeviceInfo::~HMDDeviceInfo() {
}

void HMDDeviceInfo::insertElement(std::string name, int element) {
    this->deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, unsigned int element) {
    this->deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, float element) {
    this->deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, double element) {
    this->deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, std::string element) {
    this->deviceInformation[name] = element;
}

void HMDDeviceInfo::insertElement(std::string name, int* elements, int size) {
    std::vector<int> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, unsigned int* elements, int size) {
    std::vector<unsigned int> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, float* elements, int size) {
    std::vector<float> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, double* elements, int size) {
    std::vector<double> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->deviceInformation[name] = vector;
}

void HMDDeviceInfo::insertElement(std::string name, std::string* elements, int size) {
    std::vector<std::string> vector;
    for (int i = 0; i < size; i++) {
        vector.push_back(elements[i]);
    }
    this->deviceInformation[name] = vector;
}

boost::any HMDDeviceInfo::getElement(std::string name) {
    if (this->deviceInformation.find(name) != this->deviceInformation.end()) {
        return this->deviceInformation[name];
    } else {
        throw ElementNotFoundError();
    }
}
