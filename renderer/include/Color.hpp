//------------------------------------------------------------------------------------------------
//                                       RenderLamp - Color
//                                       Márton Bán (C) 2025
//	
//  This class is the same class what you can read in the Ray Tracing In On Weekend series.
//  To be fair at this level there is no difference :D
//------------------------------------------------------------------------------------------------


#ifndef COLOR_HPP
#define COLOR_HPP

#include <glm/vec3.hpp>

#include <iostream>

using color = glm::dvec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}


#endif