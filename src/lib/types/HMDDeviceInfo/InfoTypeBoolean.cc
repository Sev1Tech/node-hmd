/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>
#include <node.h>

#include "InfoTypeBoolean.h"

using ::v8::Handle;
using ::v8::Value;

InfoTypeBoolean::InfoTypeBoolean(bool value) {
    this->value = value;
}

InfoTypeBoolean::~InfoTypeBoolean() {
}

Handle<Value> InfoTypeBoolean::getValue() {
    return NanNew(this->value);
}
