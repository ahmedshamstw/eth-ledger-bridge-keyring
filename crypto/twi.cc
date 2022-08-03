#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "TWI Test String ");
}
Napi::String SumWithPointer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "TWI Test From File TWI");
}
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hellor"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "testAnotherFunction"),
              Napi::Function::New(env, SumWithPointer));
  return exports;
}

NODE_API_MODULE(twi, Init)
