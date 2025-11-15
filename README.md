# [WIP] RenderLamp 
⚠️ WARNING! This project is not yet finished. The descriptions and code are not complete.

## What RenderLamp is
RenderLamp is a 3D DCC tool developed in C++. RenderLamp is an animation and rendering application designed for creating 3D illustrations, scenes, and short films. It is currently under development and in a highly experimental phase, but it will eventually serve as the foundation for the RenderArc framework.

## Core Libaries
 - Arca - A libary responsible for asset management and application state tracking
 - Buzz Renderer - A Ray Tracing Libary
 - Marathon - Simple Building System
 - Stage - ECS System

## Dependencies
- Used CMAKE and MSVC for building the project.
- [raylib](https://github.com/raysan5/raylib)
- [imGui](https://github.com/ocornut/imgui)
- [rlImGui](https://github.com/raylib-extras/rlImGui)
- [nlohmannjson](https://github.com/nlohmann/json)
- [GoogleTest](https://github.com/google/googletest)
- [GLM](https://github.com/g-truc/glm)


## Renderer - Buzz Renderer
This version of RenderLamp you can use the Buzz Renderer. Coming Soon...

## Build the Project
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
    ./build/editor/Debug/RenderLamp
    ```

# Resources/Credits
In the following section, I would like to clarify the guidelines I followed during the project and give proper credit to everyone who contributed to its creation. First and foremost, I would like to express my gratitude to my university advisor, Dr. Péter Mileff, for his guidance and valuable advice throughout this journey. Additionally, I would like to thank Levente Fazekas for contributing to my C++ knowledge through his university course. <br>
The most important point to clarify is that whenever I use a code snippet, I will explicitly reference it in my source code and provide a link to the original author. Unfortunately, due to time constraints, I am unable to verify the originality of every single source, but I will make every effort to do so to the best of my ability.

## Literature
I utilized several academic and technical sources to understand the fundamentals of Computer Graphics. A significant portion of these materials was implemented or summarized in separate repositories. Naturally, these sources served as the foundation for designing and developing my own software. The following list contains the references I relied on and drew inspiration from.

- Base of the ray tracer: [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley, Trevor David Black and Steve Hollasch
- Software rendering: [tinyseries](https://github.com/ssloy/tinyrenderer) by Dmitry V. Sokolov
- Raytracing & Triangle Intersection: [Scratchpixel](https://www.scratchapixel.com/index.html) by scratchpixel team
- General Graphics Knowledge: [Fundamentals of Computer Graphics](https://www.amazon.com/Fundamentals-Computer-Graphics-Steve-Marschner/dp/1482229390) by Steve Marschner and Peter Shirley 
- Editor's ECS Architecture: [Coding a 2D Game Engine in Java](https://www.youtube.com/playlist?list=PLtrSb4XxIVbp8AKuEAlwNXDxr99e3woGE) by GamesWithGabe
- Projection: [How Do Computers Display 3D on a 2D Screen? (Perspective Projection)](https://www.youtube.com/watch?v=eoXn6nwV694) by Carl the Person
- C++/Graphics Concepts : [Code-It-Yourself! Series](https://www.youtube.com/watch?v=8OK8_tHeCIA&list=PLrOv9FMX8xJE8NgepZR1etrsU63fDDGxO) by javidx9
- CMAKE: [CMake Examples](https://github.com/ttroy50/cmake-examples) by Thom Troy
- Projection Matrix: [OpenGL Projection Matrix](https://www.songho.ca/opengl/gl_projectionmatrix.html) by Song Ho Ahn
- Triangle Intersection [Ray-triangle intersection - Washington](https://courses.cs.washington.edu/courses/csep557/10au/lectures/triangle_intersection.pdf) by Brian Curless


## Generative AI tools
In this project, I utilized various generative AI tools, such as ChatGPT and GitHub Copilot. ChatGPT was used exclusively to improve the spelling and grammatical structure of my sentences, as well as to translate some of my more complex sentences from Hungarian to English. <br>
I also utilized GitHub Copilot during the project. However, I aimed to minimize its use, primarily leveraging it to get started with a basic structure or to explain issues in my code. Additionally, I used it to correct minor C++-specific syntax errors. The majority of the code it generated was completely rewritten.
