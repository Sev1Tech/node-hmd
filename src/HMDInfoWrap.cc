#include <node.h>

#include "HMDInfoWrap.h"

using namespace v8;

Persistent<Function> HMDInfoWrap::constructor;

HMDInfoWrap::HMDInfoWrap() {
	_hmdInfo = new OVR::HMDInfo();
}

HMDInfoWrap::~HMDInfoWrap() {
	delete _hmdInfo;
}

void HMDInfoWrap::Initialize(Handle<Object> target) {
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("HMDInfo"));

	tpl->PrototypeTemplate()->Set(String::NewSymbol("HResolution"),  FunctionTemplate::New(HResolution)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("HMDInfo"), constructor);
}

Handle<Value> HMDInfoWrap::New(const Arguments& args) {
	HandleScope scope;

	HMDInfoWrap* w = new HMDInfoWrap();
	w->Wrap(args.This());

	return args.This();
}

Handle<Value> HMDInfoWrap::NewInstance(const Arguments& args) {
	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	Local<Object> instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

OVR::HMDInfo* HMDInfoWrap::GetWrapped() {
	return _hmdInfo;
}


Handle<Value> HMDInfoWrap::HResolution(const v8::Arguments& args) {
	HandleScope scope;

	HMDInfoWrap* w = ObjectWrap::Unwrap<HMDInfoWrap>(args.This());
	OVR::HMDInfo* hmdInfo = w->GetWrapped();

	return scope.Close(Number::New((*hmdInfo).HResolution));
}