/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_

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
 private:
    std::vector<T> _value;

 public:
    InfoTypeArray(int length, ...) {
        va_list arguments;

        va_start(arguments, length);
        for (int i = 0; i < length; i++) {
            this->_value.push_back(va_arg(arguments, T));
        }

        va_end(arguments);
    }

    InfoTypeArray(T* elements, int length) {
        for (int i = 0; i < length; i++) {
            this->_value.push_back(elements[i]);
        }
    }

    explicit InfoTypeArray(std::vector<T> values) {
        for (typename std::vector<T>::size_type i = 0; i < values.size(); i++) {
            this->_value.push_back(values[i]);
        }
    }

    ~InfoTypeArray() {
    }

    v8::Handle<v8::Value> getValue() {
        v8::Local<v8::Array> array = NanNew<v8::Array>(this->_value.size());

        for (typename std::vector<T>::size_type i = 0; i < this->_value.size(); i++) {
            array->Set(i, NanNew(this->_value[i]));
        }

        return array;
    }

    HMDDeviceInfoElement* clone() {
        return new InfoTypeArray<T>(this->_value);
    }
};

template<>
class InfoTypeArray<HMDDeviceInfoElement *> : public HMDDeviceInfoElement {
 private:
    std::vector<HMDDeviceInfoElement *> _value;

 public:
    InfoTypeArray(int length, ...) {
        va_list arguments;

        va_start(arguments, length);
        for (int i = 0; i < length; i++) {
            this->_value.push_back(va_arg(arguments, HMDDeviceInfoElement *));
        }

        va_end(arguments);
    }

    InfoTypeArray(HMDDeviceInfoElement** elements, int length) {
        for (int i = 0; i < length; i++) {
            this->_value.push_back(elements[i]);
        }
    }

    explicit InfoTypeArray(std::vector<HMDDeviceInfoElement *> values) {
        for (typename std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < values.size(); i++) {
            this->_value.push_back(values[i]->clone());
        }
    }

    ~InfoTypeArray() {
        for (typename std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->_value.size(); i++) {
            delete this->_value[i];
        }
    }

    v8::Handle<v8::Value> getValue() {
        v8::Local<v8::Array> array = NanNew<v8::Array>(this->_value.size());

        for (typename std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->_value.size(); i++) {
            array->Set(i, NanNew(this->_value[i]->getValue()));
        }

        return array;
    }

    HMDDeviceInfoElement* clone() {
        return new InfoTypeArray<HMDDeviceInfoElement *>(this->_value);
    }
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEARRAY_H_
