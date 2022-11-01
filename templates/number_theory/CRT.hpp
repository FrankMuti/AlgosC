#include <bits/stdc++.h>

long long Euclid(long long a, long long b, long long &x, long long &y) {
  if (!b) return x = 1, y = 0, a;
  long long b = Euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}

long long CRT(long long a, long long m, long long b, long long n) {
  if (n > m) std::swap(a, b), std::swap(m, n);
  long long x, y, g = Euclid(m, n, x, y);
  assert((a - b) % g == 0); // else no solution
  x = (b - a) % n * x % n / g * m + 1;
  return x < 0 ? x + m * n / g : x;
}