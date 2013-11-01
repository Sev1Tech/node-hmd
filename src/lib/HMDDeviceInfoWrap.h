/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEINFOWRAP_H
#define HMDDEVICEINFOWRAP_H

#include <node.h>

#include "HMDDevice.h"
using namespace v8;

class HMDDeviceInfoWrap : public node::ObjectWrap {
	public:
  		static void Initialize(v8::Handle<v8::Object> target);
  		static Handle<Value> NewInstance(const Arguments& args);
  		HMDDeviceInfo* GetWrapped();

      static Handle<Value> GetDeviceInfoProperty(Local<String> property, const AccessorInfo &info);

	private:
  		HMDDeviceInfoWrap();
  		~HMDDeviceInfoWrap();
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		HMDDeviceInfo* _hmdDeviceInfo;
};

#endif