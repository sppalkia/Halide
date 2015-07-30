# load("build_defs", "empty_src")

# # workaround for https://github.com/google/bazel/issues/333
# empty_src(name="empty")

# cc_library(name="lib_halide",
#            srcs=[
#                "distrib/bin/libHalide.a",
#                ":empty"
#            ],
#            hdrs=[
#                "distrib/include/Halide.h"
#            ],
#            linkopts=[
#                "-lpthread",
#                "-ldl",
#                "-lm",
#                "-lz"
#            ],
#            copts=[
#                "-fno-rtti"
#            ],
#            includes=[
#                "distrib/include"
#            ])

# cc_library(name="halide_runtime",
#            srcs=[
#                ":empty"
#            ],
#            hdrs=[
#                "distrib/include/HalideRuntime.h"
#            ],
#            includes=[
#                "distrib/include"
#            ])

# cc_library(name="image-io",
#            deps=[
#                ":halide_runtime"
#            ],
#            linkopts=[
#                "-lpng"
#            ],
#            srcs=[
#                ":empty"
#            ],
#            hdrs=[
#                "apps/support/image_io.h"
#            ],
#            includes=[
#                "apps/support"
#            ])

# cc_library(name="static-image",
#            srcs=[
#                ":empty"
#            ],
#            deps=[
#                ":halide_runtime"
#            ],
#            hdrs=[
#                "apps/support/static_image.h"
#            ],
#            includes=[
#                "apps/support"
#            ])
