#include <bits/stdc++.h>

#define MP std::make_pair
#define LTJ(X) if (s == -1 || MP(X[j], N[j]) < MP(X[s], N[s])) s = j;
#define REP(i, a, b) for (int i = (a); i < (b); i++)

template<typename T = double>
struct LPSolver {
  const T eps = 1E-8;
  const T inf = 1 / .0;

  int m, n;
  std::vector<int> N, B;
  std::vector<std::vector<T>> D;

  LPSolver(const std::vector<std::vector<T>>& A, const std::vector<T>& b, const std::vector<T>& c) : m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, std::vector<T>(n + 2)){
    REP(i, 0, m) REP(j, 0, n) D[i][j] = A[i][j];
    REP(i, 0, m) { B[i] = n + 1; D[i][n] = -1; D[i][n + 1] = b[i]; }
    REP(j, 0, n) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1;
    D[m + 1][n] = 1;
  }

  void Pivot(int r, int s) {
    T *a = D[r].data(), inv = 1 / a[s];
    REP(i, 0, m + 2) if (i != r && std::abs(D[i][s]) > eps) {
      T *b = D[i].data(), inv2 = b[s] * inv;
      REP(j, 0, n + 2) b[j] -= a[j] * inv2;
      b[s] = a[s] * inv2;
    }
    REP(j, 0, n + 2) if (j != s) D[r][j] *= inv;
    REP(i, 0, m + 2) if (i != r) D[i][s] *= -inv;
    D[r][s] = inv;
    std::swap(B[r], N[s]);
  }

  bool Simplex(int phase) {
    int x = m + phase - 1;
    for (;;) {
      int s = -1;
      REP(j, 0, n + 1) if (N[j] != -phase) LTJ(D[x]);
      if (D[x][s] >= -eps) return true;
      int r = -1;
      REP(i, 0, m) {
        if (D[i][s] <= eps) continue;
        if (r == -1 || MP(D[i][n + 1] / D[i][s], B[i]) < MP(D[r][n + 1] / D[r][s], B[r])) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }

  T Solve(std::vector<T>& x) {
    int r = 0;
    REP(i, 1, m) if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -eps) {
      Pivot(r, n);
      if (!Simplex(2) || D[m + 1][n + 1] < -eps) return -inf;
      REP(i, 0, m) if (B[i] == -1) {
        int s = 0;
        REP(j, 1, n + 1) LTJ(D[i]);
        Pivot(i, s);
      }
    }
    bool ok = Simplex(1);
    x = std::vector<T> (n);
    REP(i, 0, m) if (B[i] < n) x[B[i]] = D[i][n + 1];
    return ok ? D[m][n + 1] : inf;
  }
};






/*
 * Usage
 *
 * std::vector<std::vector<double>> A = {{-1, -1}, {-1, -1}, {-1, -2}};
 * std::vector<double> b = {1, 1, -4}, c = {-1, -1}, x;
 * T val = LPSolver(A, b, c).solve(x)
 */