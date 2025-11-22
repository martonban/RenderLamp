# Contributing to RenderArc

Thank you for considering contributing to RenderArc! This document provides guidelines and best practices for contributing to this project.

## Table of Contents
- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Testing](#testing)
- [Pull Request Process](#pull-request-process)

## Code of Conduct

This project follows a Code of Conduct to ensure a welcoming environment for all contributors. Please be respectful and professional in all interactions.

## Getting Started

### Prerequisites
- CMake 3.10 or higher
- C++20 compatible compiler (MSVC on Windows, GCC/Clang on Linux)
- Git

### Building the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/martonban/RenderArc.git
   cd RenderArc
   ```

2. **Install System Dependencies** (Linux):
   ```bash
   sudo apt-get install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev
   ```

3. **Configure and Build**:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

4. **Run Tests**:
   ```bash
   ctest --test-dir build --verbose
   ```

## Development Workflow

### Repository Structure

This is a monolithic repository organized as follows:

```
RenderArc/
├── applications/       # Executable applications
│   ├── renderlamp/    # Main DCC tool application
│   └── game/          # Game application example
├── core/              # Core libraries
│   ├── Arca/          # Asset management library
│   └── BuzzRenderer/  # Ray tracing renderer library
├── tests/             # Unit and integration tests
├── vendors/           # Third-party dependencies (vendored)
├── docs/              # Documentation
├── .github/           # GitHub workflows and configurations
└── CMakeLists.txt     # Root CMake configuration
```

### Branching Strategy

- `main` - Stable production branch
- `develop` - Integration branch for features
- `feature/*` - Feature branches
- `bugfix/*` - Bug fix branches
- `hotfix/*` - Critical fixes for production

### Commit Messages

Follow the [Conventional Commits](https://www.conventionalcommits.org/) specification:

```
<type>(<scope>): <subject>

<body>

<footer>
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, etc.)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

Example:
```
feat(renderer): add support for PBR materials

Implemented physically-based rendering materials with support for
metallic-roughness workflow.

Closes #123
```

## Coding Standards

### C++ Style Guide

- **C++ Standard**: Use C++20 features where appropriate
- **Naming Conventions**:
  - Classes/Structs: `PascalCase`
  - Functions/Methods: `camelCase`
  - Variables: `camelCase`
  - Constants: `UPPER_SNAKE_CASE`
  - Private members: prefix with `m_` (e.g., `m_memberVariable`)
  
- **File Organization**:
  - Header files: `.hpp` extension
  - Source files: `.cpp` extension
  - One class per file (generally)
  - Headers in `include/`, sources in `src/`

- **Code Formatting**:
  - Use the provided `.clang-format` configuration
  - Run `clang-format` before committing
  - Use 4 spaces for indentation (no tabs)

### Example Code Style

```cpp
#pragma once

#include <string>
#include <vector>

namespace RenderArc {

class ExampleClass {
public:
    ExampleClass();
    ~ExampleClass();
    
    void doSomething(const std::string& input);
    int getValue() const;
    
private:
    void helperMethod();
    
    int m_value;
    std::vector<std::string> m_items;
};

} // namespace RenderArc
```

## Testing

### Writing Tests

- Use Google Test framework for unit tests
- Place tests in `tests/` directory mirroring the source structure
- Test file naming: `Test<ClassName>.cpp`
- Use meaningful test names that describe what is being tested

Example test:
```cpp
#include <gtest/gtest.h>
#include "Arca/ArcaAsset.hpp"

TEST(ArcaAssetTest, CreatesAssetWithValidData) {
    // Arrange
    std::string assetName = "test_asset";
    
    // Act
    ArcaAsset asset(assetName);
    
    // Assert
    EXPECT_EQ(asset.getName(), assetName);
}

TEST(ArcaAssetTest, ThrowsOnInvalidInput) {
    // Arrange & Act & Assert
    EXPECT_THROW(ArcaAsset(""), std::invalid_argument);
}
```

### Running Tests

```bash
# Build tests
cmake --build build

# Run all tests
ctest --test-dir build --verbose

# Run specific test
build/tests/TestArca
```

## Pull Request Process

1. **Create a Feature Branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make Your Changes**:
   - Write clean, well-documented code
   - Add tests for new functionality
   - Update documentation as needed

3. **Test Your Changes**:
   ```bash
   cmake --build build
   ctest --test-dir build
   ```

4. **Format Your Code**:
   ```bash
   clang-format -i $(find . -name "*.cpp" -o -name "*.hpp")
   ```

5. **Commit Your Changes**:
   ```bash
   git add .
   git commit -m "feat: your feature description"
   ```

6. **Push to Your Fork**:
   ```bash
   git push origin feature/your-feature-name
   ```

7. **Create Pull Request**:
   - Provide clear description of changes
   - Reference related issues
   - Ensure CI checks pass
   - Request review from maintainers

### Pull Request Checklist

- [ ] Code follows the project style guide
- [ ] All tests pass
- [ ] New tests added for new functionality
- [ ] Documentation updated
- [ ] Commit messages follow convention
- [ ] No merge conflicts
- [ ] Code is properly formatted

## Getting Help

- Check existing [documentation](docs/)
- Search [existing issues](https://github.com/martonban/RenderArc/issues)
- Create a new issue with detailed description
- Join community discussions

## License

By contributing to RenderArc, you agree that your contributions will be licensed under the same license as the project.
