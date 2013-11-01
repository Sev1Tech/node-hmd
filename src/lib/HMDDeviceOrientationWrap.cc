/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

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
	instance->SetAccessor(String::NewSymbol("yaw"), GetYaw, SetEmpty);
	instance->SetAccessor(String::NewSymbol("pitch"), GetPitch, SetEmpty);
	instance->SetAccessor(String::NewSymbol("roll"), GetRoll, SetEmpty);

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

void HMDDeviceOrientationWrap::SetEmpty(Local<String> property, Local<Value> value, const AccessorInfo& info) {
}

Handle<Value> HMDDeviceOrientationWrap::GetYaw(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(info.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->yaw));
}

Handle<Value> HMDDeviceOrientationWrap::GetPitch(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(info.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->pitch));
}

Handle<Value> HMDDeviceOrientationWrap::GetRoll(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(info.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->roll));
}