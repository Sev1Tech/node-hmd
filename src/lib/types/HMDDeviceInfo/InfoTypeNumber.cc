/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <boost/any.hpp>
#include <nan/nan.h>
#include <node.h>

#include "InfoTypeNumber.h"

using ::v8::Handle;
using ::v8::Value;

InfoTypeNumber::InfoTypeNumber(int value) {
    this->value = value;
}

InfoTypeNumber::InfoTypeNumber(float value) {
    this->value = value;
}

InfoTypeNumber::InfoTypeNumber(double value) {
    this->value = value;
}

InfoTypeNumber::~InfoTypeNumber() {
}

Handle<Value> InfoTypeNumber::getValue() {
    if (this->value.type() == typeid(static_cast<int>(0))) {
        return NanNew(boost::any_cast<int>(this->value));
    } else if (this->value.type() == typeid(static_cast<float>(0.0f))) {
        return NanNew(boost::any_cast<float>(this->value));
    } else if (this->value.type() == typeid(static_cast<double>(0.0))) {
        return NanNew(boost::any_cast<double>(this->value));
    } else {
        return NanUndefined();
    }
}
