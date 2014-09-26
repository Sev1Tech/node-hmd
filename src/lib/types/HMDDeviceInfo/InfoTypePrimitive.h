/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEPRIMITIVE_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEPRIMITIVE_H_

#include <nan/nan.h>
#include <node.h>

#include <string>

#include "HMDDeviceInfoElement.h"

/*! \class InfoTypePrimitive
 * 
 * 
 */
template<typename T>
class InfoTypePrimitive : public HMDDeviceInfoElement {
 private:
    T _value;

 public:
    explicit InfoTypePrimitive(T value) : _value(value) {
    }

    ~InfoTypePrimitive() {
    }

    v8::Handle<v8::Value> getValue() {
        return NanNew(this->_value);
    }

    HMDDeviceInfoElement* clone() {
    	return new InfoTypePrimitive<T>(this->_value);
    }
};

#define InfoTypeBoolean(x) InfoTypePrimitive<bool>(x)
#define InfoTypeDouble(x) InfoTypePrimitive<double>(x)
#define InfoTypeFloat(x) InfoTypePrimitive<float>(x)
#define InfoTypeInt(x) InfoTypePrimitive<int>(x)
#define InfoTypeLong(x) InfoTypePrimitive<int32_t>(x)
#define InfoTypeShort(x) InfoTypePrimitive<int16_t>(x)
#define InfoTypeString(x) InfoTypePrimitive<std::string>(x)
#define InfoTypeUInt(x) InfoTypePrimitive<unsigned int>(x)

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEPRIMITIVE_H_
