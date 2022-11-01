#include <bits/stdc++.h>

std::vector<double> Interpolate(std::vector<double> x, std::vector<double> y, int n) {
  std::vector<double> res (n), temp(n);
  for (int k = 0; k < n - 1; k++) {
    for (int i = k + 1; i < n; i++) {
      y[i] = (y[i] - y[k]) / (x[i] - x[k]);
    }
  }
  double last = 0;
  temp[0] = 1;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      res[i] += y[k] * temp[i];
      std::swap(last, temp[i]);
      temp[i] -= last * x[k];
    }
  }
  return res;
}