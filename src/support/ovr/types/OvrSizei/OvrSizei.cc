/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>

#include "OvrSizei.h"
#include "OvrSizeiWrap.h"

using ::v8::Handle;
using ::v8::Value;

OvrSizei::OvrSizei(ovrSizei value) : _value(value) {
}

OvrSizei::~OvrSizei() {
}

Handle<Value> OvrSizei::getValue() {
    Handle<Value> ovrSizeiHandle = OvrSizeiWrap::NewInstance();
    OvrSizeiWrap* deviceOvrSizeiWrap = node::ObjectWrap::Unwrap<OvrSizeiWrap>(ovrSizeiHandle->ToObject());
    ovrSizei* deviceOvrSizei = deviceOvrSizeiWrap->GetWrapped();

    deviceOvrSizei->w = this->_value.w;
    deviceOvrSizei->h = this->_value.h;

    return ovrSizeiHandle;
}

HMDDeviceInfoElement* OvrSizei::clone() {
    return new OvrSizei(this->_value);
}