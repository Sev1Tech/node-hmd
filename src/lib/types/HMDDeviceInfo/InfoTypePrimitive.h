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
 public:
	InfoTypePrimitive(T value) {
		this->value = value;
	}

    ~InfoTypePrimitive() {
    }

    v8::Handle<v8::Value> getValue() {
	    return NanNew(value);
	}
 private:
    T value;
};

#define InfoTypeBoolean(x) InfoTypePrimitive<bool>(x)
#define InfoTypeShort(x) InfoTypePrimitive<short>(x)
#define InfoTypeInt(x) InfoTypePrimitive<int>(x)
#define InfoTypeUInt(x) InfoTypePrimitive<unsigned int>(x)
#define InfoTypeFloat(x) InfoTypePrimitive<float>(x)
#define InfoTypeDouble(x) InfoTypePrimitive<double>(x)
#define InfoTypeString(x) InfoTypePrimitive<std::string>(x)

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEPRIMITIVE_H_
