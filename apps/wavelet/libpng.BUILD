package(
    default_visibility = ["//visibility:public"],
)

genrule(name = "gen_pnglibconf",
        srcs=["scripts/pnglibconf.h.prebuilt"],
        outs=["pnglibconf.h"],
        cmd="cp \"$<\" \"$@\"",
        visibility=["//visibility:private"])

cc_library(name = "pnglibconf",
        hdrs=[":gen_pnglibconf"],
        includes=["."],
        visibility=["//visibility:private"])

cc_library(
    name = "libpng",
    srcs = [
        "png.c",
        "pngerror.c",
        "pngget.c",
        "pngmem.c",
        "pngpread.c",
        "pngread.c",
        "pngrio.c",
        "pngrtran.c",
        "pngrutil.c",
        "pngset.c",
        "pngtrans.c",
        "pngwio.c",
        "pngwrite.c",
        "pngwtran.c",
        "pngwutil.c",
    ],
    hdrs = ["png.h"],
    linkopts = ["-lm"],
    deps = [
        ":pnglibconf",
        "@zlib-github//:zlib",
    ],
)

