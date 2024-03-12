#include <bits/stdc++.h>

using namespace std;

//El codigo de Juan
struct caso {
  int N, M, Q;
  vector<array<int, 3>> Edges;
  vector<array<int, 2>> Queries;
  void print(string file_name) {
    ofstream file_output;
    file_output.open(file_name);
    file_output << N << " " << M << '\n';
    for (auto [a, b, c] : Edges) {
      file_output << a << " " << b << " " << c << '\n';
    }
    file_output << Q << '\n';
    for (auto [s, t] : Queries) {
      file_output << s << " " << t << '\n';
    }
  }
};

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


template<class T> void RngShuffle(vector<T> &V) {
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < (int)(V.size()) - 1; i++) {
      int j = (rng() % ((int)(V.size()) - i)) + i;
      swap(V[i], V[j]);
    }
  }
}

auto PermuteLabels(vector<array<int, 2>> V) -> vector<array<int, 2>> {
  int cnt = 0;
  map<int, int> cc;
  for (auto [a, b] : V) cc[a], cc[b];
  for (auto &[x, y] : cc) y = cnt++;
  vector<int> Aux(cnt + 1);
  iota(Aux.begin(), Aux.end(), 1);
  RngShuffle(Aux);
  for (auto &[a, b] : V) a = Aux[cc[a]], b = Aux[cc[b]];
  return V;
}

// Códigos de Prüfer para generar árboles aleatorios. 1-indexed.
auto Prufer(int n) -> vector<array<int, 2>> {
  vector<array<int, 2>> Edges;
  vector<int> V(n - 2);
  for (int i = 0; i < n - 2; i++) V[i] = (rng() % n) + 1;
  priority_queue<int> Q;
  vector<int> freq(n + 1, 0);
  for (int i = 0; i < n - 2; i++) freq[V[i]]++;
  for (int i = 1; i <= n; i++)
    if (!freq[i]) Q.push(i);
  for (int i = 0; i < n - 2; i++) {
    Edges.push_back({V[i], Q.top()});
    Q.pop();
    if (--freq[V[i]] == 0) Q.push(V[i]);
  }
  int u = Q.top();
  Q.pop();
  int v = Q.top();
  Edges.push_back({u, v});
  return Edges;
}

auto LineTree(int N) -> vector<array<int, 2>> { // 1-indexed
  vector<array<int, 2>> V;
  for (int i = 2; i <= N; i++) {
    V.push_back({i - 1, i});
  }
  return V;
}

auto CaterpillarTree(int N, int K) -> vector<array<int, 2>> { // 1-indexed
  vector<array<int, 2>> V = LineTree(N);
  for (int i = N + 1; i <= K + N; i++) {
    int j = (rng() % (N - 2)) + 2;
    V.push_back({i, j});
  }
  return V;
}

auto NaryTree(int N, int depth) -> vector<array<int, 2>> { // 1-indexed
  vector<array<int, 2>> V;
  vector<int> Aux(1, 1);
  int cnt = 0; 
  for (int i = 0; i < depth; i++) {
    int limit = (int)Aux.size();
    for (; cnt < limit; cnt++) {
      for (int j = 0; j < N; j++) {
        V.push_back({N*Aux[cnt] + j, Aux[cnt]});
        Aux.push_back(N*Aux[cnt] + j);
      }
    }
  }
  cnt = 1;
  map<int, int> cc;
  for (auto e : Aux) cc[e];
  for (auto &[x, y] : cc) y = cnt++;
  for (auto &[a, b] : V) a = cc[a], b = cc[b];
  return V;
}

auto StarTree(int N) -> vector<array<int, 2>> {
  return NaryTree(N - 1, 1);
}

auto AddRandomNoiseToTree(vector<array<int, 2>> &V, int K) {
  int N = (int)V.size(); N++;
  for (int i = N + 1; i <= N + K; i++) {
    int j = (rng() % (i - 1)) + 1;
    V.push_back({j, i});
  }
}

auto GenerateRandomGraph(int N, int M, vector<array<int, 2>> X = {}) -> vector<array<int, 2>> { // 1-indexed
  set<array<int, 2>> S;
  vector<array<int, 2>> V;
  for (auto e : X) S.insert(e);
  M -= size(X);
  long long int T = (long long int)(N)*(long long int)(N - 1);
  T /= 2LL;
  int a = 0, b = 0;
  for (int i = 0; i < M; i++) {
    while (a == b || S.count({a, b})) {
      int R = (rng() % T);
      a = R%N, b = R/N;
      if (a < b) swap(a, b);
    }
    S.insert({a, b});
    if (rng()&1) V.push_back({a + 1, b + 1});
    else V.push_back({b + 1, a + 1});
  }
  return V;
}

