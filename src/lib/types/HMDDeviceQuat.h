/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEQUAT_H_
#define SRC_LIB_TYPES_HMDDEVICEQUAT_H_

#include <nan/nan.h>
#include <node.h>

/*! \class HMDDeviceOrientation
 *
 * Basic property class containg quaternion state about the device.
 */
class HMDDeviceQuat {
 private:
    float _w;
    float _x;
    float _y;
    float _z;

 public:
    HMDDeviceQuat();
    ~HMDDeviceQuat();

    void setQuat(float w, float x, float y, float z);
    void setQuat(HMDDeviceQuat deviceQuat);

    float getW() const;
    float getX() const;
    float getY() const;
    float getZ() const;

    HMDDeviceQuat& operator= (const HMDDeviceQuat &deviceQuat);
};

/*! \class HMDDeviceQuatWrap
 *
 * Node wrapped object class for HMDDeviceQuat.
 */
class HMDDeviceQuatWrap : public node::ObjectWrap {
 private:
    HMDDeviceQuat* _hmdDeviceQuat;

    HMDDeviceQuatWrap();
    ~HMDDeviceQuatWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetDeviceQuatProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    HMDDeviceQuat* GetWrapped();
};

#endif  // SRC_LIB_TYPES_HMDDEVICEQUAT_H_
