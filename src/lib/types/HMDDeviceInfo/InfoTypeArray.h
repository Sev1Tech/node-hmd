/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_

#include <boost/any.hpp>
#include <nan/nan.h>
#include <node.h>

#include <cstdarg>
#include <vector>

#include "HMDDeviceInfoElement.h"

/*! \class InfoTypeArray
 * 
 * 
 */
template<typename T>
class InfoTypeArray : public HMDDeviceInfoElement {
 public:
	InfoTypeArray(int length, ...) {
	    va_list arguments;

	    va_start(arguments, length);
	    for (int i = 0; i < length; i++) {
	        value.push_back(va_arg(arguments, T));
	    }

	    va_end(arguments);
	}

    ~InfoTypeArray() {
    }

    v8::Handle<v8::Value> getValue() {
	    v8::Local<v8::Array> array = NanNew<v8::Array>(this->value.size());

	    for (typename std::vector<T>::size_type i = 0; i < this->value.size(); i++) {
		    array->Set(i, NanNew(this->value[i]));
		}

	    return array;
	}
 private:
    std::vector<T> value;
};

template<>
class InfoTypeArray<HMDDeviceInfoElement *> : public HMDDeviceInfoElement {
 public:
	InfoTypeArray(int length, ...) {
	    va_list arguments;

	    va_start(arguments, length);
	    for (int i = 0; i < length; i++) {
	        value.push_back(va_arg(arguments, HMDDeviceInfoElement *));
	    }

	    va_end(arguments);
	}

    ~InfoTypeArray() {
	    for (typename std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->value.size(); i++) {
		    delete this->value[i];
		}
    }

    v8::Handle<v8::Value> getValue() {
	    v8::Local<v8::Array> array = NanNew<v8::Array>(this->value.size());

	    for (typename std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->value.size(); i++) {
		    array->Set(i, NanNew(this->value[i]->getValue()));
		}

	    return array;
	}
 private:
    std::vector<HMDDeviceInfoElement *> value;
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_
