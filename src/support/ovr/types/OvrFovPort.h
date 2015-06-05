/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_TYPES_OVRFOVPORT_H_
#define SRC_SUPPORT_OVR_TYPES_OVRFOVPORT_H_

#include <nan/nan.h>
#include <node.h>

#include <HMDDeviceInfoElement.h>
#include <OVR_CAPI.h>

/*! \class ovrFovPort
 *
 * HMDDeviceInfoElement implementation for LibOVR ovrFovPort type.
 */
class OvrFovPort : public HMDDeviceInfoElement {
 private:
    ovrFovPort _value;

 public:
    explicit OvrFovPort(ovrFovPort value);
    ~OvrFovPort();

    v8::Handle<v8::Value> getValue();
    HMDDeviceInfoElement* clone();
};

/*! \class OvrFovPortWrap
 *
 * Node wrapped object class for OvrFovPort.
 */
class OvrFovPortWrap : public node::ObjectWrap {
 private:
    ovrFovPort _ovrFovPort;

    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetObjectProperty);

 public:
     OvrFovPortWrap();
     ~OvrFovPortWrap();
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    ovrFovPort* GetWrapped();
};

#endif  // SRC_SUPPORT_OVR_TYPES_OVRFOVPORT_H_
