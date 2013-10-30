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

      static Handle<Value> GetHResolution(const Arguments& args);
      static Handle<Value> GetVResolution(const Arguments& args);
      static Handle<Value> GetHScreenSize(const Arguments& args);
      static Handle<Value> GetVScreenSize(const Arguments& args);
      static Handle<Value> GetVScreenCenter(const Arguments& args);
      static Handle<Value> GetEyeToScreenDistance(const Arguments& args);
      static Handle<Value> GetLensSeparationDistance(const Arguments& args);
      static Handle<Value> GetInterpuillaryDistance(const Arguments& args);
      static Handle<Value> GetDistortionK(const Arguments& args);
      static Handle<Value> GetDesktopX(const Arguments& args);
      static Handle<Value> GetDesktopY(const Arguments& args);
      static Handle<Value> GetDisplayDeviceName(const Arguments& args);
      static Handle<Value> GetDisplayId(const Arguments& args);
  		static Handle<Value> GetProductName(const Arguments& args);
      static Handle<Value> GetManufacturer(const Arguments& args);
      static Handle<Value> GetVersion(const Arguments& args);
	private:
  		HMDDeviceInfoWrap();
  		~HMDDeviceInfoWrap();
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		HMDDeviceInfo* _hmdDeviceInfo;
};

#endif