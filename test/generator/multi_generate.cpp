#include "Halide.h"

using namespace Halide;

class MultiTest : public Halide::Generator<MultiTest> {
public:
    GeneratorParam<bool> amplify{ "amplify", true };
    GeneratorParam<int> scale{ "scale", 1 };

    ImageParam input{ UInt(16), 2, "input" };

    Func build() override {
        Var x, y;

        Func f;
        if (amplify) {
            f(x, y) = input(x, y) * scale;
        } else {
            f(x, y) = input(x, y) / scale;
        }

        return f;
    }
};

int main(int argc, const char **argv) {
    MultiTest multi;

    std::vector<Internal::GeneratorParamValues> param_sets;
    param_sets.push_back({{ "scale", "2" }, { "amplify", "true" }});
    param_sets.push_back({{ "scale", "3" }, { "amplify", "true" }});
    param_sets.push_back({{ "scale", "2" }, { "amplify", "false" }});
    param_sets.push_back({{ "scale", "3" }, { "amplify", "false" }});
    multi.emit_filter(param_sets, argv[1], "multi", "multi", MultiTest::EmitOptions());

    return 0;
}
