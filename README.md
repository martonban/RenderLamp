# RenderArc - Monolithic C++ Framework

[![CI/CD Pipeline](https://github.com/martonban/RenderArc/actions/workflows/ci.yml/badge.svg)](https://github.com/martonban/RenderArc/actions/workflows/ci.yml)

⚠️ **Note**: This project is under active development. APIs and structure may change.

## Overview

RenderArc is a modern monolithic C++ repository for building 3D applications, DCC tools, and rendering engines. It demonstrates best practices for organizing large-scale C++ projects with multiple applications sharing core libraries.

### What is RenderLamp?

RenderLamp is the flagship application built with RenderArc. It's a 3D Digital Content Creation (DCC) tool designed for creating 3D illustrations, scenes, and short films. Currently in development, it showcases the capabilities of the RenderArc framework.

## Repository Structure

This monolithic repository follows modern C++ best practices:

```
RenderArc/
├── applications/       # Executable applications
│   ├── renderlamp/    # Main 3D DCC tool
│   └── game/          # Game application example
├── core/              # Reusable core libraries
│   ├── Arca/          # Asset management system
│   └── BuzzRenderer/  # Ray tracing renderer
├── tests/             # Unit and integration tests
│   ├── core/          # Tests for core libraries
│   └── integration/   # Integration tests
├── vendors/           # Third-party dependencies
├── docs/              # Documentation
└── .github/           # CI/CD workflows
```

For detailed architecture information, see [ARCHITECTURE.md](ARCHITECTURE.md).

## Core Libraries

### Arca
A library responsible for asset management and application state tracking. Features:
- Asset loading and serialization
- JSON-based persistence
- Container-based data management

### BuzzRenderer
A ray tracing rendering library. Features:
- Path tracing implementation
- Scene management
- Material system
- Based on "Ray Tracing in One Weekend"

### Stage
Entity Component System (ECS) for scene graph management (integrated in RenderLamp).

## Dependencies

All dependencies are managed automatically via CMake FetchContent:

- **[raylib](https://github.com/raysan5/raylib)** - Window management and graphics
- **[ImGui](https://github.com/ocornut/imgui)** - User interface
- **[rlImGui](https://github.com/raylib-extras/rlImGui)** - ImGui + raylib integration
- **[nlohmann/json](https://github.com/nlohmann/json)** - JSON handling
- **[GoogleTest](https://github.com/google/googletest)** - Testing framework
- **[GLM](https://github.com/g-truc/glm)** - Mathematics library

## Getting Started

### Prerequisites

- **CMake** 3.10 or higher
- **C++20** compatible compiler:
  - Windows: MSVC 2019+
  - Linux: GCC 9+ or Clang 10+
  - macOS: Xcode 12+ (Clang)

### Linux Dependencies

```bash
sudo apt-get update
sudo apt-get install -y \
  cmake \
  ninja-build \
  libx11-dev \
  libxrandr-dev \
  libxinerama-dev \
  libxcursor-dev \
  libxi-dev \
  libgl1-mesa-dev
```

### Building

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/martonban/RenderArc.git
   cd RenderArc
   ```

2. **Configure CMake**:
   ```bash
   cmake -S . -B build
   ```

3. **Build All Targets**:
   ```bash
   cmake --build build
   ```

4. **Run Tests**:
   ```bash
   ctest --test-dir build --verbose
   ```

### Running Applications

After building:

```bash
# Run RenderLamp (3D DCC Tool)
./build/applications/renderlamp/RenderLamp

# Run Game Example
./build/applications/game/ELDON
```

### CMake Presets

Use platform-specific presets for easier configuration:

```bash
# Windows (MSVC)
cmake --preset x64-debug
cmake --build --preset x64-debug

# Linux
cmake --preset linux-debug
cmake --build --preset linux-debug

# macOS
cmake --preset macos-debug
cmake --build --preset macos-debug
```

## Development

### Project Organization

This project follows **monolithic repository** principles:
- All code in a single repository
- Shared dependencies and build configuration
- Atomic changes across multiple components
- Unified version control and CI/CD

### Code Style

We use `.clang-format` for consistent code formatting:

```bash
# Format all C++ files
find applications core tests -name "*.cpp" -o -name "*.hpp" | \
  xargs clang-format -i
```

### Testing

Write tests for all new functionality:

```bash
# Run all tests
ctest --test-dir build --verbose

# Run specific test suite
./build/tests/core/TestArca
./build/tests/core/TestBuzzRenderer
```

### Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for:
- Development workflow
- Coding standards
- Testing requirements
- Pull request process

## Documentation

- **[ARCHITECTURE.md](ARCHITECTURE.md)** - Detailed architecture and design decisions
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - How to contribute to the project
- **[docs/](docs/)** - Additional documentation and guides

## Continuous Integration

This project uses GitHub Actions for CI/CD:
- ✅ Multi-platform builds (Linux, Windows, macOS)
- ✅ Automated testing with GoogleTest
- ✅ Code formatting checks
- ✅ Test result artifacts

See [.github/workflows/ci.yml](.github/workflows/ci.yml) for details.

## Roadmap

- [ ] Plugin system for extensibility
- [ ] Enhanced material editor
- [ ] Network-based distributed rendering
- [ ] Visual shader/node editor
- [ ] Animation timeline
- [ ] Physics integration

## Resources & Credits

### Acknowledgments

I would like to express my gratitude to:
- **Dr. Péter Mileff** - University advisor for guidance and advice
- **Levente Fazekas** - C++ knowledge contributions through university courses

### Literature & References

This project builds upon knowledge from:

- **Ray Tracing**: [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley, Trevor David Black, and Steve Hollasch
- **Software Rendering**: [tinyrenderer](https://github.com/ssloy/tinyrenderer) by Dmitry V. Sokolov
- **Graphics Theory**: [Scratchpixel](https://www.scratchapixel.com/) by the Scratchpixel team
- **Textbook**: [Fundamentals of Computer Graphics](https://www.amazon.com/Fundamentals-Computer-Graphics-Steve-Marschner/dp/1482229390) by Steve Marschner and Peter Shirley
- **ECS Architecture**: [Coding a 2D Game Engine in Java](https://www.youtube.com/playlist?list=PLtrSb4XxIVbp8AKuEAlwNXDxr99e3woGE) by GamesWithGabe
- **Projection**: [Perspective Projection](https://www.youtube.com/watch?v=eoXn6nwV694) by Carl the Person
- **C++/Graphics**: [Code-It-Yourself! Series](https://www.youtube.com/watch?v=8OK8_tHeCIA&list=PLrOv9FMX8xJE8NgepZR1etrsU63fDDGxO) by javidx9
- **CMake**: [CMake Examples](https://github.com/ttroy50/cmake-examples) by Thom Troy
- **Projection Matrix**: [OpenGL Projection Matrix](https://www.songho.ca/opengl/gl_projectionmatrix.html) by Song Ho Ahn
- **Ray-Triangle Intersection**: [UW Course Material](https://courses.cs.washington.edu/courses/csep557/10au/lectures/triangle_intersection.pdf) by Brian Curless

All code snippets from external sources are explicitly referenced in the source code with links to original authors.

### Generative AI Tools

This project utilized:
- **ChatGPT** - For improving grammar, spelling, and translating Hungarian to English
- **GitHub Copilot** - For basic code structure and syntax assistance

The majority of AI-generated code was significantly rewritten and adapted for this project's needs.

## License

[Add your license information here]

## Contact

- **Repository**: [github.com/martonban/RenderArc](https://github.com/martonban/RenderArc)
- **Issues**: [GitHub Issues](https://github.com/martonban/RenderArc/issues)
- **Pull Requests**: [GitHub PRs](https://github.com/martonban/RenderArc/pulls)

