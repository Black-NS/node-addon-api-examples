#include "echo.h"

Echo::Echo(Napi::Function& callback, std::string msg) 
: Napi::AsyncWorker(callback), msg(msg) {};

Echo::~Echo()
{
    // destroy
    return;
}
void Echo::Execute() {
    if ( this->getMessage().compare("quit") == 0) {
        SetError("Opps! Echo() is Quit, IF YOUR COMMAND('"+ this->getMessage() +"')");
        return;
    }
}

void Echo::OnOK() {
    Callback().Call({
        Env().Null(),
        Napi::String::New(Env(), this->msg)
    });
}

std::string Echo::getMessage() {
    return this->msg;
}

void Echo::Deinitialize(void * argc)
{
    // deactive
    return;
}

Napi::Value runEcho(const Napi::CallbackInfo& info) {
    Napi::String msg1 = info[0].Napi::DataView::As<Napi::String>();
    Napi::Function callback = info[1].Napi::DataView::As<Napi::Function>();

    Echo* echoWorker = new Echo(callback, msg1);
    echoWorker->Queue();
    return Napi::String::New(info.Env(), echoWorker->getMessage().c_str());
}

void Echo::Initialize(Napi::Env env, Napi::Object exports)
{
    napi_add_env_cleanup_hook(env, Echo::Deinitialize, nullptr);
    
    exports.Set("runEcho", Napi::Function::New(env, runEcho, std::string("runEcho")));

    return;
}