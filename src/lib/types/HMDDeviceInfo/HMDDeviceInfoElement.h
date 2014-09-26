/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOELEMENT_H_
#define SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOELEMENT_H_

#include <node.h>
 
/*! \class HMDDeviceInfoElement
 * 
 * 
 */
class HMDDeviceInfoElement {
 public:
    virtual ~HMDDeviceInfoElement() { }

    virtual v8::Handle<v8::Value> getValue() = 0;
    virtual HMDDeviceInfoElement* clone() = 0;
};

#endif  // SRC_LIB_TYPES_HMDDEVICEINFO_HMDDEVICEINFOELEMENT_H_
