#ifndef OVRCOORDINATORWRAP_H
#define OVRCOORDINATORWRAP_H

#include <node.h>

#include "OvrCoordinator.h"

using namespace v8;

class OvrCoordinatorWrap : public node::ObjectWrap {
	private:
		// Wrapped Object
		OvrCoordinator* _ovrCoordinator;

  		// Class Methods
		OvrCoordinatorWrap();
  		~OvrCoordinatorWrap();

		// Required V8 Methods
		static Persistent<Function> constructor;
		static Handle<Value> New(const Arguments& args);

		// Wrapped Property Methods
  		static Handle<Value> GetDeviceInfo(const Arguments& args);

	public:
  		static void Initialize(Handle<Object> target);
  		static Handle<Value> NewInstance(const Arguments& args);
  		OvrCoordinator* GetWrapped();
};

#endif