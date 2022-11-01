#include <bits/stdc++.h>

constexpr int LIM = 1E6;

std::vector<int> Sieve() {
  const int S = (int) std::round(std::sqrt(LIM)), R = LIM / 2;
  std::vector<int> pr = {2}, sieve(S + 1); pr.reserve(int(LIM / std::log(LIM) * 1.1));
  std::vector<std::pair<int, int>> cp;
  for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
      cp.push_back({i, i * i / 2});
      for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
  for (int L = 1; L <= R; L += S) {
    std::vector<bool> block (S);
    for (auto& [p, idx] : cp) {
      for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
    }
    for (int i = 0; i < std::min(S, R - L); i++) {
      if (!block[i]) pr.push_back((L + i) * 2 + 1);
    }
  }
  return pr;
}