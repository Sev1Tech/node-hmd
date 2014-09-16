/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */
#include <string>

#include "HMDDeviceOrientation.h"
#include "HMDDeviceOrientationWrap.h"

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceOrientationWrap::constructor;

HMDDeviceOrientationWrap::HMDDeviceOrientationWrap() {
    this->_hmdDeviceOrientation = new HMDDeviceOrientation;
}

HMDDeviceOrientationWrap::~HMDDeviceOrientationWrap() {
    delete this->_hmdDeviceOrientation;
}

void HMDDeviceOrientationWrap::Initialize(Handle<Object> target) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceOrientation"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("yaw"), GetDeviceOrientationProperty);
    instance->SetAccessor(NanNew("pitch"), GetDeviceOrientationProperty);
    instance->SetAccessor(NanNew("roll"), GetDeviceOrientationProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    target->Set(NanNew("HMDDeviceOrientation"), constructor);
}

NAN_METHOD(HMDDeviceOrientationWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDeviceOrientationWrap* w = new HMDDeviceOrientationWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
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

    if (propertyString == "yaw") {
        NanReturnValue(NanNew(hmdDeviceInfo->yaw));
    } else if (propertyString == "pitch") {
        NanReturnValue(NanNew(hmdDeviceInfo->pitch));
    } else if (propertyString == "roll") {
        NanReturnValue(NanNew(hmdDeviceInfo->roll));
    } else {
        NanReturnValue(NanNew(0.0));
    }
}
