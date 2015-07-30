load("build_defs", "halide_library")

# workaround for https://github.com/google/bazel/issues/333
load("build_defs", "empty_src")
empty_src(name="empty")

[halide_library(
    name=g[:-14],
    srcs=[g]
) for g in glob(["*_generator.cpp"])]

cc_library(name="wavelet_filters",
           srcs=[":empty"],
           deps=[g[:-14] for g in glob(["*_generator.cpp"])])

# bazel run :wavelet -- $PWD/../images/gray.png /tmp
cc_binary(name="wavelet",
          srcs=[
              "wavelet.cpp",
              "image_io.h",
              "static_image.h"
          ],
          deps=[
              ":wavelet_filters",
              "//external:libpng",
          ])
