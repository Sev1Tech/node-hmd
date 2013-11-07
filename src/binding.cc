/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <list>
#include <string>

#include <node.h>
#include <v8.h>

#include "HMDDeviceFactory.h"
#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDManagerWrap.h"

using namespace v8;

Handle<Value> CreateManager(const Arguments& args) {
	HandleScope scope;

	TryCatch trycatch;
	Handle<Value> hmdManager = HMDManagerWrap::New(args);
	if(hmdManager.IsEmpty()) {
		return scope.Close(Undefined());
	}
	else{
		return scope.Close(hmdManager);
	}
}

Handle<Value> GetSupportedDevices(const Arguments& args) {
	HandleScope scope;
	std::list<std::string> supported = HMDDeviceFactory::getSupportedDevices();

	Local<Array> array = Array::New(supported.size());
	int i = 0;

	for (std::list<std::string>::iterator it = supported.begin(); it != supported.end(); it++) {
		array->Set(i++, String::New((*it).c_str()));
	}

	return scope.Close(array);
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
	HMDDeviceInfoWrap::Initialize(exports);
	HMDDeviceOrientationWrap::Initialize(exports);
	HMDManagerWrap::Initialize(exports);

	exports->Set(String::NewSymbol("createManager"), FunctionTemplate::New(CreateManager)->GetFunction());
	exports->Set(String::NewSymbol("getSupportedDevices"), FunctionTemplate::New(GetSupportedDevices)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
