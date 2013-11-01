/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

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
	instance->SetAccessor(String::NewSymbol("hResolution"), GetHResolution, SetEmpty);
	instance->SetAccessor(String::New("vResolution"), GetVResolution, SetEmpty);
	instance->SetAccessor(String::New("hScreenSize"), GetHScreenSize, SetEmpty);
	instance->SetAccessor(String::New("vScreenSize"), GetVScreenSize, SetEmpty);
	instance->SetAccessor(String::New("vScreenCenter"), GetVScreenCenter, SetEmpty);
	instance->SetAccessor(String::New("eyetoScreenDistance"), GetEyeToScreenDistance, SetEmpty);
	instance->SetAccessor(String::New("lensSeparationDistance"), GetLensSeparationDistance, SetEmpty);
	instance->SetAccessor(String::New("interpuillaryDistance"), GetInterpuillaryDistance, SetEmpty);
	instance->SetAccessor(String::New("distortionK"), GetDistortionK, SetEmpty);
	instance->SetAccessor(String::New("desktopX"), GetDesktopX, SetEmpty);
	instance->SetAccessor(String::New("desktopY"), GetDesktopY, SetEmpty);
	instance->SetAccessor(String::New("displayDeviceName"), GetDisplayDeviceName, SetEmpty);
	instance->SetAccessor(String::New("displayId"), GetDisplayId, SetEmpty);
	instance->SetAccessor(String::New("productName"), GetProductName, SetEmpty);
	instance->SetAccessor(String::New("manufacturer"), GetManufacturer, SetEmpty);
	instance->SetAccessor(String::New("version"), GetVersion, SetEmpty);

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("HMDDeviceInfo"), constructor);
}

Handle<Value> HMDDeviceInfoWrap::New(const Arguments& args) {
  HandleScope scope;

  HMDDeviceInfoWrap* w = new HMDDeviceInfoWrap();
  w->Wrap(args.This());

  return args.This();
}

Handle<Value> HMDDeviceInfoWrap::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

HMDDeviceInfo* HMDDeviceInfoWrap::GetWrapped() {
	return this->_hmdDeviceInfo;
}

void HMDDeviceInfoWrap::SetEmpty(Local<String> property, Local<Value> value, const AccessorInfo& info) {
}

Handle<Value> HMDDeviceInfoWrap::GetHResolution(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->hResolution));
}

Handle<Value> HMDDeviceInfoWrap::GetVResolution(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->vResolution));
}

Handle<Value> HMDDeviceInfoWrap::GetHScreenSize(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->hScreenSize));
}

Handle<Value> HMDDeviceInfoWrap::GetVScreenSize(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->vScreenSize));
}

Handle<Value> HMDDeviceInfoWrap::GetVScreenCenter(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Number::New(hmdDeviceInfo->vScreenCenter));
}

Handle<Value> HMDDeviceInfoWrap::GetEyeToScreenDistance(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Number::New(hmdDeviceInfo->eyetoScreenDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetLensSeparationDistance(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Number::New(hmdDeviceInfo->lensSeparationDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetInterpuillaryDistance(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Number::New(hmdDeviceInfo->interpuillaryDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetDistortionK(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	Local<Array> array = Array::New(4);

	array->Set(0, Number::New(hmdDeviceInfo->distortionK[0]));
	array->Set(1, Number::New(hmdDeviceInfo->distortionK[1]));
	array->Set(2, Number::New(hmdDeviceInfo->distortionK[2]));
	array->Set(3, Number::New(hmdDeviceInfo->distortionK[3]));

	return scope.Close(array);
}

Handle<Value> HMDDeviceInfoWrap::GetDesktopX(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Integer::New(hmdDeviceInfo->desktopX));
}

Handle<Value> HMDDeviceInfoWrap::GetDesktopY(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Integer::New(hmdDeviceInfo->desktopY));
}

Handle<Value> HMDDeviceInfoWrap::GetDisplayDeviceName(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(String::New(hmdDeviceInfo->displayDeviceName));
}

Handle<Value> HMDDeviceInfoWrap::GetDisplayId(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Integer::New(hmdDeviceInfo->displayId));
}

Handle<Value> HMDDeviceInfoWrap::GetProductName(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(String::New(hmdDeviceInfo->productName));
}

Handle<Value> HMDDeviceInfoWrap::GetManufacturer(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(String::New(hmdDeviceInfo->manufacturer));
}

Handle<Value> HMDDeviceInfoWrap::GetVersion(Local<String> property, const AccessorInfo &info) {
	HandleScope scope;
	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(info.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
	
	return scope.Close(Integer::New(hmdDeviceInfo->version));
}