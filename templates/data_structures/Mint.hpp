#include <iostream>
#include <cassert>

constexpr int Mod = (int) 1E9 + 7;

template<int P = Mod>
int norm(int x) {
  if (x < 0) {
    x += P;
  }
  if (x >= P) {
    x -= P;
  }
  return x;
}

template<class T>
T power(T a, long long b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template<int P = Mod>
struct Mint {
  int x;

  explicit Mint(int x = 0) : x(norm(x)) {}
  explicit Mint(int64_t x) : x(norm(x % P)) {}

  [[nodiscard]] int val() const { return x; }

  Mint operator-() const {
    Mint(norm(P - x));
  }

  Mint inv() const {
    assert(x != 0);
    return power(*this, P - 2);
  }

  Mint &operator*=(const Mint& rhs) {
    x = int64_t(x) * rhs.x % P;
    return *this;
  }

  Mint &operator+=(const Mint& rhs) {
    x = norm(x + rhs.x);
    return *this;
  }

  Mint &operator-=(const Mint& rhs) {
    x = norm(x - rhs.x);
    return *this;
  }

  Mint &operator/=(const Mint& rhs) {
    return *this *= rhs.inv();
  }

  friend Mint operator*(const Mint& lhs, const Mint& rhs) {
    Mint res = lhs;
    res *= rhs;
    return res;
  }

  friend Mint operator+(const Mint& lhs, const Mint& rhs) {
    Mint res = lhs;
    res += rhs;
    return res;
  }

  friend Mint operator-(const Mint& lhs, const Mint& rhs) {
    Mint res = lhs;
    res -= rhs;
    return res;
  }

  friend Mint operator/(const Mint& lhs, const Mint& rhs) {
    Mint res = lhs;
    res /= rhs;
    return res;
  }

  friend std::istream &operator>>(std::istream &is, Mint &a) {
    int64_t v;
    is >> v;
    a = Mint(v);
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const Mint& a) {
    return os << a.val();
  }
};
