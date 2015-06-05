/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_H_
#define SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_H_

#include <nan/nan.h>
#include <node.h>

#include <HMDDeviceInfoElement.h>
#include <OVR_CAPI.h>

/*! \class OvrVector2i
 *
 * HMDDeviceInfoElement implementation for LibOVR ovrVector2i type.
 */
class OvrVector2i : public HMDDeviceInfoElement {
 private:
    ovrVector2i _value;

 public:
    explicit OvrVector2i(ovrVector2i value);
    ~OvrVector2i();

    v8::Handle<v8::Value> getValue();
    HMDDeviceInfoElement* clone();
};

/*! \class OvrVector2iWrap
 *
 * Node wrapped object class for OvrVector2i.
 */
class OvrVector2iWrap : public node::ObjectWrap {
 private:
    ovrVector2i _ovrVector2i;

    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetObjectProperty);

 public:
     OvrVector2iWrap();
     ~OvrVector2iWrap();
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    ovrVector2i* GetWrapped();
};

#endif  // SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_H_
