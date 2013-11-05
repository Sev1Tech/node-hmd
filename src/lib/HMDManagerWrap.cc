/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <node.h>

#include "HMDDeviceFactory.h"
#include "HMDDeviceInfo.h"
#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDDeviceType.h"
#include "HMDManagerWrap.h"

using namespace v8;

struct AsyncDeviceRequest {
	uv_work_t workRequest;
	Persistent<Function> callback;
	const Arguments* context;

	HMDDevice* hmdDevice;
	void* requestData;
};

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

	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceInfo"), FunctionTemplate::New(GetDeviceInfoAsync)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceInfoSync"), FunctionTemplate::New(GetDeviceInfoSync)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceOrientation"), FunctionTemplate::New(GetDeviceOrientationAsync)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceOrientationSync"), FunctionTemplate::New(GetDeviceOrientationSync)->GetFunction());

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

Handle<Value> HMDManagerWrap::GetDeviceInfoAsync(const Arguments& args) {
	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

	AsyncDeviceRequest *asyncRequest = new AsyncDeviceRequest;
	asyncRequest->workRequest.data = asyncRequest;
	asyncRequest->callback = Persistent<Function>::New(Local<Function>::Cast(args[0]));
	asyncRequest->context = &args;

	asyncRequest->hmdDevice = hmdManager->GetDevice();
	asyncRequest->requestData = new HMDDeviceInfo;

	uv_queue_work(uv_default_loop(), &asyncRequest->workRequest, GetDeviceInfoRequestAsync, (uv_after_work_cb)GetDeviceInfoRequestAfterAsync);

	return Undefined();
}

void HMDManagerWrap::GetDeviceInfoRequestAsync(uv_work_t *request) {
	AsyncDeviceRequest *asyncRequest = reinterpret_cast<AsyncDeviceRequest *>(request->data);
	asyncRequest->hmdDevice->getDeviceInfo((HMDDeviceInfo *)(asyncRequest->requestData));
}

void HMDManagerWrap::GetDeviceInfoRequestAfterAsync(uv_work_t *request) {
	AsyncDeviceRequest *asyncRequest = reinterpret_cast<AsyncDeviceRequest *>(request->data);
	Handle<Value> hmdDeviceInfo = HMDDeviceInfoWrap::NewInstance(*(asyncRequest->context));
	*ObjectWrap::Unwrap<HMDDeviceInfoWrap>(hmdDeviceInfo->ToObject())->GetWrapped() = *(HMDDeviceInfo *)(asyncRequest->requestData);

	Handle<Value> argv[2] = { Null(), hmdDeviceInfo };

	TryCatch tryCatch;

	asyncRequest->callback->Call(Context::GetCurrent()->Global(), 2, argv);
	asyncRequest->callback.Dispose();
	delete (HMDDeviceInfo *)(asyncRequest->requestData);
	delete asyncRequest;

	if (tryCatch.HasCaught()) {
		node::FatalException(tryCatch);
	}
}

Handle<Value> HMDManagerWrap::GetDeviceInfoSync(const Arguments& args) {
	HandleScope scope;

	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
	Handle<Value> hmdDeviceInfo = HMDDeviceInfoWrap::NewInstance(args);

	hmdManager->GetDevice()->getDeviceInfo(ObjectWrap::Unwrap<HMDDeviceInfoWrap>(hmdDeviceInfo->ToObject())->GetWrapped());

	return scope.Close(hmdDeviceInfo);
}

Handle<Value> HMDManagerWrap::GetDeviceOrientationAsync(const Arguments& args) {
	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

	AsyncDeviceRequest *asyncRequest = new AsyncDeviceRequest;
	asyncRequest->workRequest.data = asyncRequest;
	asyncRequest->callback = Persistent<Function>::New(Local<Function>::Cast(args[0]));
	asyncRequest->context = &args;

	asyncRequest->hmdDevice = hmdManager->GetDevice();
	asyncRequest->requestData = new HMDDeviceOrientation;

	uv_queue_work(uv_default_loop(), &asyncRequest->workRequest, GetDeviceOrientationRequestAsync, (uv_after_work_cb)GetDeviceOrientationRequestAfterAsync);

	return Undefined();
}

void HMDManagerWrap::GetDeviceOrientationRequestAsync(uv_work_t *request) {
	AsyncDeviceRequest *asyncRequest = reinterpret_cast<AsyncDeviceRequest *>(request->data);
	asyncRequest->hmdDevice->getDeviceOrientation((HMDDeviceOrientation *)(asyncRequest->requestData));
}

void HMDManagerWrap::GetDeviceOrientationRequestAfterAsync(uv_work_t *request) {
	AsyncDeviceRequest *asyncRequest = reinterpret_cast<AsyncDeviceRequest *>(request->data);
	Handle<Value> hmdDeviceOrientation = HMDDeviceOrientationWrap::NewInstance(*(asyncRequest->context));
	*ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(hmdDeviceOrientation->ToObject())->GetWrapped() = *(HMDDeviceOrientation *)(asyncRequest->requestData);

	Handle<Value> argv[2] = { Null(), hmdDeviceOrientation };

	TryCatch tryCatch;

	asyncRequest->callback->Call(Context::GetCurrent()->Global(), 2, argv);
	asyncRequest->callback.Dispose();
	delete (HMDDeviceOrientation *)(asyncRequest->requestData);
	delete asyncRequest;

	if (tryCatch.HasCaught()) {
		node::FatalException(tryCatch);
	}
}

Handle<Value> HMDManagerWrap::GetDeviceOrientationSync(const Arguments& args) {
	HandleScope scope;

	HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
	Handle<Value> hmdDeviceOrientation = HMDDeviceOrientationWrap::NewInstance(args);

	hmdManager->GetDevice()->getDeviceOrientation(ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(hmdDeviceOrientation->ToObject())->GetWrapped());

	return scope.Close(hmdDeviceOrientation);
}