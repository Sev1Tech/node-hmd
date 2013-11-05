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
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("HMDDeviceInfo"));

	Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
	instance->SetInternalFieldCount(1);
	instance->SetAccessor(String::NewSymbol("hResolution"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("vResolution"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("hScreenSize"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("vScreenSize"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("vScreenCenter"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("eyetoScreenDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("lensSeparationDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("interpuillaryDistance"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("distortionK"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("desktopX"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("desktopY"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("displayDeviceName"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("displayId"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("productName"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("manufacturer"), GetDeviceInfoProperty);
	instance->SetAccessor(String::New("version"), GetDeviceInfoProperty);

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("HMDDeviceInfo"), constructor);
}

Handle<Value> HMDDeviceInfoWrap::New(const Arguments& args) {
  HandleScope scope;

  if (args.IsConstructCall()) {
    HMDDeviceInfoWrap* w = new HMDDeviceInfoWrap();
    w->Wrap(args.This());
    return args.This();
  }
  else {
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    return scope.Close(constructor->NewInstance(argc, argv));
  }
}

HMDDeviceInfo* HMDDeviceInfoWrap::GetWrapped() {
	return this->_hmdDeviceInfo;
}

Handle<Value> HMDDeviceInfoWrap::GetDeviceInfoProperty(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	String::AsciiValue propertyAscii(property);
	std::string propertyString(*propertyAscii);

  	if(propertyString == "hResolution") {
  		return scope.Close(Integer::New(hmdDeviceInfo->hResolution));
  	}
  	else if(propertyString == "vResolution") {
  		return scope.Close(Integer::New(hmdDeviceInfo->vResolution));
  	}
  	else if(propertyString == "hScreenSize") {
  		return scope.Close(Number::New(hmdDeviceInfo->hScreenSize));
  	}
  	else if(propertyString == "vScreenSize") {
  		return scope.Close(Number::New(hmdDeviceInfo->vScreenSize));
  	}
  	else if(propertyString == "vScreenCenter") {
  		return scope.Close(Number::New(hmdDeviceInfo->vScreenCenter));
  	}
  	else if(propertyString == "eyetoScreenDistance") {
  		return scope.Close(Number::New(hmdDeviceInfo->eyetoScreenDistance));
  	}
  	else if(propertyString == "lensSeparationDistance") {
  		return scope.Close(Number::New(hmdDeviceInfo->lensSeparationDistance));
  	}
  	else if(propertyString == "interpuillaryDistance") {
  		return scope.Close(Number::New(hmdDeviceInfo->interpuillaryDistance));
  	}
  	else if(propertyString == "distortionK") {
		Local<Array> array = Array::New(4);

		array->Set(0, Number::New(hmdDeviceInfo->distortionK[0]));
		array->Set(1, Number::New(hmdDeviceInfo->distortionK[1]));
		array->Set(2, Number::New(hmdDeviceInfo->distortionK[2]));
		array->Set(3, Number::New(hmdDeviceInfo->distortionK[3]));

		return scope.Close(array);
  	}
  	else if(propertyString == "desktopX") {
  		return scope.Close(Integer::New(hmdDeviceInfo->desktopX));
  	}
  	else if(propertyString == "desktopY") {
  		return scope.Close(Integer::New(hmdDeviceInfo->desktopY));
  	}
  	else if(propertyString == "displayDeviceName") {
  		return scope.Close(String::New(hmdDeviceInfo->displayDeviceName));
  	}
  	else if(propertyString == "displayId") {
  		return scope.Close(Integer::New(hmdDeviceInfo->displayId));
  	}
  	else if(propertyString == "productName") {
  		return scope.Close(String::New(hmdDeviceInfo->productName));
  	}
  	else if(propertyString == "manufacturer") {
  		return scope.Close(String::New(hmdDeviceInfo->manufacturer));
  	}
  	else if(propertyString == "version") {
  		return scope.Close(Integer::New(hmdDeviceInfo->version));
  	}
  	else {
  		return scope.Close(String::New(""));
  	}
}
