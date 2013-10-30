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
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	tpl->PrototypeTemplate()->Set(String::NewSymbol("hResolution"), FunctionTemplate::New(GetHResolution)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("vResolution"), FunctionTemplate::New(GetVResolution)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("hScreenSize"), FunctionTemplate::New(GetHScreenSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("vScreenSize"), FunctionTemplate::New(GetVScreenSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("vScreenCenter"), FunctionTemplate::New(GetVScreenCenter)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("eyetoScreenDistance"), FunctionTemplate::New(GetEyeToScreenDistance)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("lensSeparationDistance"), FunctionTemplate::New(GetLensSeparationDistance)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("interpuillaryDistance"), FunctionTemplate::New(GetInterpuillaryDistance)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("distortionK"), FunctionTemplate::New(GetDistortionK)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("desktopX"), FunctionTemplate::New(GetDesktopX)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("desktopY"), FunctionTemplate::New(GetDesktopY)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("displayDeviceName"), FunctionTemplate::New(GetDisplayDeviceName)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("displayId"), FunctionTemplate::New(GetDisplayId)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("productName"), FunctionTemplate::New(GetProductName)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("manufacturer"), FunctionTemplate::New(GetManufacturer)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("version"), FunctionTemplate::New(GetVersion)->GetFunction());

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

Handle<Value> HMDDeviceInfoWrap::GetHResolution(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->hResolution));
}

Handle<Value> HMDDeviceInfoWrap::GetVResolution(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->vResolution));
}

Handle<Value> HMDDeviceInfoWrap::GetHScreenSize(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->hScreenSize));
}

Handle<Value> HMDDeviceInfoWrap::GetVScreenSize(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->vScreenSize));
}

Handle<Value> HMDDeviceInfoWrap::GetVScreenCenter(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->vScreenCenter));
}

Handle<Value> HMDDeviceInfoWrap::GetEyeToScreenDistance(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->eyetoScreenDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetLensSeparationDistance(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->lensSeparationDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetInterpuillaryDistance(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->interpuillaryDistance));
}

Handle<Value> HMDDeviceInfoWrap::GetDistortionK(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	Local<Array> array = Array::New(4);

	array->Set(0, Number::New(hmdDeviceInfo->distortionK[0]));
	array->Set(1, Number::New(hmdDeviceInfo->distortionK[1]));
	array->Set(2, Number::New(hmdDeviceInfo->distortionK[2]));
	array->Set(3, Number::New(hmdDeviceInfo->distortionK[3]));

	return scope.Close(array);
}

Handle<Value> HMDDeviceInfoWrap::GetDesktopX(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->desktopX));
}

Handle<Value> HMDDeviceInfoWrap::GetDesktopY(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->desktopY));
}

Handle<Value> HMDDeviceInfoWrap::GetDisplayDeviceName(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(String::New(hmdDeviceInfo->displayDeviceName));
}

Handle<Value> HMDDeviceInfoWrap::GetDisplayId(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Number::New(hmdDeviceInfo->displayId));
}

Handle<Value> HMDDeviceInfoWrap::GetProductName(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(String::New(hmdDeviceInfo->productName));
}

Handle<Value> HMDDeviceInfoWrap::GetManufacturer(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(String::New(hmdDeviceInfo->manufacturer));
}

Handle<Value> HMDDeviceInfoWrap::GetVersion(const Arguments& args) {
	HandleScope scope;

	HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
	HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

	return scope.Close(Integer::New(hmdDeviceInfo->version));
}