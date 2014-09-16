/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_LIB_HMDMANAGERWRAP_H_
#define SRC_LIB_HMDMANAGERWRAP_H_

#include <node.h>
#include <nan.h>

#include "HMDDevice.h"

/*! \struct AsyncDeviceRequest
 * 
 * Struct designed to handle state and data associated with asynchronous device communication requests.
 */
// struct AsyncDeviceRequest {
//  uv_work_t workRequest;
//  Persistent<Function> callback;
//  const Arguments* context;

//  HMDDevice* hmdDevice;
//  void* requestData;
// };

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

    // static Handle<Value> GetDeviceInfoAsync(const Arguments& args);
    // static void GetDeviceInfoRequestAsync(uv_work_t *r);
    // static void GetDeviceInfoRequestAfterAsync(uv_work_t *r);
    // static Handle<Value> GetDeviceInfoSync(const Arguments& args);
    // static Handle<Value> GetDeviceOrientationAsync(const Arguments& args);
    // static void GetDeviceOrientationRequestAsync(uv_work_t *r);
    // static void GetDeviceOrientationRequestAfterAsync(uv_work_t *r);
    static NAN_METHOD(GetDeviceOrientationSync);

 public:
    static void Initialize(v8::Handle<v8::Object> target);
    static NAN_METHOD(New);
    HMDDevice* GetDevice();
};

#endif  // SRC_LIB_HMDMANAGERWRAP_H_
