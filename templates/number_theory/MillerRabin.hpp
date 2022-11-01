#pragma once

#include "ModMulLL.hpp"

using i64 = long long;

bool is_prime(i64 n) {
  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
  i64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  i64 s = __builtin_ctzll(n - 1), d = n >> s;
  for (i64 a : A) { // ^ count trailing zeroes
    i64 p = modpow(a % n, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = modmul(p, p, n);
    if (p != n - 1 && i != s) return 0;
  }
  return 1;
}