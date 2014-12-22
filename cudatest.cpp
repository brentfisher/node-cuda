#include <node.h>
#include <string>

using namespace v8;

Handle<Value> RunTest(const Arguments& args) {
    HandleScope scope;

    if (!args[0]->IsString()) {
        return ThrowException(Exception::TypeError(
            String::New("First argument must be a string")));
    }
    if (!args[1]->IsFunction()) {
        return ThrowException(Exception::TypeError(
            String::New("Second argument must be a callback function")));
    }

    Local<String> mystr = args[0]->ToString();
    Local<Function> callback = Local<Function>::Cast(args[1]);

    const unsigned argc = 2;
    Local<Value> argv[argc] = {
      Local<Value>::New(Null()),
      Local<Value>::New(mystr)
    };

    callback->Call(Context::GetCurrent()->Global(), argc, argv);

    return Undefined();
    // return scope.Close(mystr);
}

void RegisterModule(Handle<Object> target) {
    target->Set(String::NewSymbol("cudatest"),
        FunctionTemplate::New(RunTest)->GetFunction());
}

NODE_MODULE(cudatest, RegisterModule);
