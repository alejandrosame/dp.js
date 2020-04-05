workspace(name = "openmined_dp")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

http_archive(
    name = "node_binding",
    #sha256 = "756b1db942c80936172507bd1a8b1fffaf1bc04f",
    strip_prefix = "node-binding-1.3.1",
    urls = [
        "https://github.com/chokobole/node-binding/archive/v1.3.1.tar.gz",
    ],
)

load("@node_binding//bazel:node_binding_deps.bzl", "node_binding_deps")

node_binding_deps()

load("@node_binding//third_party/node_addon_api:install_node_addon_api.bzl", "install_node_addon_api")

install_node_addon_api(name = "node_addon_api")


git_repository(
    name = "differential-privacy",
    commit = "14f26fb91570cce384c2715d3adcaa4e92eec605",
    remote = "https://github.com/google/differential-privacy",
)


git_repository(
    name = "com_google_absl",
    commit = "aae8143cf9aa611f70d7ea9b95b8b8b383b2271a",
    remote = "https://github.com/abseil/abseil-cpp",
)

# needed for protobuf
http_archive(
    name = "zlib",
    build_file = "//third_party:zlib.BUILD",
    sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
    strip_prefix = "zlib-1.2.11",
    urls = [
        "http://mirror.bazel.build/zlib.net/fossils/zlib-1.2.11.tar.gz",
        "http://zlib.net/fossils/zlib-1.2.11.tar.gz",  # 2017-01-15
    ],
)

http_archive(
            name = "bazel_skylib",
            type = "tar.gz",
            url = "https://github.com/bazelbuild/bazel-skylib/releases/download/0.8.0/bazel-skylib.0.8.0.tar.gz",
            sha256 = "2ef429f5d7ce7111263289644d233707dba35e39696377ebab8b0bc701f7818e",
)

http_archive(
            name = "com_google_protobuf",
            urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.8.0.tar.gz"],
            sha256 = "03d2e5ef101aee4c2f6ddcf145d2a04926b9c19e7086944df3842b1b8502b783",
            strip_prefix = "protobuf-3.8.0",
)

http_archive(
    name = "boringssl",
    build_file = "//third_party:boringssl.BUILD",
    urls = [
        "https://boringssl.googlesource.com/boringssl/+archive/master-with-bazel.tar.gz"
    ],
)