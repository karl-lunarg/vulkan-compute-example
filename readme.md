# Vulkan Compute Example

Simple (but complete) example of Vulkan use for GPGPU computing.
Saxpy kernel computation on 2d arrays.

Features covered:

- Vulkan boilerplate setup using vulkan-hpp
- data copy between host and device-local memory
- passing array parameters to shader (layout bindings)
- passing non-array parameters to shader (push constants)
- define workgroup dimensions (specialization constants)
- very simple glsl shader (saxpy)
- glsl to spir-v compilation (build time)

This was an attempt to structure the Vulkan compute code in a way that would be easy to modify for each particular use case.
I think I failed here so this example still sucks. But I learned while doing this and as a result there is a [vuh](https://github.com/Glavnokoman/vuh) Vulkan compute library which enables you to do the same but in (literally) 10 lines of code. You're cordially invited to use that instead.

## Dependencies

- c++14 compatible compiler
- cmake
- [vulkan-headers](https://github.com/KhronosGroup/Vulkan-Docs)
- [vulkan-hpp](https://github.com/KhronosGroup/Vulkan-Hpp)
- [glslang](https://github.com/KhronosGroup/glslang)
- [catch2](https://github.com/catchorg/Catch2) (optional)
- [sltbench](https://github.com/ivafanas/sltbench) (optional)

## Karl's Changelog

The primary branch for my stuff is `main`.  `master` is the same as the upstream.

### Testing and Performance Dependencies

I tried to build this with the catch2 and sltbench dependencies. But this repo
was very out of date and "behind" at least catch2. After some wrangling, I
almost got it, but was getting a missing SEH symbol (on Windows).  I then
decided it was not worth it, since I don't know if I wanted these packages
anyway.

Add these to `.vscode/settings.json` to remove the dependencies.

```json
    "cmake.configureArgs": [
        "-DVULKAN_COMPUTE_EXAMPLE_BUILD_BENCHMARKS=OFF",
        "-DVULKAN_COMPUTE_EXAMPLE_BUILD_TESTS=OFF"
    ],
```

### CMake Generator

Visual Studio and Ninja should both work.  I had better luck with Ninja when
trying to get the testing and performance helper dependencies working because I
think that this project was UNIX-only for a while and the Release/Debug
directory levels added by the Visual Studio generator caused problems.

### Changes

- Added `.gitignore` file so we can have .vscode and build directories.
- Added `.value` to vulkan.hpp's createComputePipeline call to silence warning.
- Changed several instances of `uint32_t` to `vk::DeviceSize` to silence 64->32 warnings.
- Updated the name of the validation layer.
