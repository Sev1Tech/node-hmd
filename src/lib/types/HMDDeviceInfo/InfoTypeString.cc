/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>
#include <node.h>

#include "InfoTypeString.h"

using ::v8::Handle;
using ::v8::Value;

InfoTypeString::InfoTypeString(std::string value) {
    this->value = value;
}

InfoTypeString::~InfoTypeString() {
}

Handle<Value> InfoTypeString::getValue() {
    return NanNew(this->value);
}
