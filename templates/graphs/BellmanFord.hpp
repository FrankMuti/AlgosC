#include <bits/stdc++.h>

const long long inf = LLONG_MAX;

struct Edge {
  int a, b, w;
  int s() const { return a < b ? a : -a; }
};

struct Node {
  long long dist = inf;
  int prev = -1;
};

void BellmanFord(std::vector<Node>& nodes, std::vector<Edge>& edges, int s) {
  nodes[s].dist = 0;
  std::sort(edges.begin(), edges.end(), [&] (const Edge& a, const Edge& b) {
    return a.s() < b.s();
  });
  int lim = ((int) nodes.size()) / 2 + 2;
  for (int i = 0; i < lim; i++) {
    for (const Edge& ed : edges) {
      Node cur = nodes[ed.a], &dest = nodes[ed.b];
      if (std::abs(cur.dist) == inf) continue;
      long long d = cur.dist + ed.w;
      if (d < dest.dist) {
        dest.prev = ed.a;
        dest.dist = (i < lim - 1 ? d : -inf);
      }
    }
  }
  for (int i = 0; i < lim; i++) {
    for (const Edge& e : edges) {
      if (nodes[e.a].dist == -inf) {
        nodes[e.b].dist = -inf;
      }
    }
  }
}