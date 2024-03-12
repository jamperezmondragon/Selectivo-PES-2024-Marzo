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

// Juan random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

vector<array<int, 2>> getTreeFromFile(int &N, string casename){
    ifstream fin;
    fin.open("generator/graphs/tree-"+ casename + ".in");

    fin>> N;

    vector<array<int, 2>> T;
    for(int i=1; i<N; i++){
        int u, v;
        fin>> u>> v;
        T.push_back({u + 1, v + 1});
    }
    fin.close();

    return T;
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
        if(subtask == 1){
            n_limitL = 1;
            n_limitR = 1e5;
            num_of_cases = 1;
            start_point = 12;
        }
        else if(subtask == 2){
            n_limitL = 1;
            n_limitR = 4000;
            num_of_cases = 1;
            start_point = 12;
        }
        else if(subtask == 3){
            n_limitL = 1;
            n_limitR = 1e5;
            num_of_cases = 1;
            start_point = 12;
        }
        for(int case_n = 0; case_n < num_of_cases; case_n++){
            int case_number = case_n + start_point;
            string casename;
			if(subtask == -1){
				casename = "sample" + to_string(case_number);
			}
			else{
				casename = "sub" + to_string(subtask) + "." + to_string(case_number);
			}
            string filename = "cases/" + casename + ".in";

			int N, M, Q;
            vector<array<int, 2>> tree = getTreeFromFile(N, casename);
            long long totalEdges = (N * (N - 1))/2;
            M = min(totalEdges, (long long)get_random(1e5, 2e5));
            Q = 1e5;
            if(subtask == 1){
                Q = 1;
            }
            if(subtask == 2){
                Q = 4000;
            }

            vector<array<int, 3>> graph = graphWithTreeMST(N, M, tree);

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