/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_H_

#include <nan/nan.h>
#include <node.h>

#include <HMDDeviceInfoElement.h>

#include <map>
#include <stdexcept>
#include <string>

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

/*! \class HMDDeviceInfoWrap
 *
 * Node wrapped object class for HMDDeviceInfo.
 */
class HMDDeviceInfoWrap : public node::ObjectWrap {
 private:
    HMDDeviceInfo* _hmdDeviceInfo;

    HMDDeviceInfoWrap();
    ~HMDDeviceInfoWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetDeviceInfoProperty);
    static NAN_PROPERTY_ENUMERATOR(DeviceInfoPropertyEnumerator);
 public:
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    HMDDeviceInfo* GetWrapped();
};

class ElementNotFoundError : public std::runtime_error {
 public:
    ElementNotFoundError(): runtime_error("Device information element not found.") {}
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_H_
