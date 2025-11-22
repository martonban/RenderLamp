# RenderArc Code Style Guide

This document defines the coding standards and style guidelines for the RenderArc project.

## General Principles

1. **Consistency**: Follow the established patterns in the codebase
2. **Clarity**: Write code that is easy to read and understand
3. **Simplicity**: Prefer simple solutions over complex ones
4. **Maintainability**: Write code that is easy to modify and extend

## C++ Standard

- **Required**: C++20 or later
- Use modern C++ features when appropriate
- Avoid deprecated features

## File Organization

### File Structure

```cpp
// 1. Header guard (for .hpp files)
#pragma once

// 2. Includes
#include <system_headers>
#include <library_headers>
#include "local_headers.hpp"

// 3. Namespace declaration
namespace RenderArc {

// 4. Forward declarations (if needed)
class ForwardDeclaredClass;

// 5. Class/function declarations
class MyClass {
    // ...
};

} // namespace RenderArc
```

### File Naming

- **Header files**: `.hpp` extension
- **Source files**: `.cpp` extension
- **File names**: Match the primary class name (e.g., `ArcaAsset.hpp`, `ArcaAsset.cpp`)
- Use `PascalCase` for file names

### Directory Structure

```
component/
├── include/           # Public API headers
│   └── Component.hpp
└── src/              # Implementation files
    └── Component.cpp
```

## Naming Conventions

### Classes and Structs

- Use `PascalCase`
- Be descriptive and specific

```cpp
class ArcaAsset { };
class BuzzRenderer { };
struct Transform3D { };
```

### Functions and Methods

- Use `camelCase`
- Start with a verb when possible
- Be descriptive

```cpp
void loadAsset(const std::string& path);
int calculateDistance(const Point& a, const Point& b);
bool isValid() const;
```

### Variables

- Use `camelCase`
- Be descriptive, avoid abbreviations
- Use meaningful names even for loop variables when appropriate

```cpp
int frameCount = 0;
std::string assetPath = "assets/model.obj";
Vector3 cameraPosition;

// Loop variables can be short when context is clear
for (size_t i = 0; i < items.size(); ++i) {
    // ...
}
```

### Member Variables

- Prefix with `m_`
- Use `camelCase` after prefix

```cpp
class MyClass {
private:
    int m_count;
    std::string m_name;
    Vector3 m_position;
};
```

### Constants

- Use `UPPER_SNAKE_CASE`
- Prefer `constexpr` over `#define`

```cpp
constexpr int MAX_BUFFER_SIZE = 1024;
constexpr double PI = 3.14159265359;
const std::string DEFAULT_ASSET_PATH = "assets/";
```

### Namespaces

- Use `PascalCase`
- Keep names short and meaningful
- Avoid nested namespaces when possible

```cpp
namespace RenderArc {
namespace Renderer {
    // ...
}
}

// Or with C++17
namespace RenderArc::Renderer {
    // ...
}
```

### Enums

- Use `enum class` (strongly typed)
- Enum name in `PascalCase`
- Enum values in `PascalCase`

```cpp
enum class RenderMode {
    Wireframe,
    Solid,
    Textured,
    PBR
};
```

## Code Formatting

### Indentation

- **4 spaces** for indentation (no tabs)
- Indent inside namespaces

```cpp
namespace RenderArc {

class MyClass {
public:
    void myMethod() {
        if (condition) {
            doSomething();
        }
    }
};

} // namespace RenderArc
```

### Braces

- Opening brace on the same line (K&R style)
- Always use braces for control structures, even for single statements

```cpp
// Good
if (condition) {
    doSomething();
}

for (int i = 0; i < 10; ++i) {
    process(i);
}

// Bad
if (condition)
    doSomething();
```

### Line Length

- **Maximum 100 characters** per line
- Break long lines at logical points

```cpp
// Break after comma
void longFunction(const std::string& param1, const std::string& param2,
                  const std::string& param3, const std::string& param4);

// Break after operators
bool result = (longCondition1 && longCondition2) ||
              (longCondition3 && longCondition4);
```

### Spacing

- Space after keywords: `if (`, `for (`, `while (`
- No space after function names: `function(`
- Spaces around binary operators: `a + b`, `x = y`
- No space before semicolons

```cpp
// Good
if (x > 0) {
    y = x + 5;
    function(y);
}

// Bad
if(x>0){
    y=x+5;
    function (y) ;
}
```

## Language Features

### Pointers and References

- Use references for parameters that won't be null
- Use pointers only when nullptr is a valid value
- Prefer smart pointers over raw pointers

```cpp
// Good
void process(const Asset& asset);           // Can't be null
void process(Asset* asset);                 // May be null
std::unique_ptr<Asset> createAsset();       // Ownership transfer
std::shared_ptr<Asset> getSharedAsset();    // Shared ownership

// Bad
void process(Asset* asset);  // When asset can't be null
```

### Const Correctness

- Use `const` wherever possible
- Mark methods `const` when they don't modify state
- Use `const` for parameters that won't be modified

```cpp
class MyClass {
public:
    int getValue() const { return m_value; }  // const method
    void setValue(int value) { m_value = value; }
    
    void process(const std::string& input);   // const parameter
    
private:
    int m_value;
};
```

### Auto Keyword

- Use `auto` when the type is obvious or complex
- Avoid `auto` when it makes code less readable

```cpp
// Good
auto it = container.begin();
auto ptr = std::make_unique<MyClass>();
std::vector<std::string> names = getNames();  // Type explicit

// Avoid
auto x = 5;  // int is clearer
auto result = calculate();  // What type is returned?
```

### Range-Based For Loops

