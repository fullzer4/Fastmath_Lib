#include <node/v8.h>
#include <node/node.h>
#include "divops.cpp"
#include "sumops.cpp"
#include "subops.cpp"
#include "matops.cpp"
#include "multops.cpp"

namespace lib {

  using v8::Local;
  using v8::Object;


  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "sumAll", sumops::SumAll);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
