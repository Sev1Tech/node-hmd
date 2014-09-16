/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan.h>
#include <node.h>
#include <v8.h>

#include <list>
#include <string>

#include "HMDDeviceFactory.h"
#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDManagerWrap.h"

using ::v8::Array;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::TryCatch;
using ::v8::String;
using ::v8::Value;

NAN_METHOD(CreateManager) {
    NanScope();

    TryCatch trycatch;
    Handle<Value> hmdManager = HMDManagerWrap::New(args);
    if (hmdManager.IsEmpty()) {
        NanReturnUndefined();
    } else {
        NanReturnValue(hmdManager);
    }
}

NAN_METHOD(GetSupportedDevices) {
    NanScope();
    std::list<std::string> supported = HMDDeviceFactory::getSupportedDevices();

    Local<Array> array = NanNew<Array>(supported.size());
    int i = 0;

    for (std::list<std::string>::iterator it = supported.begin(); it != supported.end(); it++) {
        array->Set(i++, NanNew(*it));
    }

    NanReturnValue(array);
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
    HMDDeviceInfoWrap::Initialize(exports);
    HMDDeviceOrientationWrap::Initialize(exports);
    HMDManagerWrap::Initialize(exports);

    exports->Set(NanNew<String>("createManager"), NanNew<FunctionTemplate>(CreateManager)->GetFunction());
    exports->Set(NanNew<String>("getSupportedDevices"), NanNew<FunctionTemplate>(GetSupportedDevices)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
