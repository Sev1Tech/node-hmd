/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDMANAGERWRAP_H_
#define SRC_LIB_HMDMANAGERWRAP_H_

#include <node.h>
#include <nan/nan.h>

#include "HMDDevice.h"

/*! \class HMDManagerWrap
 * 
 * Node wrapped object class which acts as the main interface for the node-hmd module.
 */
class HMDManagerWrap : public node::ObjectWrap {
 private:
    HMDDevice* _hmdDevice;

    explicit HMDManagerWrap(const char* classToken);
    ~HMDManagerWrap();
    static v8::Persistent<v8::Function> constructor;

    static NAN_METHOD(GetDeviceInfoAsync);
    static NAN_METHOD(GetDeviceInfoSync);
    static NAN_METHOD(GetDeviceOrientationAsync);
    static NAN_METHOD(GetDeviceOrientationSync);
    static NAN_METHOD(GetDevicePositionAsync);
    static NAN_METHOD(GetDevicePositionSync);
    static NAN_METHOD(GetDeviceQuatAsync);
    static NAN_METHOD(GetDeviceQuatSync);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    HMDDevice* GetDevice();
};

/*! \class GetDeviceInfoWorker
 * 
 * NanAsyncWorker class for performing asynchronous device information work.
 */
class GetDeviceInfoWorker : public NanAsyncWorker {
 private:
    HMDDevice* hmdDevice;
    HMDDeviceInfo hmdDeviceInfo;
    v8::Arguments args;

 public:
    GetDeviceInfoWorker(NanCallback *callback, HMDDevice* hmdDevice, v8::Arguments args)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice), args(args) {}
    ~GetDeviceInfoWorker() {}

    void Execute();
    void HandleOKCallback();
};

/*! \class GetDeviceOrientationWorker
 * 
 * NanAsyncWorker class for performing asynchronous device orientation work.
 */
class GetDeviceOrientationWorker : public NanAsyncWorker {
 private:
    HMDDevice* hmdDevice;
    HMDDeviceOrientation hmdDeviceOrientation;
    v8::Arguments args;

 public:
    GetDeviceOrientationWorker(NanCallback *callback, HMDDevice* hmdDevice, v8::Arguments args)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice), args(args) {}
    ~GetDeviceOrientationWorker() {}

    void Execute();
    void HandleOKCallback();
};

/*! \class GetDevicePositionWorker
 * 
 * NanAsyncWorker class for performing asynchronous device orientation work.
 */
class GetDevicePositionWorker : public NanAsyncWorker {
 private:
    HMDDevice* hmdDevice;
    HMDDevicePosition hmdDevicePosition;
    v8::Arguments args;

 public:
    GetDevicePositionWorker(NanCallback *callback, HMDDevice* hmdDevice, v8::Arguments args)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice), args(args) {}
    ~GetDevicePositionWorker() {}

    void Execute();
    void HandleOKCallback();
};

/*! \class GetDeviceOrientationWorker
 * 
 * NanAsyncWorker class for performing asynchronous device quaternion work.
 */
class GetDeviceQuatWorker : public NanAsyncWorker {
 private:
    HMDDevice* hmdDevice;
    HMDDeviceQuat hmdDeviceQuat;
    v8::Arguments args;

 public:
    GetDeviceQuatWorker(NanCallback *callback, HMDDevice* hmdDevice, v8::Arguments args)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice), args(args) {}
    ~GetDeviceQuatWorker() {}

    void Execute();
    void HandleOKCallback();
};

#endif  // SRC_LIB_HMDMANAGERWRAP_H_
