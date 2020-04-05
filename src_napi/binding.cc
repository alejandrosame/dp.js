#include "status_js.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    StatusJs::Init(env, exports);
    return exports;
}

NODE_API_MODULE(bindings, Init);
