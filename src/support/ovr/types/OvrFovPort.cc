/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <OvrFovPort.h>

#include <nan/nan.h>

#include <string>

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

/*
 * OvrFovPort
 */

OvrFovPort::OvrFovPort(ovrFovPort value)
    : _value(value) {
}

OvrFovPort::~OvrFovPort() {
}

Handle<Value> OvrFovPort::getValue() {
    Handle<Value> ovrFovPortHandle = OvrFovPortWrap::NewInstance();
    OvrFovPortWrap* deviceOvrFovPortWrap = node::ObjectWrap::Unwrap<OvrFovPortWrap>(ovrFovPortHandle->ToObject());
    ovrFovPort* deviceOvrFovPort = deviceOvrFovPortWrap->GetWrapped();

    deviceOvrFovPort->UpTan = this->_value.UpTan;
    deviceOvrFovPort->DownTan = this->_value.DownTan;
    deviceOvrFovPort->LeftTan = this->_value.LeftTan;
    deviceOvrFovPort->RightTan = this->_value.RightTan;

    return ovrFovPortHandle;
}

HMDDeviceInfoElement* OvrFovPort::clone() {
    return new OvrFovPort(this->_value);
}

/*
 * OvrFovPortWrap
 */

Persistent<Function> OvrFovPortWrap::constructor;

OvrFovPortWrap::OvrFovPortWrap() {
}

OvrFovPortWrap::~OvrFovPortWrap() {
}

void OvrFovPortWrap::Initialize(Handle<Object> target) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("OvrFovPort"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("UpTan"), GetObjectProperty);
    instance->SetAccessor(NanNew("DownTan"), GetObjectProperty);
    instance->SetAccessor(NanNew("LeftTan"), GetObjectProperty);
    instance->SetAccessor(NanNew("RightTan"), GetObjectProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    target->Set(NanNew("OvrFovPort"), constructor);
}

NAN_METHOD(OvrFovPortWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        OvrFovPortWrap* w = new OvrFovPortWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        NanReturnValue(constructor->NewInstance());
    }
}

Handle<Value> OvrFovPortWrap::NewInstance() {
    NanScope();
    NanReturnValue(constructor->NewInstance());
}

ovrFovPort* OvrFovPortWrap::GetWrapped() {
    return &this->_ovrFovPort;
}

NAN_GETTER(OvrFovPortWrap::GetObjectProperty) {
    NanScope();

    OvrFovPortWrap* w = ObjectWrap::Unwrap<OvrFovPortWrap>(args.This());
    ovrFovPort* deviceOvrFovPort = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "UpTan") {
        NanReturnValue(NanNew(deviceOvrFovPort->UpTan));
    } else if (propertyString == "DownTan") {
        NanReturnValue(NanNew(deviceOvrFovPort->DownTan));
    } else if (propertyString == "LeftTan") {
        NanReturnValue(NanNew(deviceOvrFovPort->LeftTan));
    } else if (propertyString == "RightTan") {
        NanReturnValue(NanNew(deviceOvrFovPort->RightTan));
    } else {
        NanReturnValue(NanUndefined());
    }
}
