#pragma once

#include <bits/stdc++.h>

#include "ModMulLL.hpp"
#include "MillerRabin.hpp"

using i64 = long long;


i64 pollard(i64 n) {
  auto f = [n](i64 x) { return modmul(x, x, n) + 1; };
  i64  x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  while (t++ % 40 || std::__gcd(prd, n) == 1) {
    if (x == y) x = ++i, y = f(x);
    if ((q = modmul(prd, std::max(x, y) - std::min(x, y), n))) prd = q;
    x = f(x), y = f(f(y));
  }
  return std::__gcd(prd, n);
}


std::vector<i64> factor(i64 n) {
  if (n == 1) return {};
  if (is_prime(n)) return {n};
  i64 x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}