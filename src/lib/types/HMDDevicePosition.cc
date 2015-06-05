/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDDevicePosition.h>

#include <string>

/*
 * HMDDevicePosition
 */

HMDDevicePosition::HMDDevicePosition()
    : _x(0.0f), _y(0.0f), _z(0.0f) {
}

HMDDevicePosition::~HMDDevicePosition() {
}

void HMDDevicePosition::setPosition(float x, float y, float z) {
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

void HMDDevicePosition::setPosition(HMDDevicePosition devicePosition) {
    this->setPosition(devicePosition.getX(), devicePosition.getY(), devicePosition.getZ());
}

float HMDDevicePosition::getX() const {
    return this->_x;
}

float HMDDevicePosition::getY() const {
    return this->_y;
}

float HMDDevicePosition::getZ() const {
    return this->_z;
}

HMDDevicePosition& HMDDevicePosition::operator= (const HMDDevicePosition &devicePosition) {
    this->setPosition(devicePosition);

    return *this;
}

/*
 * HMDDevicePositionWrap
 */

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDevicePositionWrap::constructor;

HMDDevicePositionWrap::HMDDevicePositionWrap()
    : _hmdDevicePosition(new HMDDevicePosition) {
}

HMDDevicePositionWrap::~HMDDevicePositionWrap() {
    delete this->_hmdDevicePosition;
}

void HMDDevicePositionWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDevicePosition"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("x"), GetDevicePositionProperty);
    instance->SetAccessor(NanNew("y"), GetDevicePositionProperty);
    instance->SetAccessor(NanNew("z"), GetDevicePositionProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("HMDDevicePosition"), NanNew(constructor));
}

NAN_METHOD(HMDDevicePositionWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDevicePositionWrap* w = new HMDDevicePositionWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Function> cons = NanNew(constructor);
        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

Handle<Object> HMDDevicePositionWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
}

HMDDevicePosition* HMDDevicePositionWrap::GetWrapped() {
    return this->_hmdDevicePosition;
}

NAN_GETTER(HMDDevicePositionWrap::GetDevicePositionProperty) {
    NanScope();

    HMDDevicePositionWrap* w = ObjectWrap::Unwrap<HMDDevicePositionWrap>(args.This());
    HMDDevicePosition* hmdDevicePosition = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "x") {
        NanReturnValue(NanNew(hmdDevicePosition->getX()));
    } else if (propertyString == "y") {
        NanReturnValue(NanNew(hmdDevicePosition->getY()));
    } else if (propertyString == "z") {
        NanReturnValue(NanNew(hmdDevicePosition->getZ()));
    } else {
        NanReturnValue(NanUndefined());
    }
}
