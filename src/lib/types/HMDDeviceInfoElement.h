/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFOELEMENT_H_
#define SRC_LIB_TYPES_HMDDEVICEINFOELEMENT_H_

#include <nan/nan.h>
#include <node.h>

#include <cstdarg>
#include <string>
#include <vector>

/*! \class HMDDeviceInfoElement
 *
 * Base class describing an element of device information with V8 conversion interface.
 */
class HMDDeviceInfoElement {
 public:
    virtual ~HMDDeviceInfoElement() { }

    virtual v8::Handle<v8::Value> getValue() = 0;
    virtual HMDDeviceInfoElement* clone() = 0;
};

/*! \class InfoTypePrimitive
 *
 * Template for implementing a HMDDeviceInfoElement class for primitive types.
 * See: InfoTypeBoolean, InfoTypeDouble, InfoTypeFloat, InfoTypeInt, InfoTypeLong, InfoTypeShort, InfoTypeString, InfoTypeUInt
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

/*! \class InfoTypeArray
 *
 * Specialized implementation of HMDDeviceInfoElement for arrays of primitives objects.
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

/*! \class InfoTypeArray<HMDDeviceInfoElement *>
 *
 * Template specialization for InfoTypeArray containing a list of HMDDeviceInfoElement pointers.
 */
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
        for (std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < values.size(); i++) {
            this->_value.push_back(values[i]->clone());
        }
    }

    ~InfoTypeArray() {
        for (std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->_value.size(); i++) {
            delete this->_value[i];
        }
    }

    v8::Handle<v8::Value> getValue() {
        v8::Local<v8::Array> array = NanNew<v8::Array>(this->_value.size());

        for (std::vector<HMDDeviceInfoElement *>::size_type i = 0; i < this->_value.size(); i++) {
            array->Set(i, NanNew(this->_value[i]->getValue()));
        }

        return array;
    }

    HMDDeviceInfoElement* clone() {
        return new InfoTypeArray<HMDDeviceInfoElement *>(this->_value);
    }
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFOELEMENT_H_
