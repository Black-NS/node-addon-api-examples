#ifndef __ECHO__HEADER__
#define __ECHO__HEADER__

#include <napi.h>

class Echo : public Napi::AsyncWorker
{
    public:
        // constructor
        Echo(Napi::Function&, std::string msg);
        ~Echo();

        // initialize function
        static void Initialize(Napi::Env, Napi::Object);

        // deinitialize function
        static void Deinitialize(void *);

        // call
        void Execute();
        void OnOK();

        // member values
        std::string getMessage();

    private:
        std::string msg;
};

#endif