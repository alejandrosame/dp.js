load("@node_binding//bazel:node_binding.bzl", "node_binding")
load("@node_binding//bazel:node_binding_cc.bzl", "node_binding_copts")



# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
  name = "status_js",
  srcs = ["status_js.cc"],
  hdrs = ["status_js.h"],
  deps = ["@google_dp//differential_privacy/base:status"],
)


node_binding(
    name = "name",
    srcs = [
      "binding.cc"
    ],
    copts = node_binding_copts(),
    deps = [
        ":status_js",
    ],
)