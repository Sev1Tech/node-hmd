/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>
#include <vector>

#include "HMDDeviceInfo.h"
#include "HMDDeviceInfoWrap.h"

using ::v8::Array;
using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Integer;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceInfoWrap::constructor;

HMDDeviceInfoWrap::HMDDeviceInfoWrap() {
    this->_hmdDeviceInfo = new HMDDeviceInfo;
}

HMDDeviceInfoWrap::~HMDDeviceInfoWrap() {
    delete this->_hmdDeviceInfo;
}

void HMDDeviceInfoWrap::Initialize(Handle<Object> target) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceInfo"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetNamedPropertyHandler(GetDeviceInfoProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    target->Set(NanNew("HMDDeviceInfo"), constructor);
}

NAN_METHOD(HMDDeviceInfoWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDeviceInfoWrap* w = new HMDDeviceInfoWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
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
    try {
        HMDDeviceInfoElement* element = hmdDeviceInfo->getElement(*NanAsciiString(property));
        NanReturnValue(element->getValue());
    }
    catch (ElementNotFoundError &ex) {
        NanReturnValue(NanUndefined());
    }
}
