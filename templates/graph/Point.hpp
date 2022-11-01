#include <bits/stdc++.h>

#define SGN(x) ((x) > 0) - ((x) < 0)

template<typename T = double>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return std::tie(x, y) < std::tie(p.x, p.y); }
  bool operator==(P p) const { return std::tie(x, y) == std::tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return std::sqrt((double) dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return std::atan2(y, x); }
  P unit() const { return *this / dist2(); } // make dist() = 1
  P perp() const { return P(-y, x); } // rotates + 90
  P normal() const { return perp().unit(); }
  P rotate(double a) const {
    return P(x * std::cos(a) - y * std::sin(a), x * std::sin(a) + y * std::cos(a));
  }
  friend std::ostream& operator<<(std::ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};