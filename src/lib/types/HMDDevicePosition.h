/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEPOSITION_H_
#define SRC_LIB_TYPES_HMDDEVICEPOSITION_H_

#include <nan/nan.h>
#include <node.h>

/*! \class HMDDevicePosition
 *
 * Basic property class containg position state about the device.
 */
class HMDDevicePosition {
 protected:
    float _x;
    float _y;
    float _z;

 public:
    HMDDevicePosition();
    ~HMDDevicePosition();

    void setPosition(float x, float y, float z);
    void setPosition(HMDDevicePosition deviceOrientation);

    float getX() const;
    float getY() const;
    float getZ() const;

    HMDDevicePosition& operator= (const HMDDevicePosition &devicePosition);
};

/*! \class HMDDevicePositionWrap
 *
 * Node wrapped object class for HMDDevicePosition.
 */
class HMDDevicePositionWrap : public node::ObjectWrap {
 private:
    HMDDevicePosition* _hmdDevicePosition;

    HMDDevicePositionWrap();
    ~HMDDevicePositionWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetDevicePositionProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    HMDDevicePosition* GetWrapped();
};

#endif  // SRC_LIB_TYPES_HMDDEVICEPOSITION_H_
