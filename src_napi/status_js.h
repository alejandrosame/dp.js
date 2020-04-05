#pragma once

#include "napi.h"
#include "node_binding/type_convertor.h"

#include "differential_privacy/base/status.h"

namespace dp = differential_privacy::base; 

class StatusJs: public Napi::ObjectWrap<StatusJs> {
    public:
        static void Init(Napi::Env env, Napi::Object exports);
        StatusJs(const Napi::CallbackInfo& info);

        //Napi::Value message(const Napi::CallbackInfo& info);

    private:
        static Napi::FunctionReference constructor_;

        dp::Status status_;
};