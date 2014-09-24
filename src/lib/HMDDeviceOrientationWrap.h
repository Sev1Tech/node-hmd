/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDDEVICEORIENTATIONWRAP_H_
#define SRC_LIB_HMDDEVICEORIENTATIONWRAP_H_

#include <node.h>
#include <nan/nan.h>

#include "HMDDeviceOrientation.h"

/*! \class HMDDeviceOrientationWrap
 * 
 * Node wrapped object class for HMDDeviceOrientation.
 */
class HMDDeviceOrientationWrap : public node::ObjectWrap {
 private:
    HMDDeviceOrientation* _hmdDeviceOrientation;

    HMDDeviceOrientationWrap();
    ~HMDDeviceOrientationWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_GETTER(GetDeviceOrientationProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    HMDDeviceOrientation* GetWrapped();
};

#endif  // SRC_LIB_HMDDEVICEORIENTATIONWRAP_H_
