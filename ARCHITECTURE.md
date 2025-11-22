# RenderArc Architecture

## Overview

RenderArc is a monolithic C++ repository structured to support multiple applications sharing core libraries. This document describes the architectural decisions, component relationships, and design patterns used throughout the project.

## Monolithic Repository Structure

### Why Monolithic?

A monolithic repository offers several advantages for this project:

1. **Atomic Changes**: Changes across multiple components can be made atomically
2. **Simplified Dependency Management**: All code uses consistent dependency versions
3. **Easier Refactoring**: Cross-component refactoring is straightforward
4. **Single Build System**: One CMake configuration manages all components
5. **Shared Code**: Core libraries are easily reused across applications

### Repository Layout

```
RenderArc/
├── applications/          # Executable applications
│   ├── renderlamp/       # 3D DCC tool (Digital Content Creation)
│   │   ├── CMakeLists.txt
│   │   ├── include/      # Public headers
│   │   └── src/          # Implementation files
│   └── game/             # Game application example
│       ├── CMakeLists.txt
│       └── src/
│
├── core/                 # Core libraries (reusable)
│   ├── Arca/            # Asset management system
│   │   ├── CMakeLists.txt
│   │   ├── README.md
│   │   ├── include/      # Public API
│   │   └── src/          # Implementation
│   └── BuzzRenderer/     # Ray tracing renderer
│       ├── CMakeLists.txt
│       ├── include/
│       └── src/
│
├── tests/               # Test suites
│   ├── CMakeLists.txt
│   ├── core/           # Tests for core libraries
│   └── integration/    # Integration tests
│
├── vendors/            # Third-party dependencies
│   ├── imgui/         # Vendored ImGui
│   └── rlImGui/       # Vendored rlImGui wrapper
│
├── docs/               # Documentation
│   ├── Welcome.md
│   ├── api/           # API documentation
│   └── guides/        # User guides
│
├── .github/            # GitHub configurations
│   └── workflows/      # CI/CD pipelines
│
├── CMakeLists.txt      # Root build configuration
└── CMakePresets.json   # CMake presets for different platforms
```

## Core Components

### 1. Arca - Asset Management System

**Purpose**: Manages application assets, state, and serialization.

**Key Features**:
- Asset loading and saving
- Asset container management
- JSON serialization/deserialization
- Modular architecture

**API Design**:
```cpp
namespace Arca {
    class ArcaAsset;      // Base asset class
    class ArcaContainer;  // Asset collection
    class ArcaInstance;   // Asset instance
    class ArcaModule;     // Plugin system
    class ArcaIO;         // I/O operations
}
```

**Dependencies**:
- nlohmann/json (JSON handling)

### 2. BuzzRenderer - Ray Tracing Library

**Purpose**: Provides ray tracing and rendering capabilities.

**Key Features**:
- Path tracing implementation
- Scene management
- Material system
- Output rendering

**Dependencies**:
- GLM (math library)
- nlohmann/json (configuration)
- Arca (asset integration)

### 3. RenderLamp Application

**Purpose**: Main 3D DCC tool for creating animations and scenes.

**Architecture**:
- **ECS (Entity Component System)**: Scene graph management
- **GUI Layer**: ImGui-based user interface
- **Systems**: Modular functionality (rendering, camera, build)
- **Project Management**: Multi-file project support

**Key Systems**:
- `SceneManagerSystem`: Scene hierarchy and entity management
- `RealTimeRenderingSystem`: Interactive viewport rendering
- `BuildSystem`: Final render output
- `CameraSystem`: Camera controls and navigation

**Dependencies**:
- raylib (window management, input, OpenGL)
- ImGui (user interface)
- Core libraries (Arca, BuzzRenderer)

## Design Patterns

### 1. Entity Component System (ECS)

Used in scene management to separate data from behavior:

```cpp
class Entity {
    // Data container
    std::vector<Component*> components;
};

class System {
    // Behavior processor
    virtual void update(std::vector<Entity*>& entities) = 0;
};
```

### 2. Module Pattern

Core libraries are designed as modules with clear APIs:

```cpp
// Public API in include/
class ArcaModule {
public:
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
};

// Implementation in src/
class ConcreteModule : public ArcaModule {
    // Implementation details hidden
};
```

### 3. Dependency Injection

Systems and components receive dependencies through constructors:

