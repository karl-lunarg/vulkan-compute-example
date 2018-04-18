# Vulkan Compute Example

Simple (but complete) example of Vulkan use for GPGPU computing.
Saxpy kernel computation on 2d arrays.

Features covered:
- Vulkan boilerplate setup using vulkan-hpp
- array copy to/from device
- array binding to the shader
- push constants (to define array dimensions and scaling constant)
- specialization constants (to define the workgroup dimensions)
