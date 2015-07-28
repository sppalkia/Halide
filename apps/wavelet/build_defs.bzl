# TODO:
# -- How to handle absolute-path specification of Halide library?
# -- how to specify HL_TARGET; do we use config_settings? if so, what are cpu settings?

# workaround for https://github.com/google/bazel/issues/333


def empty_src(name):
    native.genrule(
        name=name,
        outs=["safelight_empty_noop_%s.cc" % name],
        cmd="echo > \"$@\"")


def halide_library(name,
                   srcs,
                   hdrs=[],
                   filter_deps=[],
                   generator_deps=[],
                   visibility=None,
                   function_name=None,
                   generator_name=None,
                   generator_args=None,
                   gpu_target=None,
                   debug=False):

    extra_features = []
    if gpu_target != None:
        if not gpu_target in ["opengl", "opencl", "cuda"]:
            fail(None, 'Illegal value (' + gpu_target + ') for gpu_target')
        extra_features.append(gpu_target)
    if debug:
        extra_features.append("debug")

    halide_target = "host"
    halide_target = halide_target + '-'.join(extra_features)

    generator_executable = "%s_generator" % name
    native.cc_binary(
        name=generator_executable,
        srcs=srcs,
        copts=["-fno-rtti"],
        deps=[
            "@halide-root//:gengen",
            "@halide-root//:lib_halide"
        ] + generator_deps,
        visibility=["//visibility:private"]
    )

    native.genrule(
        name="%s_files" % name,
        outs=[
            "%s.o" % name,
            "%s.h" % name
        ],
        visibility=["//visibility:private"],
        cmd="$(location %s) " % generator_executable
        + ((" -g %s" % generator_name) if generator_name != None else "")
        + ((" -f %s" % function_name) if function_name != None else "")
        + " -o $(@D)"
        + " target=%s" % halide_target
        + (generator_args if generator_args != None else ""),
        tools=[generator_executable]
    )

    native.cc_library(
        name=name,
        srcs=["%s.o" % name],
        # It's important to list filter_deps *after* the generated files;
        # since cc_library deps follow Unix linker rules, filter_deps can
        # get discarded if they come first.
        deps=[
            "@halide-root//:halide_runtime"
        ] + filter_deps,
        hdrs=["%s.h" % name],
        visibility=visibility,
    )
