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

      static void SetEmpty(Local<String> property, Local<Value> value, const AccessorInfo& info);
      static Handle<Value> GetHResolution(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetVResolution(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetHScreenSize(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetVScreenSize(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetVScreenCenter(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetEyeToScreenDistance(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetLensSeparationDistance(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetInterpuillaryDistance(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetDistortionK(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetDesktopX(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetDesktopY(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetDisplayDeviceName(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetDisplayId(Local<String> property, const AccessorInfo &info);
  		static Handle<Value> GetProductName(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetManufacturer(Local<String> property, const AccessorInfo &info);
      static Handle<Value> GetVersion(Local<String> property, const AccessorInfo &info);
	private:
  		HMDDeviceInfoWrap();
  		~HMDDeviceInfoWrap();
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		HMDDeviceInfo* _hmdDeviceInfo;
};

#endif