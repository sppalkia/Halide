# # workaround for https://github.com/google/bazel/issues/333
# load("build_defs", "empty_src")
# empty_src(name="empty")

# cc_library(name="lib_halide_darwin_64",
#            srcs=[
#                "halide_Darwin_64/bin/libHalide.a",
#                ":empty"
#            ],
#            linkopts=[
#                "-lpthread",
#                "-ldl",
#                "-lm",
#                "-lz"
#            ],
#            copts=[
#                "-fno-rtti"
#            ])

# cc_library(name="lib_halide",
#            srcs=[
#                ":empty"
#            ],
#            deps=[
#                ":lib_halide_darwin_64"
#            ],
#            hdrs=[
#                "halide_Darwin_64/include/Halide.h"
#            ],
#            includes=[
#                "halide_Darwin_64/include"
#            ])

# cc_library(name="halide_runtime",
#            srcs=[
#                ":empty"
#            ],
#            hdrs=[
#                "include/HalideRuntime.h"
#            ],
#            includes=[
#                "include"
#            ])
