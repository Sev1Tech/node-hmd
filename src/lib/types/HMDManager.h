/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_TYPES_HMDMANAGER_H_
#define SRC_LIB_TYPES_HMDMANAGER_H_

#include <nan/nan.h>
#include <node.h>

#include <HMDDevice.h>

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
    static NAN_METHOD(New);

    static NAN_METHOD(GetDeviceInfoAsync);
    static NAN_METHOD(GetDeviceInfoSync);
    static NAN_METHOD(GetDeviceOrientationAsync);
    static NAN_METHOD(GetDeviceOrientationSync);
    static NAN_METHOD(GetDevicePositionAsync);
    static NAN_METHOD(GetDevicePositionSync);
    static NAN_METHOD(GetDeviceQuatAsync);
    static NAN_METHOD(GetDeviceQuatSync);


 public:
    static void Initialize(v8::Handle<v8::Object> exports);
    static NAN_METHOD(NewInstance);
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

 public:
    GetDeviceInfoWorker(NanCallback *callback, HMDDevice* hmdDevice)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice) {}
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

 public:
    GetDeviceOrientationWorker(NanCallback *callback, HMDDevice* hmdDevice)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice) {}
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

 public:
    GetDevicePositionWorker(NanCallback *callback, HMDDevice* hmdDevice)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice) {}
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

 public:
    GetDeviceQuatWorker(NanCallback *callback, HMDDevice* hmdDevice)
        : NanAsyncWorker(callback), hmdDevice(hmdDevice) {}
    ~GetDeviceQuatWorker() {}

    void Execute();
    void HandleOKCallback();
};

#endif  // SRC_LIB_TYPES_HMDMANAGER_H_
