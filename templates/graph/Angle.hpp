#include <bits/stdc++.h>

template<typename T = int>
struct Angle {
  typedef Angle A;
  T x, y;
  T t;
  explicit Angle(T x, T y, T t = 0) : x(x), y(y), t(t) {}
  A operator-(A b) const { return {x - b.x, y - b,y, t}; }
  int half() const {
    assert(x || y);
    return y < 0 || (x == 0 && x < 0);
  }
  A t90() const { return {-y, x, t + (half() && x >= 0)}; }
  A t180() const { return {-x, -y, t + half()}; }
  A t360() const { return {x, y, t + 1}; }
};