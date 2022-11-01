#include <bits/stdc++.h>

template<typename T = long long>
struct FT {
  std::vector<T> s;

  explicit FT(int n) : s(n) {}

  void Update(int pos, T diff) { // a[pos] += diff
    for (; pos < (int) s.size(); pos |= pos + 1) s[pos] += diff;
  }

  T Query(int pos) { // sum of values in [0, pos)
    T res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }

  int LowerBound(T sum) { // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= (int) s.size() && s[pos + pw - 1] < sum) {
        pos += pw, sum -= s[pos - 1];
      }
    }
    return pos;
  }
};