#include <node.h>

namespace math { 
  using v8::FunctionCallbackInfo; 
  using v8::Isolate; 
  using v8::Local;
  using v8::Object;
  using v8::Number;
  using v8::Value;
  using v8::Exception;
  using v8::String;

  void Sum(const FunctionCallbackInfo<Value>&args) {
    Isolate* isolate = args.GetIsolate();

    double sum = 0.0; 

    for (int i = 0; i < args.Length(); i++) {
      if (!args[i]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Os parâmetros devem ser números").ToLocalChecked()));
        return;
      }

      double value = args[i].As<Number>()->Value();
      sum += value;
    }


    auto result = Number::New(isolate, sum);
    args.GetReturnValue().Set(result);    
  }

  void Sub(const FunctionCallbackInfo<Value>&args) {
    Isolate* isolate = args.GetIsolate();

    double sub = 0.0;


  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "sum", Sum);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
