#include <nan.h>
#include <math.h>

using namespace std;

void multiplicationPerf(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  // validate input data size and type
  if (info.Length() != 3) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }
  if (!info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber()) {
    Nan::ThrowTypeError("Argument type error found ");
    return;
  }

  // reading args
  double a = info[0]->NumberValue();
  double b = info[1]->NumberValue();
  double loops = info[2]->NumberValue();
  
  // invoke c++ function
  for (int i = 0; i < loops; i++) {
    double product = a * b;
  }

  // prepare return value and assign it to info
  v8::Local<v8::Number> retVal = Nan::New(0); // ignore the output
  info.GetReturnValue().Set(retVal);
}

void generateMessage(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  // validate input data size and type
  if (info.Length() != 2) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }
  
  // reading args
  int num = info[0]->NumberValue();
  v8::Local<v8::Function> cb = info[1].As<v8::Function>();

  // execute callback
  string str = "The number you entered: " + to_string(num);
  string verb = "INFO";
  
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = {Nan::New(str).ToLocalChecked()};
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(
    Nan::New("multiplicationPerf").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(multiplicationPerf)->GetFunction()
  );
  exports->Set(
    Nan::New("generateMessage").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(generateMessage)->GetFunction()
  );
}

NODE_MODULE(function_definition, Init)