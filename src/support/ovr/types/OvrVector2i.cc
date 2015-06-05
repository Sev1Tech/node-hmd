/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <OvrVector2i.h>

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
 * OvrVector2i
 */

OvrVector2i::OvrVector2i(ovrVector2i value)
    : _value(value) {
}

OvrVector2i::~OvrVector2i() {
}

Handle<Value> OvrVector2i::getValue() {
    Handle<Object> deviceOvrVector2iHandle = OvrVector2iWrap::CreateInstance();
    OvrVector2iWrap* deviceOvrVector2iWrap =  node::ObjectWrap::Unwrap<OvrVector2iWrap>(deviceOvrVector2iHandle);;
    ovrVector2i* deviceOvrVector2i = deviceOvrVector2iWrap->GetWrapped();

    deviceOvrVector2i->x = this->_value.x;
    deviceOvrVector2i->y = this->_value.y;

    return deviceOvrVector2iHandle;
}

HMDDeviceInfoElement* OvrVector2i::clone() {
    return new OvrVector2i(this->_value);
}

/*
 * OvrVector2iWrap
 */

Persistent<Function> OvrVector2iWrap::constructor;

OvrVector2iWrap::OvrVector2iWrap() {
}

OvrVector2iWrap::~OvrVector2iWrap() {
}

void OvrVector2iWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("OvrVector2i"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("x"), GetObjectProperty);
    instance->SetAccessor(NanNew("y"), GetObjectProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("OvrVector2i"), NanNew(constructor));
}

NAN_METHOD(OvrVector2iWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        OvrVector2iWrap* w = new OvrVector2iWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        NanReturnValue(NanNew(constructor)->NewInstance(argc, argv));
    }
}

Handle<Object> OvrVector2iWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
}

ovrVector2i* OvrVector2iWrap::GetWrapped() {
    return &this->_ovrVector2i;
}

NAN_GETTER(OvrVector2iWrap::GetObjectProperty) {
    NanScope();

    OvrVector2iWrap* w = ObjectWrap::Unwrap<OvrVector2iWrap>(args.This());
    ovrVector2i* deviceOvrVector2i = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "x") {
        NanReturnValue(NanNew(deviceOvrVector2i->x));
    } else if (propertyString == "y") {
        NanReturnValue(NanNew(deviceOvrVector2i->y));
    } else {
        NanReturnValue(NanUndefined());
    }
}
