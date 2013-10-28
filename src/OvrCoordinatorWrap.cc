#include <node.h>

#include "HMDInfoWrap.h"
#include "OvrCoordinator.h"
#include "OvrCoordinatorWrap.h"

using namespace v8;

Persistent<Function> OvrCoordinatorWrap::constructor;

OvrCoordinatorWrap::OvrCoordinatorWrap() {
	_ovrCoordinator = OvrCoordinator::getInstance();
}

OvrCoordinatorWrap::~OvrCoordinatorWrap() {
}

void OvrCoordinatorWrap::Initialize(Handle<Object> target) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("OVRCoordinator"));

	tpl->PrototypeTemplate()->Set(String::NewSymbol("getDeviceInfo"), FunctionTemplate::New(GetDeviceInfo)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("OVRCoordinator"), constructor);
}

Handle<Value> OvrCoordinatorWrap::New(const Arguments& args) {
	HandleScope scope;

	OvrCoordinatorWrap* w = new OvrCoordinatorWrap();
	w->Wrap(args.This());

	return args.This();
}

Handle<Value> OvrCoordinatorWrap::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

OvrCoordinator* OvrCoordinatorWrap::GetWrapped() {
	return _ovrCoordinator;
}

Handle<Value> OvrCoordinatorWrap::GetDeviceInfo(const Arguments& args) {
	HandleScope scope;

	Handle<Value> hmdInfo = HMDInfoWrap::NewInstance(args);
	return scope.Close(hmdInfo);
}