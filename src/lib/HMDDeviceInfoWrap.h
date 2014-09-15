/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDDEVICEINFOWRAP_H
#define HMDDEVICEINFOWRAP_H

#include <node.h>
#include <nan.h>

#include "HMDDevice.h"

using namespace v8;

/*! \class HMDDeviceInfoWrap
 * 
 * Node wrapped object class for HMDDeviceInfo.
 */
class HMDDeviceInfoWrap : public node::ObjectWrap {
    private:
        HMDDeviceInfo* _hmdDeviceInfo;

        HMDDeviceInfoWrap();
        ~HMDDeviceInfoWrap();
        static Persistent<Function> constructor;
        static NAN_GETTER(GetDeviceInfoProperty);

    public:
        static void Initialize(Handle<Object> target);
        static NAN_METHOD(New);
        HMDDeviceInfo* GetWrapped();
};

#endif