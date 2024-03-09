#include <bits/stdc++.h>
using namespace std;

const int LOGN = 18, Mxn = 2e5 + 1;
vector<array<int, 3>> Edges;
vector<array<int, 2>> adj[Mxn];
int ST[LOGN + 1][Mxn];
int ST_max[LOGN + 1][Mxn];
int depth[Mxn];
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

void dfs(int node = 1, int parent = 1, int weight = 0) {
  ST[0][node] = parent;
  ST_max[0][node] = weight;
  depth[node] = depth[parent] + 1;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
    ST_max[i][node] = max(ST_max[i - 1][node], ST_max[i - 1][ST[i - 1][node]]);
  }
  for (auto [child, w] : adj[node]) {
    if (child == parent) continue;
    dfs(child, node, w);
  }
}

int jump(int node, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) node = ST[i][node];
  }
  return node;
}
long long int get_max(int node, int k, int ans = 0) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) {
      ans = max(ans, ST_max[i][node]); node = ST[i][node];
    }
  }
  return ans;
}

int LCA(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  a = jump(a, depth[a] - depth[b]);
  if (a == b) return a;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][a] != ST[i][b]) a = ST[i][a], b = ST[i][b];
  }
  return ST[0][a];
}

void query() {
  int s, t; cin >> s >> t;
  int lca = LCA(s, t);
  cout << Total_Sum - max(get_max(s, depth[s] - depth[lca]), get_max(t, depth[t] - depth[lca])) << '\n';
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
  dfs(1, 1, 0);
  int q; cin >> q;
  while (q--) {
    query();
  }
}
