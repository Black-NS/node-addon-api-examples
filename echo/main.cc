#include "main.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    Echo::Initialize(env, exports);   
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);