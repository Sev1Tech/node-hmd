/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <nan/nan.h>
#include <node.h>
#include <v8.h>

#include <string>
#include <vector>

#include "HMDDeviceFactory.h"
#include "HMDDeviceInfoWrap.h"
#include "HMDDeviceOrientationWrap.h"
#include "HMDDevicePositionWrap.h"
#include "HMDDeviceQuatWrap.h"
#include "HMDManagerWrap.h"

#include <OvrFovPortWrap.h>
#include <OvrSizeiWrap.h>
#include <OvrVector2iWrap.h>

using ::v8::Array;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Local;
using ::v8::Object;
using ::v8::String;
using ::v8::TryCatch;
using ::v8::Value;

NAN_METHOD(CreateManager) {
    NanScope();

    NanReturnValue(HMDManagerWrap::New(args));
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

    OvrFovPortWrap::Initialize(exports);
    OvrSizeiWrap::Initialize(exports);
    OvrVector2iWrap::Initialize(exports);

    exports->Set(NanNew<String>("createManager"), NanNew<FunctionTemplate>(CreateManager)->GetFunction());
    exports->Set(NanNew<String>("getSupportedDevices"), NanNew<FunctionTemplate>(GetSupportedDevices)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
