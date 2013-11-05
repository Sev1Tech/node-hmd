/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEINFOWRAP_H
#define HMDDEVICEINFOWRAP_H

#include <node.h>

#include "HMDDevice.h"
using namespace v8;

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
    static Handle<Value> GetDeviceInfoProperty(Local<String> property, const AccessorInfo &info);

	public:
    static void Initialize(v8::Handle<v8::Object> target);
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    HMDDeviceInfo* GetWrapped();
};

#endif