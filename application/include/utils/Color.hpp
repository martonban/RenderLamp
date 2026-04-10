#ifndef COLOR_HPP
#define COLOR_HPP

#include <glm/vec3.hpp>
#include <algorithm>

class Color {
public:
	double r, g, b;

	Color() : r(0), g(0), b(0) {}
	Color(double r, double g, double b) : r(r), g(g), b(b) {}
	Color(const glm::dvec3& v) : r(v.r), g(v.g), b(v.b) {}

	Color operator+(const Color& other) const {
		return Color(r + other.r, g + other.g, b + other.b);
	}
	
    Color operator-(const Color& other) const {
		return Color(r - other.r, g - other.g, b - other.b);
	}
	
    Color operator*(double scalar) const {
		return Color(r * scalar, g * scalar, b * scalar);
	}
	
    Color operator*(const Color& other) const {
		return Color(r * other.r, g * other.g, b * other.b);
	}
	
    Color& operator+=(const Color& other) {
		r += other.r; g += other.g; b += other.b;
		return *this;
	}
	
    Color& operator*=(double scalar) {
		r *= scalar; g *= scalar; b *= scalar;
		return *this;
	}
	
    Color& operator*=(const Color& other) {
		r *= other.r; g *= other.g; b *= other.b;
		return *this;
	}
	
    void clamp(double minVal = 0.0, double maxVal = 1.0) {
		r = std::clamp(r, minVal, maxVal);
		g = std::clamp(g, minVal, maxVal);
		b = std::clamp(b, minVal, maxVal);
	}

	glm::dvec3 ToVec3() const { return glm::dvec3(r, g, b); }

    glm::ivec3 ToIntRGB() const {
		return glm::ivec3(
			static_cast<int>(std::clamp(r, 0.0, 1.0) * 255.0 + 0.5),
			static_cast<int>(std::clamp(g, 0.0, 1.0) * 255.0 + 0.5),
			static_cast<int>(std::clamp(b, 0.0, 1.0) * 255.0 + 0.5)
		);
	}
};

#endif
