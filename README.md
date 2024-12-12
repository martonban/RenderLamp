# [WIP] RenderLamp 
![Cover](RenderLampCover.png)

## What RenderLamp is
RenderLamp is a 3D CPU ray tracer with a simple editor. You can create scenes give properties to objects and render those scenes with a raytracer.

## Motivation
This project is mainly a C++ project to me and not a graphics one. So please don't expect complicated rendering algorithms. In the future I want to continue this project like using CUDA/OpenCL or implementing a renderer for the editor too. 

## Technologies/Dependencies
- Used CMAKE and MSVC for the building projects
- The editor's viewport based on [raylib](https://github.com/raysan5/raylib)
- The whole project will use [nlohmannjson](https://github.com/nlohmann/json) libary for handling json files and [GoogleTest](https://github.com/google/googletest) for unit testing.

## Renderer - Buzz Renderer
This version of RenderLamp you can use the Buzz Renderer. This renderer is based on the [Ray Tracing in One Weekend book](https://raytracing.github.io/books/RayTracingInOneWeekend.html).
