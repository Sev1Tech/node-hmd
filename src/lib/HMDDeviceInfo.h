/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEINFO_H_
#define SRC_LIB_HMDDEVICEINFO_H_

#define MAX_DESCRIPTION_LENGTH 32

#include <boost/any.hpp>
#include <node.h>

#include <map>
#include <stdexcept>
#include <string>

/*! \class HMDDeviceInfo
 * 
 * Basic property class containg information about the device.
 */
class HMDDeviceInfo {
 private:
    std::map<std::string, boost::any > deviceInformation;
 public:
    HMDDeviceInfo();
    ~HMDDeviceInfo();

    void insertElement(std::string name, int element);
    void insertElement(std::string name, unsigned int element);
    void insertElement(std::string name, float element);
    void insertElement(std::string name, double element);
    void insertElement(std::string name, std::string element);

    void insertElement(std::string name, int* element, int size);
    void insertElement(std::string name, unsigned int* element, int size);
    void insertElement(std::string name, float* element, int size);
    void insertElement(std::string name, double* element, int size);
    void insertElement(std::string name, std::string* element, int size);

    boost::any getElement(std::string name);
};

class ElementNotFoundError : public std::runtime_error {
 public:
    ElementNotFoundError(): runtime_error("Device information element not found.") {}
};

#endif  // SRC_LIB_HMDDEVICEINFO_H_
