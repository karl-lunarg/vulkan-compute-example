#include "example_filter.h"
#include "vulkan_helpers.hpp"

auto main(int argc, char *argv[]) -> int
{
    const auto numElements = 6140;
    const auto a = 2.0f; // saxpy scaling factor

    auto y = std::vector<float>(numElements, 0.71f);
    auto x = std::vector<float>(numElements, 0.65f);

    ExampleFilter f("shaders/saxpy.spv");
    auto d_y = vuh::Array<float>::fromHost(y, f.device, f.physDevice);
    auto d_x = vuh::Array<float>::fromHost(x, f.device, f.physDevice);

    f(d_y, d_x, {numElements, a});

    auto out_tst = std::vector<float>{};
    d_y.to_host(out_tst); // and now out_tst should contain the result of saxpy (y = y + ax)

    return 0;
}
