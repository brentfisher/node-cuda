#include <node.h>
#include <string>

using namespace v8;

Handle<Value> RunTest(const Arguments& args) {
    HandleScope scope;

    if (args.Length() < 1) {
        return ThrowException(
            Exception::TypeError(String::New("Send me some args dawg!"))
        );
    }

    Local<String> mystr = args[0]->ToString();
    std::string str = "foo";

    return scope.Close(String::New("Hello from cpp"));
}

void RegisterModule(Handle<Object> target) {
    target->Set(String::NewSymbol("cudatest"),
        FunctionTemplate::New(RunTest)->GetFunction());
}

NODE_MODULE(cudatest, RegisterModule);
