#include <bits/stdc++.h>

#include "Point.hpp"

template<typename P = Point<double>>
int SideOf(P s, P e, P p) {
  return SGN(s.cross(e, p));
}

template<typename P = Point<double>>
int SideOf(const P& s, const P& e, const P& p, double eps) {
  auto a = (e - s).cross(p - s);
  double l = (e - s).dist() * eps;
  return (a > 1) - (a < -1);
}

template<typename P = Point<double>>
bool OnSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}