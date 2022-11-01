#include <bits/stdc++.h>

constexpr int inf = 1E9;

template<typename T = int>
struct Node {
  Node* l = 0, *r = 0;
  int lo, hi;
  T m_set = inf, m_add = 0;
  T val = -inf;

  Node(int _lo, int _hi) : lo(_lo), hi(_hi) {}

  Node(std::vector<T>& v, int _lo, int _hi) : lo(_lo), hi(_hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = std::max(l->val, r->val);
    } else {
      val = v[lo];
    }
  }

  T Query(int L, int R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    Push();
    return std::max(l->Query(L, R), r->Query(L, R));
  }

  void Set(int L, int R, T x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) m_set = val = x, m_add = 0;
    else {
      Push();
      l->Set(L, R, x);
      r->Set(L, R, x);
      val = std::max(l->val, r->val);
    }
  }

  void Add(int L, int R, T x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (m_set != inf) m_set += x;
      else m_add += x;
      val += x;
    } else {
      Push();
      l->Add(L, R, x);
      r->Add(L, R, x);
      val = std::max(l->val, r->val);
    }
  }

  void Push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (m_set !=inf) {
      l->Set(lo, hi, m_set);
      r->Set(lo, hi, m_set);
      m_set = inf;
    } else if (m_add) {
      l->Add(lo, hi, m_add);
      r->Add(lo, hi, m_add);
      m_add = 0;
    }
  }
};