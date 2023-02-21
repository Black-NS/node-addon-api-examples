#include <napi.h>

/*
* @descriptor   return hello universe string
* @param        Napi CallbackInfo Pointer
* @return       Hello Universe String
*/
Napi::String HelloUniverse(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env(); // get environment information;

    return Napi::String::New(env, "Hello, Universe!");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "Hello"), Napi::Function::New(env, HelloUniverse));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);