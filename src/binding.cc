#include <node.h>
#include <v8.h>

#include "HMDInfoWrap.h"
#include "OvrCoordinatorWrap.h"

using namespace v8;

Handle<Value> CreateObject(const Arguments& args) {
	HandleScope scope;
	return scope.Close(OvrCoordinatorWrap::NewInstance(args));
}

void RegisterModule(Handle<Object> exports, Handle<Object> module) {
	HMDInfoWrap::Initialize(exports);
	OvrCoordinatorWrap::Initialize(exports);

	module->Set(String::NewSymbol("exports"), FunctionTemplate::New(CreateObject)->GetFunction());
}

NODE_MODULE(ovr, RegisterModule);
