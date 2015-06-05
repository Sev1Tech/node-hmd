/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDManager.h>

#include <HMDDeviceFactory.h>
#include <HMDDeviceInfo.h>
#include <HMDDeviceOrientation.h>
#include <HMDDevicePosition.h>
#include <HMDDeviceQuat.h>

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDManagerWrap::constructor;

HMDManagerWrap::HMDManagerWrap(const char* classToken)
    : _hmdDevice(HMDDeviceFactory::getInstance(classToken)) {
}

HMDManagerWrap::~HMDManagerWrap() {
    if (_hmdDevice) {
        delete this->_hmdDevice;
    }
}

void HMDManagerWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDManager"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NanSetPrototypeTemplate(tpl, "getDeviceInfo", NanNew<FunctionTemplate>(GetDeviceInfoAsync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDeviceInfoSync", NanNew<FunctionTemplate>(GetDeviceInfoSync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDeviceOrientation", NanNew<FunctionTemplate>(GetDeviceOrientationAsync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDeviceOrientationSync", NanNew<FunctionTemplate>(GetDeviceOrientationSync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDevicePosition", NanNew<FunctionTemplate>(GetDevicePositionAsync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDevicePositionSync", NanNew<FunctionTemplate>(GetDevicePositionSync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDeviceQuat", NanNew<FunctionTemplate>(GetDeviceQuatAsync)->GetFunction());
    NanSetPrototypeTemplate(tpl, "getDeviceQuatSync", NanNew<FunctionTemplate>(GetDeviceQuatSync)->GetFunction());

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
}

NAN_METHOD(HMDManagerWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDManagerWrap* w = new HMDManagerWrap(*NanAsciiString(args[0]));

        if (w->GetDevice() == NULL) {
            NanThrowError("Invalid device creation token.");
        }

        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Function> cons = NanNew(constructor);
        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

NAN_METHOD(HMDManagerWrap::NewInstance) {
    NanScope();

    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Function> cons = NanNew(constructor);
    NanReturnValue(cons->NewInstance(argc, argv));
}

HMDDevice* HMDManagerWrap::GetDevice() {
    return this->_hmdDevice;
}

NAN_METHOD(HMDManagerWrap::GetDeviceInfoAsync) {
    NanScope();

    HMDManagerWrap* hmdManagerWrap = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
    NanCallback *callback = new NanCallback(args[0].As<Function>());

    NanAsyncQueueWorker(new GetDeviceInfoWorker(callback, hmdManagerWrap->GetDevice()));
    NanReturnUndefined();
}

NAN_METHOD(HMDManagerWrap::GetDeviceInfoSync) {
    NanScope();


    HMDManagerWrap* hmdManagerWrap = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

    Handle<Value> hmdDeviceInfoHandle = HMDDeviceInfoWrap::CreateInstance();
    hmdManagerWrap->GetDevice()->getDeviceInfo(ObjectWrap::Unwrap<HMDDeviceInfoWrap>(hmdDeviceInfoHandle->ToObject())->GetWrapped());

    NanReturnValue(hmdDeviceInfoHandle);
}

NAN_METHOD(HMDManagerWrap::GetDeviceOrientationAsync) {
    NanScope();

    HMDManagerWrap* hmdManagerWrap = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
    NanCallback *callback = new NanCallback(args[0].As<Function>());

    NanAsyncQueueWorker(new GetDeviceOrientationWorker(callback, hmdManagerWrap->GetDevice()));
    NanReturnUndefined();
}

NAN_METHOD(HMDManagerWrap::GetDeviceOrientationSync) {
    NanScope();

    HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

    Handle<Value> hmdDeviceOrientation = HMDDeviceOrientationWrap::CreateInstance();
    hmdManager->GetDevice()->getDeviceOrientation(ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(hmdDeviceOrientation->ToObject())->GetWrapped());

    NanReturnValue(hmdDeviceOrientation);
}

NAN_METHOD(HMDManagerWrap::GetDevicePositionAsync) {
    NanScope();

    HMDManagerWrap* hmdManagerWrap = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
    NanCallback *callback = new NanCallback(args[0].As<Function>());

    NanAsyncQueueWorker(new GetDevicePositionWorker(callback, hmdManagerWrap->GetDevice()));
    NanReturnUndefined();
}

NAN_METHOD(HMDManagerWrap::GetDevicePositionSync) {
    NanScope();

    HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

    Handle<Value> hmdDevicePosition = HMDDevicePositionWrap::CreateInstance();
    hmdManager->GetDevice()->getDevicePosition(ObjectWrap::Unwrap<HMDDevicePositionWrap>(hmdDevicePosition->ToObject())->GetWrapped());

    NanReturnValue(hmdDevicePosition);
}

NAN_METHOD(HMDManagerWrap::GetDeviceQuatAsync) {
    NanScope();

    HMDManagerWrap* hmdManagerWrap = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());
    NanCallback *callback = new NanCallback(args[0].As<Function>());

    NanAsyncQueueWorker(new GetDeviceQuatWorker(callback, hmdManagerWrap->GetDevice()));
    NanReturnUndefined();
}

NAN_METHOD(HMDManagerWrap::GetDeviceQuatSync) {
    NanScope();

    HMDManagerWrap* hmdManager = ObjectWrap::Unwrap<HMDManagerWrap>(args.This());

    Handle<Value> hmdDeviceQuat = HMDDeviceQuatWrap::CreateInstance();
    hmdManager->GetDevice()->getDeviceQuat(ObjectWrap::Unwrap<HMDDeviceQuatWrap>(hmdDeviceQuat->ToObject())->GetWrapped());

    NanReturnValue(hmdDeviceQuat);
}

void GetDeviceInfoWorker::Execute() {
    this->hmdDevice->getDeviceInfo(&this->hmdDeviceInfo);
}

void GetDeviceInfoWorker::HandleOKCallback() {
    NanScope();

    Handle<Value> hmdDeviceInfoHandle = HMDDeviceInfoWrap::CreateInstance();
    HMDDeviceInfoWrap* hmdDeviceInfo = node::ObjectWrap::Unwrap<HMDDeviceInfoWrap>(hmdDeviceInfoHandle->ToObject());
    *hmdDeviceInfo->GetWrapped() = this->hmdDeviceInfo;

    Handle<Value> argv[] = { NanNull(), hmdDeviceInfoHandle };

    callback->Call(2, argv);
}

void GetDeviceOrientationWorker::Execute() {
    this->hmdDevice->getDeviceOrientation(&this->hmdDeviceOrientation);
}

void GetDeviceOrientationWorker::HandleOKCallback() {
    NanScope();

    Handle<Value> hmdDeviceOrientationHandle = HMDDeviceOrientationWrap::CreateInstance();
    HMDDeviceOrientationWrap* hmdDeviceOrientation = node::ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(hmdDeviceOrientationHandle->ToObject());
    *hmdDeviceOrientation->GetWrapped() = this->hmdDeviceOrientation;

    Handle<Value> argv[] = { NanNull(), hmdDeviceOrientationHandle };

    callback->Call(2, argv);
}

void GetDevicePositionWorker::Execute() {
    this->hmdDevice->getDevicePosition(&this->hmdDevicePosition);
}

void GetDevicePositionWorker::HandleOKCallback() {
    NanScope();

    Handle<Value> hmdDevicePositionHandle = HMDDevicePositionWrap::CreateInstance();
    HMDDevicePositionWrap* hmdDevicePosition = node::ObjectWrap::Unwrap<HMDDevicePositionWrap>(hmdDevicePositionHandle->ToObject());
    *hmdDevicePosition->GetWrapped() = this->hmdDevicePosition;

    Handle<Value> argv[] = { NanNull(), hmdDevicePositionHandle };

    callback->Call(2, argv);
}

void GetDeviceQuatWorker::Execute() {
    this->hmdDevice->getDeviceQuat(&this->hmdDeviceQuat);
}

void GetDeviceQuatWorker::HandleOKCallback() {
    NanScope();

    Handle<Value> hmdDeviceQuatHandle = HMDDeviceQuatWrap::CreateInstance();
    HMDDeviceQuatWrap* hmdDeviceQuat = node::ObjectWrap::Unwrap<HMDDeviceQuatWrap>(hmdDeviceQuatHandle->ToObject());
    *hmdDeviceQuat->GetWrapped() = this->hmdDeviceQuat;

    Handle<Value> argv[] = { NanNull(), hmdDeviceQuatHandle };

    callback->Call(2, argv);
}
