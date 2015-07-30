package(default_visibility=["//visibility:public"])


# workaround for https://github.com/google/bazel/issues/333
load("build_defs", "empty_src")
empty_src(name="empty")

cc_library(name="lib_halide",
           srcs=[
               "halide/bin/libHalide.a",
               ":empty"
           ],
           linkopts=[
               "-lpthread",
               "-ldl",
               "-lm",
               "-lz"
           ],
           copts=[
               "-fno-rtti"
           ],
           hdrs=[
               "halide/include/Halide.h"
           ],
           includes=[
               "halide/include"
           ])

cc_library(name="halide_runtime",
           srcs=[
               ":empty"
           ],
           hdrs=[
               "halide/include/HalideRuntime.h"
           ],
           includes=[
               "halide/include"
           ])
