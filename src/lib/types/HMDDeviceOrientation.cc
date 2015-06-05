/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDDeviceOrientation.h>

#include <string>

/*
 * HMDDeviceOrientation
 */

HMDDeviceOrientation::HMDDeviceOrientation()
    : _yaw(0.0f), _pitch(0.0f), _roll(0.0f) {
}

HMDDeviceOrientation::~HMDDeviceOrientation() {
}

void HMDDeviceOrientation::setOrientation(float yaw, float pitch, float roll) {
    this->_yaw = yaw;
    this->_pitch = pitch;
    this->_roll = roll;
}

void HMDDeviceOrientation::setOrientation(HMDDeviceOrientation deviceOrientation) {
    this->setOrientation(deviceOrientation.getYaw(), deviceOrientation.getPitch(), deviceOrientation.getRoll());
}

float HMDDeviceOrientation::getYaw() const {
    return this->_yaw;
}

float HMDDeviceOrientation::getPitch() const {
    return this->_pitch;
}

float HMDDeviceOrientation::getRoll() const {
    return this->_roll;
}

HMDDeviceOrientation& HMDDeviceOrientation::operator= (const HMDDeviceOrientation &deviceOrientation) {
    this->setOrientation(deviceOrientation);

    return *this;
}

/*
 * HMDDeviceOrientationWrap
 */

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceOrientationWrap::constructor;

HMDDeviceOrientationWrap::HMDDeviceOrientationWrap()
    : _hmdDeviceOrientation(new HMDDeviceOrientation) {
}

HMDDeviceOrientationWrap::~HMDDeviceOrientationWrap() {
    delete this->_hmdDeviceOrientation;
}

void HMDDeviceOrientationWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceOrientation"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("yaw"), GetDeviceOrientationProperty);
    instance->SetAccessor(NanNew("pitch"), GetDeviceOrientationProperty);
    instance->SetAccessor(NanNew("roll"), GetDeviceOrientationProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("HMDDeviceOrientation"), NanNew(constructor));
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
        Local<Function> cons = NanNew(constructor);
        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

Handle<Object> HMDDeviceOrientationWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
}

HMDDeviceOrientation* HMDDeviceOrientationWrap::GetWrapped() {
    return this->_hmdDeviceOrientation;
}

NAN_GETTER(HMDDeviceOrientationWrap::GetDeviceOrientationProperty) {
    NanScope();

    HMDDeviceOrientationWrap* w = ObjectWrap::Unwrap<HMDDeviceOrientationWrap>(args.This());
    HMDDeviceOrientation* hmdDeviceOrientation = w->GetWrapped();

    std::string propertyString(*NanAsciiString(property));

    if (propertyString == "yaw") {
        NanReturnValue(NanNew(hmdDeviceOrientation->getYaw()));
    } else if (propertyString == "pitch") {
        NanReturnValue(NanNew(hmdDeviceOrientation->getPitch()));
    } else if (propertyString == "roll") {
        NanReturnValue(NanNew(hmdDeviceOrientation->getRoll()));
    } else {
        NanReturnValue(NanUndefined());
    }
}
