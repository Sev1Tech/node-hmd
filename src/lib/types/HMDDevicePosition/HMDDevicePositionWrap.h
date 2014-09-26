/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITIONWRAP_H_
#define SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITIONWRAP_H_

#include <node.h>
#include <nan/nan.h>

#include "HMDDevicePosition.h"

/*! \class HMDDevicePositionWrap
 * 
 * Node wrapped object class for HMDDevicePosition.
 */
class HMDDevicePositionWrap : public node::ObjectWrap {
 private:
    HMDDevicePosition* _hmdDevicePosition;

    HMDDevicePositionWrap();
    ~HMDDevicePositionWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_GETTER(GetDevicePositionProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    HMDDevicePosition* GetWrapped();
};

#endif  // SRC_LIB_TYPES_HMDDEVICEPOSITION_HMDDEVICEPOSITIONWRAP_H_
