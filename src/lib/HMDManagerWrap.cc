/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <node.h>

#include "HMDDeviceFactory.h"
#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDDeviceType.h"
#include "HMDManagerWrap.h"

using namespace v8;

Persistent<Function> HMDManagerWrap::constructor;

HMDManagerWrap::HMDManagerWrap(const Arguments& args) {
	this->_hmdDevice = HMDDeviceFactory::getInstance(DEVICETYPE_DEFAULT); //TODO: Feed the factory.
}

HMDManagerWrap::~HMDManagerWrap() {
	if(_hmdDevice) {
		delete this->_hmdDevice;
	}
}

void HMDManagerWrap::Initialize(Handle<Object> target) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("HMDManager"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceInfo"), FunctionTemplate::New(GetDeviceInfo)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceOrientation"), FunctionTemplate::New(GetDeviceOrientation)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("HMDManager"), constructor);
}

Handle<Value> HMDManagerWrap::New(const Arguments& args) {
	HandleScope scope;

	HMDManagerWrap* w = new HMDManagerWrap(args);
	w->Wrap(args.This());

	return args.This();
}

Handle<Value> HMDManagerWrap::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}


HMDDevice* HMDManagerWrap::GetDevice() {
	return this->_hmdDevice;
}

Handle<Value> HMDManagerWrap::GetDeviceInfo(const Arguments& args) {
	HandleScope scope;

	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
	Handle<Value> hmdDeviceInfo = HMDDeviceInfoWrap::NewInstance(args);

	hmdManager->GetDevice()->getDeviceInfo(ObjectWrap::Unwrap<HMDDeviceInfoWrap>(hmdDeviceInfo->ToObject())->GetWrapped());

	return scope.Close(hmdDeviceInfo);
}

Handle<Value> HMDManagerWrap::GetDeviceOrientation(const Arguments& args) {
	HandleScope scope;

	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
	Handle<Value> hmdDeviceOrientation = HMDDeviceOrientationWrap::NewInstance(args);

	hmdManager->GetDevice()->getDeviceOrientation(ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(hmdDeviceOrientation->ToObject())->GetWrapped());

	return scope.Close(hmdDeviceOrientation);
}