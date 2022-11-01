#pragma once


long long modmul(long long a, long long b, long long M) {
  long long ret = a * b - M * (long long)(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (long long) M);
}


long long modpow(long long b, long long e, long long M) {
  long long res = 1;
  for (; e; b = modmul(b, b, M), e /= 2) if (e & 1) res = modmul(res, b, M);
  return res;
}