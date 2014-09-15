/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */
#include <string>

#include <node.h>
#include <nan.h>

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
	Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
	tpl->SetClassName(NanNew<String>("HMDDeviceOrientation"));

	Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
	instance->SetInternalFieldCount(1);
	instance->SetAccessor(NanNew<String>("yaw"), GetDeviceOrientationProperty);
	instance->SetAccessor(NanNew<String>("pitch"), GetDeviceOrientationProperty);
	instance->SetAccessor(NanNew<String>("roll"), GetDeviceOrientationProperty);

	NanAssignPersistent<Function>(constructor, tpl->GetFunction());
	target->Set(NanNew<String>("HMDDeviceOrientation"), constructor);
}

NAN_METHOD(HMDDeviceOrientationWrap::New) {
	NanScope();

	if (args.IsConstructCall()) {
		HMDDeviceOrientationWrap* w = new HMDDeviceOrientationWrap();
		w->Wrap(args.This());
		NanReturnValue(args.This());
	}
	else {
		const int argc = 1;
		Local<Value> argv[argc] = { args[0] };
		NanReturnValue(constructor->NewInstance(argc, argv));
	}
}

HMDDeviceOrientation* HMDDeviceOrientationWrap::GetWrapped() {
	return this->_hmdDeviceOrientation;
}

NAN_GETTER(HMDDeviceOrientationWrap::GetDeviceOrientationProperty) {
	NanScope();

	HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(args.This());
	HMDDeviceOrientation* hmdDeviceInfo = w->GetWrapped();

	std::string propertyString(*NanAsciiString(property));

  	if(propertyString == "yaw") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->yaw));
  	}
  	else if(propertyString == "pitch") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->pitch));
  	}
  	else if(propertyString == "roll") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->roll));
  	}
  	else {
  		NanReturnValue(NanNew<Number>(0.0));
  	}
}
