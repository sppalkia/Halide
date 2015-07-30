package(default_visibility=["//visibility:public"])

cc_library(name="lib_halide",
           srcs=[
               "halide/bin/libHalide.a",
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
           hdrs=[
               "halide/include/HalideRuntime.h"
           ],
           includes=[
               "halide/include"
           ])
