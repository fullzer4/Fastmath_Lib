#include <node/node.h>
#include <node/v8-container.h>
#include <node/v8.h>

namespace sumops {
  using v8::FunctionCallbackInfo; 
  using v8::Isolate; 
  using v8::Local;
  using v8::Object;
  using v8::Number;
  using v8::Value;
  using v8::Exception;
  using v8::String;
  using v8::Array;

  void Sum(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 1 || !args[0]->IsArray()) {
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "O parâmetro deve ser um array de números").ToLocalChecked()));
      return;
    }

    Local<Array> numbersArray = Local<Array>::Cast(args[0]);
    double sum = 0.0;

    for (uint32_t i = 0; i < numbersArray->Length(); i++) {
      Local<Value> element = numbersArray->Get(i);
      if (!element->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "O array deve conter apenas números").ToLocalChecked()));
        return;
      }

      double value = element.As<Number>()->Value();
      sum += value;
    }

    args.GetReturnValue().Set(Number::New(isolate, sum));
  }
}
