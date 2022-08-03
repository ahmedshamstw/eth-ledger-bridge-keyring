#include <napi.h>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
extern "C" {
  #include "test_api.h" //a C header, so wrap it in extern "C" 
}

Napi::Value Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();
  Napi::Number num = Napi::Number::New(env, arg0 + arg1);

  return num;
}

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  // int a=4;
  
  // std::string var =helloUser("test from callback c file");
  // std::string *ip;
  // ip = &var;
  // *ip+=" Second Part Of String Added By Pointer From Another File";
  return Napi::String::New(env, "ThirdWayv Calling From Cpp");
}

Napi::String SumWithPointer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  // status = napi_call_function(env, global, add_two, argc, argv, &return_val);

  return Napi::String::New(env, "TWI Test Stringhh");
}

Napi::Value CallEmit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function emit = info[0].As<Napi::Function>();
  emit.Call({Napi::String::New(env, "helloworld")});

  for (int i = 0; i < 3; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    emit.Call(
        {Napi::String::New(env, "data"), Napi::String::New(env, "thirdwaYVE ...")});
  }
  // emit.Call({Napi::String::New(env, "end")});
  return Napi::String::New(env, "OK");
}

void RunCallback(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function cb = info[0].As<Napi::Function>();
  cb.Call({Napi::String::New(env, "helloworld")});
}
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "pointer"), Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "string"), Napi::Function::New(env, SumWithPointer));
  exports.Set(Napi::String::New(env, "callback"), Napi::Function::New(env, Add));
  exports.Set(Napi::String::New(env, "secondCallback"), Napi::Function::New(env, RunCallback));
  exports.Set(Napi::String::New(env, "callEmit"),Napi::Function::New(env, CallEmit));
  return exports;
}

NODE_API_MODULE(helloeeee, Init)
