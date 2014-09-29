/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2IWRAP_H_
#define SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2IWRAP_H_

#include <node.h>
#include <nan/nan.h>

#include <OVR_CAPI.h>

/*! \class OvrVector2iWrap
 * 
 * Node wrapped object class for OvrVector2i.
 */
class OvrVector2iWrap : public node::ObjectWrap {
 private:
    ovrVector2i _ovrVector2i;

    OvrVector2iWrap();
    ~OvrVector2iWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_GETTER(GetObjectProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    static v8::Handle<v8::Value> NewInstance();
    ovrVector2i* GetWrapped();
};

#endif  // SRC_SUPPORT_OVR_TYPES_OVRVECTOR2I_OVRVECTOR2IWRAP_H_
