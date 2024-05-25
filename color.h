#pragma once

#include <iostream>

#include "interval.h"
#include "vec3.h"

using color = vec3;

inline double linear_to_gamma(double linear_component) {
   return (linear_component > 0.0) ? sqrt(linear_component) : 0.0;
}

void write_color(std::ostream& out, const color& pixel_color) {
   // We need to apply a linear to gamma transform for gamma 2
   auto r = linear_to_gamma(pixel_color.x());
   auto g = linear_to_gamma(pixel_color.y());
   auto b = linear_to_gamma(pixel_color.z());

   // Translate the [0, 1] component values to the byte range [0, 255]
   static const interval intensity(0.000, 0.999);
   int rbyte = int(256 * intensity.clamp(r));
   int gbyte = int(256 * intensity.clamp(g));
   int bbyte = int(256 * intensity.clamp(b));

   // Write out the pixel color components
   out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}