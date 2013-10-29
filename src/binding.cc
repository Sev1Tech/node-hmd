#include <node.h>
#include <v8.h>

#include "HMDDeviceInfoWrap.h"
#include "HMDManagerWrap.h"

using namespace v8;

Handle<Value> CreateObject(const Arguments& args) {
	HandleScope scope;
	return scope.Close(HMDManagerWrap::NewInstance(args));
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
	HMDManagerWrap::Initialize(exports);
	HMDDeviceInfoWrap::Initialize(exports);

	module->Set(String::NewSymbol("exports"), FunctionTemplate::New(CreateObject)->GetFunction());
}

NODE_MODULE(hmd, RegisterModule);
