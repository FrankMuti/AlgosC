#include <bits/stdc++.h>

#include "Point.hpp"

template<typename T = double, typename P = Point<T>>
T SegDist(const P& s, const P& e, const P& p) {
  if (s == e) return (p - s).dist();
  auto d = (e - s).dist2(), t = std::min(d, std::max(.0, (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist() / d;
}