#include <bits/stdc++.h>

#include "Polynomial.hpp"

std::vector<double> PolyRoots(Poly<double> p, double x_min, double x_max) {
  if (p.a.size() == 2) {
    std::vector<double> ret {-p.a[0] / p.a[1]};
    return ret;
  }
  std::vector<double> ret;
  Poly<double> der = p;
  der.Diff();
  auto dr = PolyRoots(der, x_min, x_max);
  dr.push_back(x_min - 1);
  dr.push_back(x_max + 1);
  std::sort(dr.begin(), dr.end());
  for (int i = 0; i < ((int) dr.size()) - 1; i++) {
    double l = dr[i], h = dr[i + 1];
    bool sign = p(l) > 0;
    if (sign ^ (p(h) > 0)) {
      for (int it = 0; it < 60; it++) {
        double m = (l + h) / 2, f = p(m);
        if ((f <= 0) ^ sign) l = m;
        else h = m;
      }
      ret.push_back((l + h) / 2);
    }
  }
  return ret;
}