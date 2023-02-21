#include "main.h"

Hello::Hello(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Hello>(info)
{
    // constructor
    return;
}

Hello::~Hello()
{
    // destroy
    return;
}

void Hello::Deinitialize(void * argc)
{
    // deactive
    return;
}

Napi::Value Hello::HelloMethod(const Napi::CallbackInfo& info) 
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Method :: Hello, Universe!");
} 

Napi::String Hello::HelloFunc(const Napi::CallbackInfo& info) 
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Function :: Hello, Universe!");
}

void Hello::Initialize(Napi::Env env, Napi::Object exports)
{
    napi_add_env_cleanup_hook(env, Hello::Deinitialize, nullptr);
    
    Napi::Function ctor = DefineClass(env, "Hello", {
        // method
        InstanceMethod("innerMethod", &Hello::HelloMethod)
    });
    
    exports.Set("Hello", ctor);
    exports.Set("outerMethod", Napi::Function::New(env, &Hello::HelloFunc));

    return;
}


Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    Hello::Initialize(env, exports);   
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);