- Prefer range-based for loops when possible
- Use const references for read-only access

```cpp
// Good
for (const auto& item : items) {
    process(item);
}

// Modify elements
for (auto& item : items) {
    item.update();
}

// Old style (when index is needed)
for (size_t i = 0; i < items.size(); ++i) {
    process(items[i], i);
}
```

### Smart Pointers

- Use smart pointers for ownership management
- `std::unique_ptr` for exclusive ownership
- `std::shared_ptr` for shared ownership
- Avoid raw pointers for ownership

```cpp
// Exclusive ownership
std::unique_ptr<Asset> asset = std::make_unique<Asset>();

// Shared ownership
std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();

// Non-owning reference (use raw pointer or reference)
void render(Asset* asset);  // Non-owning
void render(Asset& asset);  // Non-owning, can't be null
```

## Class Design

### Class Structure Order

```cpp
class MyClass {
public:
    // 1. Constructors and destructors
    MyClass();
    ~MyClass();
    
    // 2. Public methods
    void publicMethod();
    int getValue() const;
    
protected:
    // 3. Protected methods
    void protectedMethod();
    
private:
    // 4. Private methods
    void privateHelper();
    
    // 5. Private member variables (at the end)
    int m_value;
    std::string m_name;
};
```

### Constructor Guidelines

- Use member initializer lists
- Initialize members in declaration order

```cpp
class MyClass {
public:
    MyClass(int value, std::string name)
        : m_value(value)
        , m_name(std::move(name))
        , m_initialized(true) {
        // Constructor body
    }
    
private:
    int m_value;
    std::string m_name;
    bool m_initialized;
};
```

### Rule of Five/Zero

- Follow the Rule of Five or Rule of Zero
- If you define one special member, consider defining all

```cpp
// Rule of Zero (prefer this)
class MyClass {
private:
    std::unique_ptr<Resource> m_resource;  // Handles itself
};

// Rule of Five (when needed)
class MyClass {
public:
    MyClass(const MyClass& other);              // Copy constructor
    MyClass(MyClass&& other) noexcept;          // Move constructor
    MyClass& operator=(const MyClass& other);   // Copy assignment
    MyClass& operator=(MyClass&& other) noexcept;  // Move assignment
    ~MyClass();                                 // Destructor
};
```

## Comments

### When to Comment

- Explain "why", not "what" (code should explain "what")
- Document complex algorithms
- Document public APIs
- Add TODO/FIXME/NOTE comments as needed

```cpp
// Good: Explains why
// Use binary search because the array is already sorted
int index = binarySearch(array, target);

// Bad: States the obvious
// Increment i by 1
++i;

// TODO: Add error handling for network failures
// FIXME: This breaks when input is negative
// NOTE: This algorithm is O(n²) but data sets are small
```

### Doxygen Comments

Use Doxygen-style comments for public APIs:

```cpp
/**
 * @brief Loads an asset from the specified path
 * 
 * Reads the asset file and creates an in-memory representation.
 * Supports various formats including OBJ, FBX, and custom formats.
 * 
 * @param path The filesystem path to the asset file
 * @param options Loading options (format, quality, etc.)
 * @return std::unique_ptr<Asset> The loaded asset, or nullptr on failure
 * @throws AssetLoadException if the file cannot be read
 */
std::unique_ptr<Asset> loadAsset(const std::filesystem::path& path,
                                  const LoadOptions& options);
```

## Error Handling

### Exceptions

- Use exceptions for exceptional conditions
- Use specific exception types
- Provide meaningful error messages

```cpp
if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + path.string());
}

// Custom exceptions
class AssetNotFoundException : public std::runtime_error {
public:
    explicit AssetNotFoundException(const std::string& assetName)
        : std::runtime_error("Asset not found: " + assetName) {
    }
};
```

### Return Values

- Use `std::optional` for functions that may not return a value
- Use return codes only for performance-critical paths

```cpp
std::optional<Asset> findAsset(const std::string& name) {
    auto it = assets.find(name);
    if (it != assets.end()) {
        return it->second;
    }
    return std::nullopt;
}

// Usage
if (auto asset = findAsset("model")) {
    process(*asset);
}
```

## Testing

### Test Naming

```cpp
TEST(ComponentName, DescriptiveTestName) {
    // Arrange
    MyClass obj(42);
    
    // Act
    int result = obj.getValue();
    
    // Assert
    EXPECT_EQ(result, 42);
}
```

### Test Organization

- One test file per class/component
- Group related tests using test fixtures
- Use descriptive test names that explain what is being tested

## Includes

### Include Order

1. Corresponding header (for .cpp files)
2. C++ standard library
3. External dependencies
4. Project headers

```cpp
// In MyClass.cpp
#include "MyClass.hpp"  // 1. Corresponding header

#include <algorithm>    // 2. C++ standard library
#include <string>
#include <vector>

#include <raylib.h>     // 3. External dependencies
#include <glm/glm.hpp>

#include "Arca/ArcaAsset.hpp"     // 4. Project headers
#include "BuzzRenderer/Renderer.hpp"
```

### Include Guards

Use `#pragma once` for all headers:

```cpp
#pragma once

// Header content
```

## Automation

### clang-format

The project uses `.clang-format` for automated formatting:

```bash
# Format a single file
clang-format -i MyClass.cpp

# Format all C++ files
find . -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
```

### clang-tidy

Use clang-tidy for static analysis:

```bash
clang-tidy MyClass.cpp -- -I./include -std=c++20
```

## Additional Resources

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Modern C++ Best Practices](https://www.modernescpp.com/)

---

**Remember**: These are guidelines, not absolute rules. Use your judgment and prioritize code readability and maintainability.
