#include <bits/stdc++.h>

template<typename T = int>
struct Tree {
  static constexpr T unit = INT_MIN;
  std::vector<T> s;
  int n;

  explicit Tree(int _n = 0, T def = unit) : s (2 * n, def), n (_n) {}

  T F(T a, T b) {
    return std::max(a, b); // any associative fn
  }

  void Update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;) {
      s[pos] = F(s[pos * 2], s[pos * 2 + 1]);
    }
  }

  T Query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = F(ra, s[b++]);
      if (e % 2) rb = F(rb, s[--e]);
    }
    return F(ra, rb);
  }
};