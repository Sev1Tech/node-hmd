/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <OvrSizei.h>

#include <nan/nan.h>

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

/*
 * OvrSizei
 */

OvrSizei::OvrSizei(ovrSizei value)
    : _value(value) {
}

OvrSizei::~OvrSizei() {
}

Handle<Value> OvrSizei::getValue() {
    Handle<Object> deviceOvrSizeiHandle = OvrSizeiWrap::CreateInstance();
    OvrSizeiWrap* deviceOvrSizeiWrap =  node::ObjectWrap::Unwrap<OvrSizeiWrap>(deviceOvrSizeiHandle);;
    ovrSizei* deviceOvrSizei = deviceOvrSizeiWrap->GetWrapped();

    deviceOvrSizei->w = this->_value.w;
    deviceOvrSizei->h = this->_value.h;

    return deviceOvrSizeiHandle;
}

HMDDeviceInfoElement* OvrSizei::clone() {
    return new OvrSizei(this->_value);
}

/*
 * OvrSizeiWrap
 */

Persistent<Function> OvrSizeiWrap::constructor;

OvrSizeiWrap::OvrSizeiWrap() {
}

OvrSizeiWrap::~OvrSizeiWrap() {
}

void OvrSizeiWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("OvrSizei"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("w"), GetObjectProperty);
    instance->SetAccessor(NanNew("h"), GetObjectProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("OvrSizei"), NanNew(constructor));
}

NAN_METHOD(OvrSizeiWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        OvrSizeiWrap* w = new OvrSizeiWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        NanReturnValue(NanNew(constructor)->NewInstance(argc, argv));
    }
}

Handle<Object> OvrSizeiWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
}

ovrSizei* OvrSizeiWrap::GetWrapped() {
    return &this->_ovrSizei;
}

NAN_GETTER(OvrSizeiWrap::GetObjectProperty) {
    NanScope();

    OvrSizeiWrap* w = ObjectWrap::Unwrap<OvrSizeiWrap>(args.This());
    ovrSizei* deviceOvrSizei = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "w") {
        NanReturnValue(NanNew(deviceOvrSizei->w));
    } else if (propertyString == "h") {
        NanReturnValue(NanNew(deviceOvrSizei->h));
    } else {
        NanReturnUndefined();
    }

    NanReturnValue(66);
}
