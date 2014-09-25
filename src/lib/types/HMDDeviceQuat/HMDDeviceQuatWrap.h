/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEQUATWRAP_H_
#define SRC_LIB_HMDDEVICEQUATWRAP_H_

#include <node.h>
#include <nan/nan.h>

#include "HMDDeviceQuat.h"

/*! \class HMDDeviceQuatWrap
 * 
 * Node wrapped object class for HMDDeviceQuat.
 */
class HMDDeviceQuatWrap : public node::ObjectWrap {
 private:
    HMDDeviceQuat* _hmdDeviceQuat;

    HMDDeviceQuatWrap();
    ~HMDDeviceQuatWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_GETTER(GetDeviceQuatProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    HMDDeviceQuat* GetWrapped();
};

#endif  // SRC_LIB_HMDDEVICEQUATWRAP_H_
