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
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	tpl->PrototypeTemplate()->Set(String::NewSymbol("yaw"), FunctionTemplate::New(GetYaw)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("pitch"), FunctionTemplate::New(GetPitch)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("roll"), FunctionTemplate::New(GetRoll)->GetFunction());

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

Handle<Value> HMDDeviceOrientationWrap::GetYaw(const Arguments& args) {
	HandleScope scope;

	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(args.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->yaw));
}

Handle<Value> HMDDeviceOrientationWrap::GetPitch(const Arguments& args) {
	HandleScope scope;

	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(args.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->pitch));
}

Handle<Value> HMDDeviceOrientationWrap::GetRoll(const Arguments& args) {
	HandleScope scope;

	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(args.This());
	HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceOrientation->roll));
}