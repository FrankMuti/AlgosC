#include <bits/stdc++.h>

#include "Point.hpp"

template<typename P = Point<double>>
double LineDist(const P& a, const P& b, const P& p) {
  return (double) (b - a).cross(p - a) / (b - a).dist();
}