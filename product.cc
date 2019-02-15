#include <nan.h>
#include <math.h>

void productIntf(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  // validate input data size and type
  if (info.Length() < 2) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }
  if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  // reading args
  double arg0 = info[0]->NumberValue();
  double arg1 = info[1]->NumberValue();
  double arg2 = info[2]->NumberValue();

  // invoke c++ function
  for (int i = 0; i < arg2; i++) {
    double product = arg0 * arg1;
  }

  // prepare return value
  v8::Local<v8::Number> retVal = Nan::New(0); // ignore the output

  //altering object reference "info"
  info.GetReturnValue().Set(retVal);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(
    Nan::New("product").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(productIntf)->GetFunction());
}

NODE_MODULE(product, Init)