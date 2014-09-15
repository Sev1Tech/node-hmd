/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "HMDDeviceInfo.h"
#include "HMDDeviceInfoWrap.h"

Persistent<Function> HMDDeviceInfoWrap::constructor;

HMDDeviceInfoWrap::HMDDeviceInfoWrap() {
	this->_hmdDeviceInfo = new HMDDeviceInfo;
}

HMDDeviceInfoWrap::~HMDDeviceInfoWrap() {
	delete this->_hmdDeviceInfo;
}

void HMDDeviceInfoWrap::Initialize(Handle<Object> target) {
	Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
	tpl->SetClassName(NanNew<String>("HMDDeviceInfo"));

	Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
	instance->SetInternalFieldCount(1);
	instance->SetAccessor(NanNew<String>("hResolution"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("vResolution"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("hScreenSize"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("vScreenSize"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("vScreenCenter"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("eyetoScreenDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("lensSeparationDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("interpuillaryDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("distortionK"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("desktopX"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("desktopY"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("displayDeviceName"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("displayId"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("productName"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("manufacturer"), GetDeviceInfoProperty);
	instance->SetAccessor(NanNew<String>("version"), GetDeviceInfoProperty);

	NanAssignPersistent<Function>(constructor, tpl->GetFunction());
	target->Set(NanNew<String>("HMDDeviceInfo"), constructor);
}

NAN_METHOD(HMDDeviceInfoWrap::New) {
  HandleScope scope;

  if (args.IsConstructCall()) {
    HMDDeviceInfoWrap* w = new HMDDeviceInfoWrap();
    w->Wrap(args.This());
    NanReturnValue(args.This());
  }
  else {
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    NanReturnValue(constructor->NewInstance(argc, argv));
  }
}

HMDDeviceInfo* HMDDeviceInfoWrap::GetWrapped() {
	return this->_hmdDeviceInfo;
}

NAN_GETTER(HMDDeviceInfoWrap::GetDeviceInfoProperty) {
	NanScope();

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	std::string propertyString(*NanAsciiString(property));

  	if(propertyString == "hResolution") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->hResolution));
  	}
  	else if(propertyString == "vResolution") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->vResolution));
  	}
  	else if(propertyString == "hScreenSize") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->hScreenSize));
  	}
  	else if(propertyString == "vScreenSize") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->vScreenSize));
  	}
  	else if(propertyString == "vScreenCenter") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->vScreenCenter));
  	}
  	else if(propertyString == "eyetoScreenDistance") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->eyetoScreenDistance));
  	}
  	else if(propertyString == "lensSeparationDistance") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->lensSeparationDistance));
  	}
  	else if(propertyString == "interpuillaryDistance") {
  		NanReturnValue(NanNew<Number>(hmdDeviceInfo->interpuillaryDistance));
  	}
  	else if(propertyString == "distortionK") {
  		Local<Array> array = NanNew<Array>(4);

  		array->Set(0, NanNew<Number>(hmdDeviceInfo->distortionK[0]));
  		array->Set(1, NanNew<Number>(hmdDeviceInfo->distortionK[1]));
  		array->Set(2, NanNew<Number>(hmdDeviceInfo->distortionK[2]));
  		array->Set(3, NanNew<Number>(hmdDeviceInfo->distortionK[3]));

  		NanReturnValue(array);
  	}
  	else if(propertyString == "desktopX") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->desktopX));
  	}
  	else if(propertyString == "desktopY") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->desktopY));
  	}
  	else if(propertyString == "displayDeviceName") {
  		NanReturnValue(NanNew<String>(hmdDeviceInfo->displayDeviceName));
  	}
  	else if(propertyString == "displayId") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->displayId));
  	}
  	else if(propertyString == "productName") {
  		NanReturnValue(NanNew<String>(hmdDeviceInfo->productName));
  	}
  	else if(propertyString == "manufacturer") {
  		NanReturnValue(NanNew<String>(hmdDeviceInfo->manufacturer));
  	}
  	else if(propertyString == "version") {
  		NanReturnValue(NanNew<Integer>(hmdDeviceInfo->version));
  	}
  	else {
  		NanReturnValue(NanNew<String>(""));
  	}
}
