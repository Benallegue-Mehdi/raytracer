#pragma once

#include <limits>
#include <random>

// Constants
constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

// Utility functions
inline double degrees_to_radians(double degrees) {
   return degrees * pi / 180.0;
}



inline double random_double() {
   // Returns a random real in [0, 1)
   static std::random_device rd{};
   static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
   static std::mt19937 generator{ ss };
   static std::uniform_real_distribution<double> distribution(0.0, 1.0);
   return distribution(generator);
}

inline double random_double(double min, double max) {
   // Returns a random real in [min, max)
   return min + (max - min) * random_double();
}
