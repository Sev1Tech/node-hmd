#ifndef HMDINFOCOLORWRAP_H
#define HMDINFOCOLORWRAP_H

#include <node.h>

#include "OVR.h"

using namespace v8;

class HMDInfoWrap : public node::ObjectWrap {
	private:
		// Wrapped Object
		OVR::HMDInfo* _hmdInfo;

		// Class Methods
		HMDInfoWrap();
		~HMDInfoWrap();

		// Required V8 Methods
		static Persistent<Function> constructor;
		static Handle<Value> New(const Arguments& args);

		// Wrapped Property Methods
		static Handle<Value> HResolution(const v8::Arguments& args);

	public:
		static void Initialize(Handle<Object> target);
		static Handle<Value> NewInstance(const Arguments& args);
		OVR::HMDInfo* GetWrapped();
};

#endif