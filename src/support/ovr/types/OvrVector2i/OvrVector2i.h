/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2I_H_
#define SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2I_H_

#include <node.h>

#include <HMDDeviceInfoElement.h>
#include <OVR_CAPI.h>

class OvrVector2i : public HMDDeviceInfoElement {
 private:
    ovrVector2i _value;

 public:
    explicit OvrVector2i(ovrVector2i value);
    ~OvrVector2i();

    v8::Handle<v8::Value> getValue();
    HMDDeviceInfoElement* clone();
};

#endif  // SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2I_H_
