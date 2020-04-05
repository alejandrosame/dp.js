#include "status_js.h"

#include "node_binding/constructor.h"
#include "node_binding/type_convertor.h"

using namespace node_binding;

Napi::FunctionReference StatusJs::constructor_;

void StatusJs::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(
        env, "Status",
        {
            //InstanceMethod("message", &StatusJs::message),
        }
    );

    constructor_ = Napi::Persistent(func);
    constructor_.SuppressDestruct();

    exports.Set("Status", func);
}

StatusJs::StatusJs(const Napi::CallbackInfo& info) : Napi::ObjectWrap<StatusJs>(info) {
    if(info.Length() == 0) {
        status_ = TypedConstruct(info, &Constructor<dp::Status>::Call<>);
    } 
    // else if (info.Length() == 2) {
    //     status_ = TypedConstruct(info, &Constructor<dp::Status>::Call<const dp::StatusCode&, const absl::string_view&>);
    // } 
    else {
        Napi::Env env = info.Env();
        THROW_JS_WRONG_NUMBER_OF_ARGUMENTS(env);
    }
}

// Napi::Value StatusJs::message(const Napi::CallbackInfo& info) {
//     return TypedCall(info, &dp::Status::message, &status_);
// }