/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOWRAP_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOWRAP_H_

#include <nan/nan.h>
#include <node.h>

#include "HMDDevice.h"

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
    static NAN_GETTER(GetDeviceInfoProperty);
    static NAN_PROPERTY_ENUMERATOR(DeviceInfoPropertyEnumerator);
 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    static v8::Handle<v8::Value> NewInstance();
    HMDDeviceInfo* GetWrapped();
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOWRAP_H_
