#include "example_filter.h"
#include "vulkan_helpers.hpp"

auto main(int argc, char *argv[]) -> int
{
    const auto numElements = 1000;
    const auto a = 2.0f; // saxpy scaling factor

    auto y = std::vector<uint32_t>(numElements, 0);
    auto x = std::vector<uint32_t>(numElements, 0);
    for (int i = 0; i < numElements; ++i) x[i] = i;
    auto w = std::vector<uint32_t>(numElements * 4, 0);

    ExampleFilter f("shaders/saxpy.spv");
    auto d_y = vuh::Array<uint32_t>::fromHost(y, f.device, f.physDevice);
    auto d_x = vuh::Array<uint32_t>::fromHost(x, f.device, f.physDevice);
    auto d_w = vuh::Array<uint32_t>::fromHost(w, f.device, f.physDevice);  // work buffer

    f(d_y, d_x, d_w, {numElements, a});

    auto out_tst = std::vector<uint32_t>{};
    d_y.to_host(out_tst); // and now out_tst should contain the result

    // Set breakpoint here and examime out_tst.
    return 0;
}
