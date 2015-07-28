load("build_defs", "halide_library")

[halide_library(
  name = g[:-14], 
  srcs = [g]
) for g in glob(["*_generator.cpp"])]

cc_library(name = "wavelet_filters",
           deps=[g[:-14] for g in glob(["*_generator.cpp"])])

# bazel run :wavelet -- `bazel-bin/wavelet ../../images/gray.png` .
cc_binary(name="wavelet",
          srcs=["wavelet.cpp"],
          deps=[":wavelet_filters", 
                "@halide-root//:halide_runtime",
                "@halide-root//:image-io",
                ])

