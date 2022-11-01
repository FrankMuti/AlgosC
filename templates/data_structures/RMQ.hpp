#include <bits/stdc++.h>

template<typename T = int>
struct RMQ {
  std::vector<std::vector<T>> jmp;

  explicit RMQ(const std::vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= (int) V.size(); pw *= 2, ++k) {
      jmp.emplace_back(V.size() - pw * 2 + 1);
      for (int j = 0; j < (int) jmp[k].size(); j++) {
        jmp[k][j] = std::min(jmp[k - 1][j], jmp[k - 1][k + pw]);
      }
    }
  }

  T Query(int a, int b) {
    if (a == b) return INFINITY;
    int dep = 31 - __builtin_clz(b - a);
    return std::min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};