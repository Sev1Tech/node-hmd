/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_TYPES_OVRSIZEI_OVRSIZEI_H_
#define SRC_SUPPORT_OVR_TYPES_OVRSIZEI_OVRSIZEI_H_

#include <node.h>

#include <HMDDeviceInfoElement.h>
#include <OVR_CAPI.h>

class OvrSizei : public HMDDeviceInfoElement {
 private:
    ovrSizei _value;

 public:
    explicit OvrSizei(ovrSizei value);
    ~OvrSizei();

    v8::Handle<v8::Value> getValue();
    HMDDeviceInfoElement* clone();
};

#endif  // SRC_SUPPORT_OVR_TYPES_OVRSIZEI_OVRSIZEI_H_
