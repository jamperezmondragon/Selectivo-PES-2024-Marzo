#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int LOGN = 18;

struct Edge{
	int u, v, w;
	bool operator < (const Edge &ed) const{
		return w > ed.w;
	}	
};

struct DSU{
private:
	vector<int> id, sz;
public:
	void build(int n){
		id.resize(n); sz.resize(n);
		iota(id.begin(), id.end(), 0);
		fill(sz.begin(), sz.end(), 1);
	}
	int findset(int u){
		return id[u] == u ? u : id[u] = findset(id[u]);
	}
	void joinset(int u, int v){
		int pu = findset(u), pv = findset(v);
		if(sz[pu] > sz[pv]) swap(pu, pv);
		id[pu] = pv;
		sz[pv] += sz[pu];
	}
};

struct TreeSparseTable{
private:
	int spr[MAXN + 1][LOGN + 1];
	int max_spr[MAXN + 1][LOGN + 1];
	int depth[MAXN + 1];
public:
	void build(vector<pair<int, int>> *adj){
		function<void(int, int)> dfs = [&](int v, int p){
			for(int x = 1; x <=LOGN; x++){
				spr[v][x] = spr[spr[v][x-1]][x-1];
				max_spr[v][x] = max(max_spr[v][x-1], max_spr[spr[v][x-1]][x-1]);
			}
			depth[v] = depth[p] + 1;
			for(auto [u, w] : adj[v]){
				if(u == p) continue;
				spr[u][0] = v;
				max_spr[u][0] = w;
				dfs(u, v);
			}
		};
		depth[0] = 0;
		spr[1][0] = 0;
		max_spr[1][0] = 0;
		dfs(1, 0);
	}
	pair<int, int> lca(int u, int v){
		int maxInPath = 0;
		if(depth[u] > depth[v]) swap(u, v);
		for(int x = LOGN; x >= 0; x--){
			if(depth[spr[v][x]] >= depth[u]){
				maxInPath = max(maxInPath, max_spr[v][x]);
				v = spr[v][x];
			}
		}
		if(u == v) return {u, maxInPath};
		for(int x = LOGN; x >= 0; x--){
			if(spr[v][x] != spr[u][x]){
				maxInPath = max(maxInPath, max_spr[v][x]);
				v = spr[v][x];
				maxInPath = max(maxInPath, max_spr[u][x]);
				u = spr[u][x];
			}
		}
		return {spr[u][0], max({maxInPath, max_spr[v][0], max_spr[u][0]})};
	}
};

vector<pair<int, int>> tree[MAXN + 1];
TreeSparseTable tspr;
DSU dsu;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin>> N>> M;

	priority_queue<Edge> pq;
	for(int i=0; i<M; i++){
		int u, v, w;
		cin>> u>> v>> w;
		pq.push({u, v, w});
	}

	dsu.build(N + 1);
	long long mstWeight = 0;
	while(!pq.empty()){
		auto [u, v, w] = pq.top();
		pq.pop();

		if(dsu.findset(u) == dsu.findset(v)){
			continue;
		}
		mstWeight += w;
		dsu.joinset(u, v);
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
	}

	tspr.build(tree);
	int Q;
	cin>> Q;
	while(Q--){
		int u, v;
		cin>> u>> v;
		auto l = tspr.lca(u, v);
		cout<< mstWeight - l.second<< '\n';
	}
	return 0;
}