/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <node.h>
#include <v8.h>

#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDManagerWrap.h"

using namespace v8;

Handle<Value> CreateManager(const Arguments& args) {
	HandleScope scope;
	return scope.Close(HMDManagerWrap::New(args));
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
	HMDDeviceInfoWrap::Initialize(exports);
	HMDDeviceOrientationWrap::Initialize(exports);
	HMDManagerWrap::Initialize(exports);

	exports->Set(String::NewSymbol("createManager"), FunctionTemplate::New(CreateManager)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
