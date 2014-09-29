/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <string>

#include "OvrVector2i.h"
#include "OvrVector2iWrap.h"

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> OvrVector2iWrap::constructor;

OvrVector2iWrap::OvrVector2iWrap() {
}

OvrVector2iWrap::~OvrVector2iWrap() {
}

void OvrVector2iWrap::Initialize(Handle<Object> target) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("OvrVector2i"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("x"), GetObjectProperty);
    instance->SetAccessor(NanNew("y"), GetObjectProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    target->Set(NanNew("OvrVector2i"), constructor);
}

NAN_METHOD(OvrVector2iWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        OvrVector2iWrap* w = new OvrVector2iWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        NanReturnValue(constructor->NewInstance());
    }
}

Handle<Value> OvrVector2iWrap::NewInstance() {
    NanScope();
    NanReturnValue(constructor->NewInstance());
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
