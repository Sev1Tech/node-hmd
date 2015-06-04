/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>
#include <node.h>
#include <v8.h>

#include <HMDDeviceFactory.h>
#include <HMDDeviceInfo.h>
#include <HMDDeviceOrientation.h>
#include <HMDDevicePosition.h>
#include <HMDDeviceQuat.h>
#include <HMDManager.h>

#include <string>
#include <vector>

using ::v8::Array;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::String;
using ::v8::Value;

NAN_METHOD(CreateManager) {
    NanScope();

    HMDManagerWrap::NewInstance(args);
}

NAN_METHOD(GetSupportedDevices) {
    NanScope();
    std::vector<std::string> supported = HMDDeviceFactory::getSupportedDevices();

    Local<Array> array = NanNew<Array>(supported.size());
    int i = 0;

    for (std::vector<std::string>::iterator it = supported.begin(); it != supported.end(); it++) {
        array->Set(i++, NanNew(*it));
    }

    NanReturnValue(array);
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
    HMDDeviceInfoWrap::Initialize(exports);
    HMDDeviceOrientationWrap::Initialize(exports);
    HMDDevicePositionWrap::Initialize(exports);
    HMDDeviceQuatWrap::Initialize(exports);
    HMDManagerWrap::Initialize(exports);

    HMDDeviceFactory::initializeModule(exports);

    exports->Set(NanNew("createManager"), NanNew<FunctionTemplate>(CreateManager)->GetFunction());
    exports->Set(NanNew("getSupportedDevices"), NanNew<FunctionTemplate>(GetSupportedDevices)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
