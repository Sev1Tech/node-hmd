/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>

#include "OvrVector2i.h"
#include "OvrVector2iWrap.h"

using ::v8::Handle;
using ::v8::Value;

OvrVector2i::OvrVector2i(ovrVector2i value) : _value(value) {
}

OvrVector2i::~OvrVector2i() {
}

Handle<Value> OvrVector2i::getValue() {
    Handle<Value> ovrVector2iHandle = OvrVector2iWrap::NewInstance();
    OvrVector2iWrap* deviceOvrVector2iWrap = node::ObjectWrap::Unwrap<OvrVector2iWrap>(ovrVector2iHandle->ToObject());
    ovrVector2i* deviceOvrVector2i = deviceOvrVector2iWrap->GetWrapped();

    deviceOvrVector2i->x = this->_value.x;
    deviceOvrVector2i->y = this->_value.y;

    return ovrVector2iHandle;
}

HMDDeviceInfoElement* OvrVector2i::clone() {
    return new OvrVector2i(this->_value);
}