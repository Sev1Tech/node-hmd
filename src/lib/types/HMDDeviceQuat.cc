/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDDeviceQuat.h>

#include <string>

/*
 * HMDDeviceQuat
 */

HMDDeviceQuat::HMDDeviceQuat()
    : _w(0.0f), _x(0.0f), _y(0.0f), _z(0.0f) {
}

HMDDeviceQuat::~HMDDeviceQuat() {
}

void HMDDeviceQuat::setQuat(float w, float x, float y, float z) {
    this->_w = w;
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

void HMDDeviceQuat::setQuat(HMDDeviceQuat deviceQuat) {
    this->setQuat(deviceQuat.getW(), deviceQuat.getX(), deviceQuat.getY(), deviceQuat.getZ());
}

float HMDDeviceQuat::getW() const {
    return this->_w;
}

float HMDDeviceQuat::getX() const {
    return this->_x;
}

float HMDDeviceQuat::getY() const {
    return this->_y;
}

float HMDDeviceQuat::getZ() const {
    return this->_z;
}

HMDDeviceQuat& HMDDeviceQuat::operator= (const HMDDeviceQuat &deviceQuat) {
    this->setQuat(deviceQuat);

    return *this;
}

/*
 * HMDDeviceQuatWrap
 */

using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceQuatWrap::constructor;

HMDDeviceQuatWrap::HMDDeviceQuatWrap()
    : _hmdDeviceQuat(new HMDDeviceQuat) {
}

HMDDeviceQuatWrap::~HMDDeviceQuatWrap() {
    delete this->_hmdDeviceQuat;
}

void HMDDeviceQuatWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceQuat"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetAccessor(NanNew("w"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("x"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("y"), GetDeviceQuatProperty);
    instance->SetAccessor(NanNew("z"), GetDeviceQuatProperty);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("HMDDeviceQuat"), NanNew(constructor));
}

NAN_METHOD(HMDDeviceQuatWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDeviceQuatWrap* w = new HMDDeviceQuatWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Function> cons = NanNew(constructor);
        NanReturnValue(cons->NewInstance(argc, argv));
    }
}

Handle<Object> HMDDeviceQuatWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
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
