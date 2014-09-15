/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEORIENTATIONWRAP_H
#define HMDDEVICEORIENTATIONWRAP_H

#include <node.h>
#include <nan.h>

#include "HMDDeviceOrientation.h"
 
using namespace v8;

/*! \class HMDDeviceOrientationWrap
 * 
 * Node wrapped object class for HMDDeviceOrientation.
 */
class HMDDeviceOrientationWrap : public node::ObjectWrap {
  private:
    HMDDeviceOrientation* _hmdDeviceOrientation;
    
    HMDDeviceOrientationWrap();
    ~HMDDeviceOrientationWrap();
    static Persistent<Function> constructor;
    static NAN_GETTER(GetDeviceOrientationProperty);

	public:
  	static void Initialize(Handle<v8::Object> target);
    static NAN_METHOD(New);
		HMDDeviceOrientation* GetWrapped();
};

#endif