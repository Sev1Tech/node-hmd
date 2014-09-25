/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <boost/any.hpp>
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
        boost::any element = hmdDeviceInfo->getElement(*NanAsciiString(property));

        if (element.type() == typeid(static_cast<int>(0))) {
            NanReturnValue(NanNew(boost::any_cast<int>(element)));
        } else if (element.type() == typeid(static_cast<float>(0.0f))) {
            NanReturnValue(NanNew(boost::any_cast<float>(element)));
        } else if (element.type() == typeid(static_cast<double>(0.0))) {
            NanReturnValue(NanNew(boost::any_cast<double>(element)));
        } else if (element.type() == typeid(std::string)) {
            std::string value = boost::any_cast<std::string>(element);
            NanReturnValue(NanNew(value));
        } else if (element.type() == typeid(std::vector<int>)) {
            std::vector<int> value = boost::any_cast<std::vector<int> >(element);
            Local<Array> arr = NanNew<Array>(value.size());
            for (std::vector<int>::size_type i = 0; i < value.size(); i++) {
                arr->Set(i, NanNew(value[i]));
            }
            NanReturnValue(NanNew(arr));
        } else if (element.type() == typeid(std::vector<float>)) {
            std::vector<float> value = boost::any_cast<std::vector<float> >(element);
            Local<Array> arr = NanNew<Array>(value.size());
            for (std::vector<float>::size_type i = 0; i < value.size(); i++) {
                arr->Set(i, NanNew(value[i]));
            }
            NanReturnValue(NanNew(arr));
        } else if (element.type() == typeid(std::vector<double>)) {
            std::vector<double> value = boost::any_cast<std::vector<double> >(element);
            Local<Array> arr = NanNew<Array>(value.size());
            for (std::vector<double>::size_type i = 0; i < value.size(); i++) {
                arr->Set(i, NanNew(value[i]));
            }
            NanReturnValue(NanNew(arr));
        } else if (element.type() == typeid(std::vector<std::string>)) {
            std::vector<std::string> value = boost::any_cast<std::vector<std::string> >(element);
            Local<Array> arr = NanNew<Array>(value.size());
            for (std::vector<std::string>::size_type i = 0; i < value.size(); i++) {
                arr->Set(i, NanNew(value[i]));
            }
            NanReturnValue(NanNew(arr));
        } else {
            NanReturnValue(NanUndefined());
        }
    }
    catch (ElementNotFoundError &ex) {
        NanReturnValue(NanUndefined());
    }
}
