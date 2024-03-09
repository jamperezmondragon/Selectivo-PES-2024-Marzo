#include <bits/stdc++.h>
using namespace std;

const int Mxn = 2e5 + 1;
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

int main() {
  int n, m; cin >> n >> m;
  Edges.resize(m);
  for (auto &[c, a, b] : Edges) {
    cin >> a >> b >> c;
  }
  int q; cin >> q; 
  int s, t; cin >> s >> t;
  Edges.push_back({0, s, t});
  sort(Edges.begin(), Edges.end());
  
  for (auto [c, a, b] : Edges) {
    if (dsu.unite(a, b)) {
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
      Total_Sum += c;
    }
  }
  cout << Total_Sum << endl;
}