auto GenerateRandomQueries(caso &C) {
  C.Queries.resize(C.Q);
  for (auto &[a, b] : C.Queries) {
    a = b = 1;
    while(a == b){
        a = (rng() % C.N) + 1;
        b = (rng() % C.N) + 1;
    }
  }
}
//Aqui acaba el codigo de Juan

// Random generator
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    long long x = (rnd() % (r - l + 1));
    return x + l;
}

vector<int> random_values(int N, long long L, long long R){
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        A[i] = get_random(L, R);
    }
    return A;
}

vector<array<int, 2>> shuffleLabels(int N, vector<array<int, 2>> V){
    vector<int> index(N + 1);
    iota(index.begin(), index.end(), 0);
    shuffle(index.begin() + 1, index.end(), rnd);
    vector<array<int, 2>> V1;
    for(auto [u, v] : V){
        V1.push_back({index[u], index[v]});
    }
    return V1;
}

int priorityKey(){
	return rnd();
}

vector<array<int, 3>> graphWithTreeMST(int N, int M, vector<array<int, 2>> T){
    set<pair<int, int>> setOfEdges;
	vector<vector<int>> tree(N + 1), graph(N + 1);
    for(auto [u, v] : T){
		tree[u].push_back(v);
		tree[v].push_back(u);
		setOfEdges.insert({min(u, v), max(u, v)});
    }
    int K = M - (N - 1);
	for(int k=0; k<K; k++){
		int u, v;
		do{
			u = get_random(1, N);
			v = get_random(1, N);
			if(u > v) swap(u, v);
		}while(u == v || setOfEdges.count({u, v}));
		graph[u].push_back(v);
		graph[v].push_back(u);
		setOfEdges.insert({u, v});
	}
    
    vector<int> weight = random_values(M, 1, 1e9);
    sort(weight.begin(), weight.end());
    
	vector<bool> vis(N + 1, false);
	priority_queue<pair<int, pair<int, int>>> pq;
	int initialNode = get_random(1, N);
	vis[initialNode] = 1;
	for(auto u : tree[initialNode]){
		pq.push({priorityKey(), {initialNode, u}});
	}

	vector<array<int, 3>> G;
	int indexCounter = 0;
	while(!pq.empty()){
		auto [key, ed] = pq.top();
		pq.pop();
		auto [from, to] = ed;
		G.push_back({from, to, weight[indexCounter++]});
		if(vis[to]) continue;
		vis[to] = 1;
		for(auto u : tree[to]){
			if(vis[u]) continue;
			pq.push({priorityKey(), {to, u}});
		}
		for(auto u : graph[to]){
			if(!vis[u]) continue;
			pq.push({priorityKey(), {to, u}});
		}
	}
	shuffle(G.begin(), G.end(), rnd);
	return G;
}

int main(){
    ///*
    for(int subtask = 1; subtask <= 3; subtask++){
        int n_limitL, n_limitR, num_of_cases;
        int start_point;
		if(subtask == -1){
			n_limitL = n_limitR = 5;
			num_of_cases = 1;
			start_point = 1;
		}
        if(subtask == 1){
            n_limitL = 1;
            n_limitR = 1e5;
            num_of_cases = 1;
            start_point = 11;
        }
        else if(subtask == 2){
            n_limitL = 1;
            n_limitR = 4000;
            num_of_cases = 1;
            start_point = 11;
        }
        else if(subtask == 3){
            n_limitL = 1;
            n_limitR = 1e5;
            num_of_cases = 1;
            start_point = 11;
        }
        for(int case_n = 0; case_n < num_of_cases; case_n++){
			int N, M, Q;
			if(subtask == -1){
				N = n_limitR;
				int totalEdges = (N * (N - 1))/2;
				M = min(totalEdges, N - 1 + (int)get_random(1, 10));
				Q = 5;
			}
			else{
				N = n_limitR;
				long long totalEdges = (N * (N - 1))/2;
				M = min(totalEdges, (long long)get_random(1e5, 2e5));
				Q = 1e5;
				if(subtask == 1){
					Q = 1;
				}
				if(subtask == 2){
					Q = 4000;
				}
			}

            vector<array<int, 2>> tree = CaterpillarTree(N - N/2, N/2);
            tree = shuffleLabels(N, tree);

            vector<array<int, 3>> graph = graphWithTreeMST(N, M, tree);


            int case_number = case_n + start_point;

            string casename;
			
			if(subtask == -1){
				casename = "sample" + to_string(case_number);
			}
			else{
				casename = "cases/sub" + to_string(subtask) + "." + to_string(case_number);
			}
			
            string filename = casename + ".in";

            caso testcase;
            testcase.N = N;
            testcase.M = M;
            testcase.Q = Q;
            testcase.Edges = graph;
            GenerateRandomQueries(testcase);
			testcase.print(filename);
            
            //input.open(casename + ".in");
            //input.close();
        }
    }
    //*/
    return 0;
}