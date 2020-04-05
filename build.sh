#!/bin/bash 

rm -r ./bazel-*
rm -r -f ./dist
rm ./test/openmined-dp.node
bazel build //src_napi/...
mkdir dist
cp ./bazel-bin/src_napi/openmined-dp.node ./dist
cp ./bazel-bin/src_napi/openmined-dp.node ./test