#include <bits/stdc++.h>

template<typename T = double>
struct Poly {
  std::vector<T> a;

  T operator() (T x) const {
    T val = 0;
    for (int i = (int) a.size(); i--; ) (val *= x) += a[i];
    return val;
  }

  void Diff() {
    for (int i = 1; i < (int) a.size(); i++) {
      a[i - 1] = i * a[i];
    }
    a.pop_back();
  }

  void DivRoot(T x0) {
    T b = a.back(), c;
    a.back() = 0;
    for (int i = ((int) a.size()) - 1; i--; ) c = a[i], a[i] = a[i + 1] * x0 + b, b = c;
    a.pop_back();
  }
};