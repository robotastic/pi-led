#include <node/node.h>
#include <napi.h>
#include <node/node_object_wrap.h>

#include <nan.h>



#include "led-matrix.h"

using namespace std;
using namespace v8;
using namespace node;


extern "C"  {
#include "wiringPiSPI.h"
#include "wiringPi.h"
}


class PiWorker : public Napi::AsyncWorker {
 public:
  //PiWorker(Napi::Function& callback, string message, Napi::Function& emit )
  //    : Napi::AsyncWorker(callback), message(message), emit(emit) {}
  PiWorker(Napi::Function& callback, string message )  
    : Napi::AsyncWorker(callback), message(message) {}
  ~PiWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute () {
    ledMatrix = new LedMatrix(4);
    ledMatrix->writeMessage(message.c_str());
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Napi::HandleScope scope(Env());
    Callback().Call({Env().Undefined(), Napi::Number::New(Env(), 1)});

    
  }

 private:
  string message;
  //Napi::Function& emit;
  LedMatrix *ledMatrix;
};

// Asynchronous access to the `Estimate()` function
Napi::Value WriteMessage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  //Napi::Function emit = info[2].As<Napi::Function>();
  string message = info[0].As<Napi::String>().Utf8Value();
  Napi::Function callback = info[1].As<Napi::Function>();
  PiWorker* piWorker = new PiWorker(callback, message);
  //PiWorker* piWorker = new PiWorker(callback, message, emit);
  //emit.Call({Napi::String::New(env, "end")});
  piWorker->Queue();
  return info.Env().Undefined();

}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "writeMessage"), Napi::Function::New(env, WriteMessage));
   return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)





