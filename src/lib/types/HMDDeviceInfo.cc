/*
 * Copyright (c) 2013-2015 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <HMDDeviceInfo.h>

#include <map>
#include <string>
#include <vector>

/*
 * HMDDeviceInfoWrap
 */

HMDDeviceInfo::HMDDeviceInfo()
    : _deviceInformation(std::map<std::string, HMDDeviceInfoElement*>()) {
}

HMDDeviceInfo::~HMDDeviceInfo() {
    for (std::map<std::string, HMDDeviceInfoElement*>::iterator iter = this->_deviceInformation.begin(); iter != this->_deviceInformation.end(); ++iter) {
        delete iter->second;
    }

    this->_deviceInformation.clear();
}

std::map<std::string, HMDDeviceInfoElement*> HMDDeviceInfo::getDeviceInfo() const {
    return this->_deviceInformation;
}

HMDDeviceInfoElement* HMDDeviceInfo::getElement(std::string name) {
    if (this->_deviceInformation.find(name) != this->_deviceInformation.end()) {
        return this->_deviceInformation[name];
    } else {
        throw ElementNotFoundError();
    }
}

void HMDDeviceInfo::insertElement(std::string name, HMDDeviceInfoElement* element) {
    this->_deviceInformation[name] = element;
}

HMDDeviceInfo& HMDDeviceInfo::operator= (const HMDDeviceInfo &deviceInfo) {
    std::map<std::string, HMDDeviceInfoElement*> deviceInformation = deviceInfo.getDeviceInfo();
    for (std::map<std::string, HMDDeviceInfoElement*>::iterator iter = deviceInformation.begin(); iter != deviceInformation.end(); ++iter) {
        this->insertElement(iter->first, iter->second->clone());
    }

    return *this;
}

/*
 * HMDDeviceInfoWrap
 */

using ::v8::Array;
using ::v8::Function;
using ::v8::FunctionTemplate;
using ::v8::Handle;
using ::v8::Integer;
using ::v8::Local;
using ::v8::Object;
using ::v8::ObjectTemplate;
using ::v8::Persistent;
using ::v8::Value;

Persistent<Function> HMDDeviceInfoWrap::constructor;

HMDDeviceInfoWrap::HMDDeviceInfoWrap()
    : _hmdDeviceInfo(new HMDDeviceInfo) {
}

HMDDeviceInfoWrap::~HMDDeviceInfoWrap() {
    delete this->_hmdDeviceInfo;
}

void HMDDeviceInfoWrap::Initialize(Handle<Object> exports) {
    Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
    tpl->SetClassName(NanNew("HMDDeviceInfo"));

    Handle<ObjectTemplate> instance = tpl->InstanceTemplate();
    instance->SetInternalFieldCount(1);
    instance->SetNamedPropertyHandler(GetDeviceInfoProperty, 0, 0, 0, DeviceInfoPropertyEnumerator);

    NanAssignPersistent<Function>(constructor, tpl->GetFunction());
    exports->Set(NanNew("HMDDeviceInfo"), NanNew(constructor));
}

NAN_METHOD(HMDDeviceInfoWrap::New) {
    NanScope();

    if (args.IsConstructCall()) {
        HMDDeviceInfoWrap* w = new HMDDeviceInfoWrap();
        w->Wrap(args.This());
        NanReturnValue(args.This());
    } else {
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        NanReturnValue(NanNew(constructor)->NewInstance(argc, argv));
    }
}

Handle<Object> HMDDeviceInfoWrap::CreateInstance() {
    return NanNew(constructor)->NewInstance();
}

HMDDeviceInfo* HMDDeviceInfoWrap::GetWrapped() {
    return this->_hmdDeviceInfo;
}

NAN_GETTER(HMDDeviceInfoWrap::GetDeviceInfoProperty) {
    NanScope();

    HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
    HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();
    try {
        HMDDeviceInfoElement* element = hmdDeviceInfo->getElement(*NanAsciiString(property));
        NanReturnValue(element->getValue());
    }
    catch (ElementNotFoundError &ex) {
        NanReturnUndefined();
    }
    NanReturnUndefined();
}

NAN_PROPERTY_ENUMERATOR(HMDDeviceInfoWrap::DeviceInfoPropertyEnumerator) {
    NanScope();

    HMDDeviceInfoWrap* w = ObjectWrap::Unwrap<HMDDeviceInfoWrap>(args.This());
    HMDDeviceInfo* hmdDeviceInfo = w->GetWrapped();

    const std::map<std::string, HMDDeviceInfoElement*> deviceInfo = hmdDeviceInfo->getDeviceInfo();
    Local<Array> properties = NanNew<Array>(deviceInfo.size());

    int i = 0;
    for (std::map<std::string, HMDDeviceInfoElement*>::const_iterator iter = deviceInfo.begin(); iter != deviceInfo.end(); ++iter) {
        properties->Set(i++, NanNew(iter->first.c_str()));
    }

    NanReturnValue(properties);
}
