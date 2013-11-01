/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEORIENTATIONWRAP_H
#define HMDDEVICEORIENTATIONWRAP_H

#include <node.h>

#include "HMDDeviceOrientation.h"
 
using namespace v8;

class HMDDeviceOrientationWrap : public node::ObjectWrap {
	public:
  		static void Initialize(v8::Handle<v8::Object> target);
  		static Handle<Value> NewInstance(const Arguments& args);
  		HMDDeviceOrientation* GetWrapped();

      static void SetEmpty(Local<String> property, Local<Value> value, const AccessorInfo& info);
  		static Handle<Value> GetYaw(Local<String> property, const AccessorInfo &info);
  		static Handle<Value> GetPitch(Local<String> property, const AccessorInfo &info);
  		static Handle<Value> GetRoll(Local<String> property, const AccessorInfo &info);
	private:
  		HMDDeviceOrientationWrap();
  		~HMDDeviceOrientationWrap();
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		HMDDeviceOrientation* _hmdDeviceOrientation;
};

#endif