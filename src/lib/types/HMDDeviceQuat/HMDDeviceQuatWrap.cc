/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "HMDDeviceQuat.h"
#include "HMDDeviceQuatWrap.h"

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceQuatWrap::constructor;

HMDDeviceQuatWrap::HMDDeviceQuatWrap() : _hmdDeviceQuat(new HMDDeviceQuat) {
}

HMDDeviceQuatWrap::~HMDDeviceQuatWrap() {
    delete this->_hmdDeviceQuat;
}

void HMDDeviceQuatWrap::Initialize(Handle<Object> target) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceQuat"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("w"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("x"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("y"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("z"), GetDeviceQuatProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    target->Set(NanNew("HMDDeviceQuat"), constructor);
}

NAN_METHOD(HMDDeviceQuatWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDeviceQuatWrap* w = new HMDDeviceQuatWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        NanReturnValue(constructor->NewInstance());
    }
}

Handle<Value> HMDDeviceQuatWrap::NewInstance() {
    NanScope();
    NanReturnValue(constructor->NewInstance());
}

HMDDeviceQuat* HMDDeviceQuatWrap::GetWrapped() {
    return this->_hmdDeviceQuat;
}

NAN_GETTER(HMDDeviceQuatWrap::GetDeviceQuatProperty) {
    NanScope();

    HMDDeviceQuatWrap* w = ObjectWrap::Unwrap<HMDDeviceQuatWrap>(args.This());
    HMDDeviceQuat* hmdDeviceQuat = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "w") {
        NanReturnValue(NanNew(hmdDeviceQuat->getW()));
    } else if (propertyString == "x") {
        NanReturnValue(NanNew(hmdDeviceQuat->getX()));
    } else if (propertyString == "y") {
        NanReturnValue(NanNew(hmdDeviceQuat->getY()));
    } else if (propertyString == "z") {
        NanReturnValue(NanNew(hmdDeviceQuat->getZ()));
    } else {
        NanReturnValue(NanUndefined());
    }
}
