/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEORIENTATIONWRAP_H
#define HMDDEVICEORIENTATIONWRAP_H

#include <node.h>

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
    static v8::Persistent<v8::Function> constructor;
    static Handle<Value> GetDeviceOrientationProperty(Local<String> property, const AccessorInfo &info);

	public:
  	static void Initialize(v8::Handle<v8::Object> target);
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
		HMDDeviceOrientation* GetWrapped();
};

#endif