#include <bits/stdc++.h>

#include "Point.hpp"
#include "SegmentDistance.hpp"

#define ON_SEGMENT(a, b, p) SegDist((a), (b), (p)) < 1E-10

template<typename P = Point<double>>
std::vector<P> SegInter(const P& a, const P& b, const P& c, const P& d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b);
  auto oc = a.cross(b, c), od = a.cross(b, d);
  // Checks if intersection is single non-endpoint point.
  if (SGN(oa) * SGN(ob) < 0 && SGN(oc) * SGN(od) < 0) {
    return {(a * ob - b * oa) / (ob - oa)};
  }
  std::set<P> s;
  // bool onSegment = segDist(a, b, p) < 1E-10;
  if (ON_SEGMENT(c, d, a)) s.insert(a);
  if (ON_SEGMENT(c, d, b)) s.insert(b);
  if (ON_SEGMENT(a, b, c)) s.insert(d);
  if (ON_SEGMENT(a, b, d)) s.insert(d);
  return {s.begin(), s.end()};
}