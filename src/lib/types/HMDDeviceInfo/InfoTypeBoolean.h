/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEBOOLEAN_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEBOOLEAN_H_

#include <node.h>

#include "HMDDeviceInfoElement.h"

/*! \class InfoTypeBoolean
 * 
 * 
 */
class InfoTypeBoolean  : public HMDDeviceInfoElement{
 public:
    explicit InfoTypeBoolean(bool value);
    ~InfoTypeBoolean();

    v8::Handle<v8::Value> getValue();
 private:
    bool value;
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_INFOTYPEBOOLEAN_H_
