/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

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
    instance->SetAccessor(NanNew("hResolution"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("vResolution"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("hScreenSize"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("vScreenSize"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("vScreenCenter"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("eyetoScreenDistance"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("lensSeparationDistance"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("interpuillaryDistance"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("distortionK"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("desktopX"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("desktopY"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("displayDeviceName"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("displayId"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("productName"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("manufacturer"), GetDeviceInfoProperty);
    instance->SetAccessor(NanNew("version"), GetDeviceInfoProperty);

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

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "hResolution") {
        NanReturnValue(NanNew(hmdDeviceInfo->hResolution));
    } else if (propertyString == "vResolution") {
        NanReturnValue(NanNew(hmdDeviceInfo->vResolution));
    } else if (propertyString == "hScreenSize") {
        NanReturnValue(NanNew(hmdDeviceInfo->hScreenSize));
    } else if (propertyString == "vScreenSize") {
        NanReturnValue(NanNew(hmdDeviceInfo->vScreenSize));
    } else if (propertyString == "vScreenCenter") {
        NanReturnValue(NanNew(hmdDeviceInfo->vScreenCenter));
    } else if (propertyString == "eyetoScreenDistance") {
        NanReturnValue(NanNew(hmdDeviceInfo->eyetoScreenDistance));
    } else if (propertyString == "lensSeparationDistance") {
        NanReturnValue(NanNew(hmdDeviceInfo->lensSeparationDistance));
    } else if (propertyString == "interpuillaryDistance") {
        NanReturnValue(NanNew(hmdDeviceInfo->interpuillaryDistance));
    } else if (propertyString == "distortionK") {
        Local<Array> array = NanNew<Array>(4);

        array->Set(0, NanNew(hmdDeviceInfo->distortionK[0]));
        array->Set(1, NanNew(hmdDeviceInfo->distortionK[1]));
        array->Set(2, NanNew(hmdDeviceInfo->distortionK[2]));
        array->Set(3, NanNew(hmdDeviceInfo->distortionK[3]));

        NanReturnValue(array);
    } else if (propertyString == "desktopX") {
        NanReturnValue(NanNew(hmdDeviceInfo->desktopX));
    } else if (propertyString == "desktopY") {
        NanReturnValue(NanNew(hmdDeviceInfo->desktopY));
    } else if (propertyString == "displayDeviceName") {
        NanReturnValue(NanNew(hmdDeviceInfo->displayDeviceName));
    } else if (propertyString == "displayId") {
        NanReturnValue(NanNew<Integer>(hmdDeviceInfo->displayId));
    } else if (propertyString == "productName") {
        NanReturnValue(NanNew(hmdDeviceInfo->productName));
    } else if (propertyString == "manufacturer") {
        NanReturnValue(NanNew(hmdDeviceInfo->manufacturer));
    } else if (propertyString == "version") {
        NanReturnValue(NanNew(hmdDeviceInfo->version));
    } else {
        NanReturnValue(NanNew(""));
    }
}
