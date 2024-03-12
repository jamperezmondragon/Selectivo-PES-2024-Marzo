#include <bits/stdc++.h>
using namespace std;

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
    a = (rng() % C.N) + 1;
    b = (rng() % C.N) + 1;
  }
}


int main() {
  return 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      string file_name = "sub";
      file_name += i;
      file_name += ".";
      file_name += j;
      file_name += ".in";

    }
  }
}