```cpp
class RenderingSystem {
public:
    RenderingSystem(Renderer* renderer, SceneManager* scenes)
        : m_renderer(renderer), m_scenes(scenes) {}
private:
    Renderer* m_renderer;
    SceneManager* m_scenes;
};
```

## Build System

### CMake Structure

The project uses CMake with a hierarchical structure:

1. **Root CMakeLists.txt**: 
   - Fetches external dependencies
   - Defines global settings
   - Includes subdirectories

2. **Component CMakeLists.txt**:
   - Defines libraries/executables
   - Specifies include directories
   - Links dependencies

### Dependency Management

**FetchContent Strategy**:
- External dependencies fetched automatically
- Pinned to specific versions for reproducibility
- No manual download required

**Vendored Dependencies**:
- Some libraries included directly (ImGui, rlImGui)
- Allows custom modifications
- Ensures availability

### Build Configurations

CMakePresets.json provides platform-specific configurations:
- `x64-debug` / `x64-release` (Windows, MSVC)
- `linux-debug` (Linux, GCC)
- `macos-debug` (macOS, Clang)

## Coding Conventions

### Naming Conventions

- **Namespaces**: Match directory structure (`Arca::`, `BuzzRenderer::`)
- **Classes**: PascalCase (`ArcaAsset`, `BuzzRenderer`)
- **Functions**: camelCase (`loadAsset()`, `renderScene()`)
- **Member variables**: prefix `m_` (`m_renderer`, `m_assetList`)

### File Organization

- One class per file (generally)
- Header files use `.hpp` extension
- Implementation files use `.cpp` extension
- Headers in `include/`, sources in `src/`

### Include Structure

```cpp
// 1. Corresponding header (for .cpp files)
#include "MyClass.hpp"

// 2. C++ standard library
#include <string>
#include <vector>

// 3. External dependencies
#include <raylib.h>
#include <nlohmann/json.hpp>

// 4. Internal project headers
#include "Arca/ArcaAsset.hpp"
#include "BuzzRenderer/Renderer.hpp"
```

## Testing Strategy

### Test Organization

```
tests/
├── CMakeLists.txt
├── core/
│   ├── TestArca.cpp         # Arca unit tests
│   └── TestBuzzRenderer.cpp # Renderer unit tests
└── integration/
    └── TestRenderPipeline.cpp # End-to-end tests
```

### Test Framework

- **Google Test**: Unit testing framework
- **Test Naming**: `TEST(ComponentName, DescriptiveTestName)`
- **Coverage**: Aim for >80% code coverage on core libraries

### Running Tests

```bash
# Configure with tests
cmake -S . -B build

# Build everything including tests
cmake --build build

# Run tests
ctest --test-dir build --verbose
```

## Data Flow

### Asset Loading Pipeline

```
File System → ArcaIO::load() → ArcaAsset → ArcaContainer → Application
```

### Rendering Pipeline

```
Scene Data → RenderingSystem → BuzzRenderer → Output Buffer → Display
```

### User Interaction Flow

```
Input Events → Window → GUI Layer → Systems → Scene Modifications → Render
```

## Performance Considerations

### Memory Management

- Use smart pointers for ownership (`std::unique_ptr`, `std::shared_ptr`)
- RAII pattern for resource management
- Avoid unnecessary copies (use const references)

### Rendering Optimization

- Spatial data structures for ray tracing
- Multi-threading support for parallel rendering
- Caching computed results

### Build Optimization

- Static libraries for core components (faster linking)
- Precompiled headers for common includes
- Unity builds for faster compilation

## Future Architecture Considerations

### Planned Improvements

1. **Plugin System**: Dynamic loading of modules
2. **Shader System**: Flexible material definition
3. **Node Editor**: Visual programming interface
4. **Distributed Rendering**: Network-based render farm

### Scalability

The monolithic structure allows for:
- Easy addition of new applications
- New core libraries as needed
- Platform-specific implementations
- Experimental features in separate modules

## References

### External Resources

- [CMake Best Practices](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Entity Component System Pattern](https://en.wikipedia.org/wiki/Entity_component_system)
- [Ray Tracing in One Weekend](https://raytracing.github.io/)

### Internal Documentation

- See `README.md` for build instructions
- See `CONTRIBUTING.md` for development workflow
- See `docs/` for detailed component documentation
