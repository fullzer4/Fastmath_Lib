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

      double valueSum = args[i].As<Number>()->Value();
      sum += valueSum;
    }


    auto result = Number::New(isolate, sum);
    args.GetReturnValue().Set(result);    
  }

  void Sub(const FunctionCallbackInfo<Value>&args) {
    Isolate* isolate = args.GetIsolate();

    double sub = 0.0;

    for (int i = 0; i < args.Length(); i++) {
      if (!args[i]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Os parametros devem ser numeros").ToLocalChecked()));
        return;
      }

      if ( i == args.Length() - 1){
        return;
      }

      int vp = i + 1;
      
      if ( i == 0 ){
        double v1 = args[i].As<Number>()->Value();
        double v2 = args[vp].As<Number>()->Value();
        sub = v1 - v2;
      }


      sub = sub - args[vp].As<Number>()->Value();
    }

    auto result = Number::New(isolate, sub);
    args.GetReturnValue().Set(result);
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "sum", Sum);
    NODE_SET_METHOD(exports, "sub", Sub);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
