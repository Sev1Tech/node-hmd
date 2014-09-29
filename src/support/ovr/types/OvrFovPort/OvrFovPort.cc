/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>

#include "OvrFovPort.h"
#include "OvrFovPortWrap.h"

using ::v8::Handle;
using ::v8::Value;

OvrFovPort::OvrFovPort(ovrFovPort value) : _value(value) {
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