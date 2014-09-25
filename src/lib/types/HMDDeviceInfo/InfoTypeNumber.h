/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPENUMBER_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPENUMBER_H_

#include <boost/any.hpp>
#include <node.h>

#include "HMDDeviceInfoElement.h"

/*! \class InfoTypeNumber
 * 
 * 
 */
class InfoTypeNumber : public HMDDeviceInfoElement {
 public:
    explicit InfoTypeNumber(int value);
    explicit InfoTypeNumber(float value);
    explicit InfoTypeNumber(double value);
    ~InfoTypeNumber();

    v8::Handle<v8::Value> getValue();
 private:
    boost::any value;
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPENUMBER_H_
