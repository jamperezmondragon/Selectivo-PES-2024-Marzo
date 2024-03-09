#include <bits/stdc++.h>
using namespace std;

const int Mxn = 4001;
vector<array<int, 3>> Edges;
vector<array<int, 2>> adj[Mxn];
long long int Total_Sum = 0;

struct DSU {
  vector<int> leader, Sz;
  DSU() {
    leader.resize(Mxn); Sz.assign(Mxn, 1);
    iota(leader.begin(), leader.end(), 0);
  }
  int find(int x) {
    return ((x == leader[x]) ? x : (leader[x] = find(leader[x])));
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (Sz[x] < Sz[y]) swap(x, y);
    leader[y] = x; Sz[x] += Sz[y];
    return 1;
  }
} dsu;

stack<int> S;

bool dfs(int node, int parent, int target, int weight = 0) {
  S.push(weight);
  if (node == target) return 1;
  for (auto [child, w] : adj[node]) {
    if (child == parent) continue;
    if (dfs(child, node, target, w)) return 1;
  }
  S.pop();
  return 0;
}

void query() {
  int s, t; cin >> s >> t;
  dfs(s, 0, t);
  int aux = 0;
  while (S.size()) {
    aux = max(aux, S.top());
    S.pop();
  }
  cout << Total_Sum - aux << '\n';
}

int main() {
  int n, m; cin >> n >> m;
  Edges.resize(m);
  for (auto &[c, a, b] : Edges) {
    cin >> a >> b >> c;
  }
  sort(Edges.begin(), Edges.end());
  for (auto [c, a, b] : Edges) {
    if (dsu.unite(a, b)) {
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
      Total_Sum += c;
    }
  }
  int q; cin >> q;
  while (q--) {
    query();
  }
}
