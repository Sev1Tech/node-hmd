/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDDEVICEORIENTATION_H_
#define SRC_LIB_TYPES_HMDDEVICEORIENTATION_H_

#include <nan/nan.h>
#include <node.h>

/*! \class HMDDeviceOrientation
 *
 * Basic property class containg orientation state about the device.
 */
class HMDDeviceOrientation {
 protected:
    float _yaw;
    float _pitch;
    float _roll;

 public:
    HMDDeviceOrientation();
    ~HMDDeviceOrientation();

    void setOrientation(float yaw, float pitch, float roll);
    void setOrientation(HMDDeviceOrientation deviceOrientation);

    float getYaw() const;
    float getPitch() const;
    float getRoll() const;

    HMDDeviceOrientation& operator= (const HMDDeviceOrientation &deviceOrientation);
};

/*! \class HMDDeviceOrientationWrap
 *
 * Node wrapped object class for HMDDeviceOrientation.
 */
class HMDDeviceOrientationWrap : public node::ObjectWrap {
 private:
    HMDDeviceOrientation* _hmdDeviceOrientation;

    HMDDeviceOrientationWrap();
    ~HMDDeviceOrientationWrap();
    static v8::Persistent<v8::Function> constructor;
    static NAN_METHOD(New);
    static NAN_GETTER(GetDeviceOrientationProperty);

 public:
    static void Initialize(v8::Handle<v8::Object> exports);
    static v8::Handle<v8::Object> CreateInstance();
    HMDDeviceOrientation* GetWrapped();
};

#endif  // SRC_LIB_TYPES_HMDDEVICEORIENTATION_H_
