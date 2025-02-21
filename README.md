# [WIP] RenderLamp 
⚠️ WARNING! This project is not yet finished. The descriptions and code found here are not complete.

## What RenderLamp is
RenderLamp is a 3D CPU software renderer utilizing ray tracing and shiped with a simple editor. You can create scenes, give properties to objects and render those scenes with a raytracer.

## Motivation
This project is mainly a C++ project to me and not a graphics one. So please don't expect complicated rendering algorithms. In the future I want to continue this project like using CUDA/OpenCL or implementing a renderer for the editor too. 

## Dependencies
- Used CMAKE and MSVC for building the project.
- My own Asset Manager Libary [Arca](https://github.com/martonban/Arca)
- [raylib](https://github.com/raysan5/raylib)
- [imGui](https://github.com/ocornut/imgui)
- [rlImGui](https://github.com/raylib-extras/rlImGui)
- [nlohmannjson](https://github.com/nlohmann/json)
- [GoogleTest](https://github.com/google/googletest)

## Renderer - Buzz Renderer
This version of RenderLamp you can use the Buzz Renderer. This renderer is based on the [Ray Tracing in One Weekend book](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

## Geting Started (WIP)
1. **Clone the Repository**:
    ```sh
    git clone https://github.com/martonban/RenderLamp.git
    cd RenderLamp
    ```

2. **Install Dependencies**:
    Ensure you have CMake and a compatible C++ compiler (MSVC) installed on your system.

3. **Build the Project**:
    ```sh
    cmake -S . -B build
    cmake --build build
    ```

4. **Run the Application**:
    After building, you can run the application from the build directory:
    ```sh
    ./RenderLamp/build/editor/Debug
    ```


Make sure to check the documentation and comments within the code for more detailed instructions and troubleshooting tips.
