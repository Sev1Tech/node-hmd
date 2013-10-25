#include <node.h>
#include <v8.h>

#include "OVR.h"

using namespace v8;

Handle<Value> getPositionData(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "getPositionData", getPositionData);
}

NODE_MODULE(binding, init);
