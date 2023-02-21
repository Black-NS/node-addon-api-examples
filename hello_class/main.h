#include <napi.h>

class Hello : public Napi::ObjectWrap<Hello>
{
    public:
        // constructor
        Hello(const Napi::CallbackInfo&);
        ~Hello();

        // initialize function
        static void Initialize(Napi::Env, Napi::Object);

        // deinitialize function
        static void Deinitialize(void *);

        // call

        static Napi::String HelloFunc(const Napi::CallbackInfo&); 

        // member values

    private:
        Napi::Value HelloMethod(const Napi::CallbackInfo&);

};