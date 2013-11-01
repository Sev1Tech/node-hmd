/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */
#include <string>
 
#include "HMDDeviceOrientation.h"
#include "HMDDeviceOrientationWrap.h"

Persistent<Function> HMDDeviceOrientationWrap::constructor;

HMDDeviceOrientationWrap::HMDDeviceOrientationWrap() {
	this->_hmdDeviceOrientation = new HMDDeviceOrientation;
}

HMDDeviceOrientationWrap::~HMDDeviceOrientationWrap() {
	delete this->_hmdDeviceOrientation;
}

void HMDDeviceOrientationWrap::Initialize(Handle<Object> target) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("HMDDeviceOrientation"));

	Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
	instance->SetInternalFieldCount(1);
	instance->SetAccessor(String::NewSymbol("yaw"), GetDeviceOrientationProperty);
	instance->SetAccessor(String::NewSymbol("pitch"), GetDeviceOrientationProperty);
	instance->SetAccessor(String::NewSymbol("roll"), GetDeviceOrientationProperty);

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("HMDDeviceOrientation"), constructor);
}

Handle<Value> HMDDeviceOrientationWrap::New(const Arguments& args) {
  HandleScope scope;

  HMDDeviceOrientationWrap* w = new HMDDeviceOrientationWrap();
  w->Wrap(args.This());

  return args.This();
}

Handle<Value> HMDDeviceOrientationWrap::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

HMDDeviceOrientation* HMDDeviceOrientationWrap::GetWrapped() {
	return this->_hmdDeviceOrientation;
}

Handle<Value> HMDDeviceOrientationWrap::GetDeviceOrientationProperty(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(info.This());
	HMDDeviceOrientation* hmdDeviceInfo = w->GetWrapped();

	String::AsciiValue propertyAscii(property);
	std::string propertyString(*propertyAscii);

  	if(propertyString == "yaw") {
  		return scope.Close(Number::New(hmdDeviceInfo->yaw));
  	}
  	if(propertyString == "pitch") {
  		return scope.Close(Number::New(hmdDeviceInfo->pitch));
  	}
  	if(propertyString == "roll") {
  		return scope.Close(Number::New(hmdDeviceInfo->roll));
  	}
  	else {
  		return scope.Close(Number::New(0.0));
  	}
}
