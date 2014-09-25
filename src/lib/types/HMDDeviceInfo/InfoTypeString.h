/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPESTRING_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPESTRING_H_

#include <node.h>

#include <string>

#include "HMDDeviceInfoElement.h"

/*! \class InfoTypeString
 * 
 * 
 */
class InfoTypeString  : public HMDDeviceInfoElement{
 public:
    explicit InfoTypeString(std::string value);
    ~InfoTypeString();

    v8::Handle<v8::Value> getValue();
 private:
    std::string value;
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPESTRING_H_
