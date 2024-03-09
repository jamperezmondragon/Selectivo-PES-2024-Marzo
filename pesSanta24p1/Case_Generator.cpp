#include <bits/stdc++.h>
using namespace std;

struct caso {
  int N, M, Q;
  vector<array<int, 3>> Edges;
  vector<array<int, 2>> Queries;
  void print(string file_name) {
    ofstream file_output;
    file_output.open(file_name);
    file_output << N << " " << N << '\n';
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

auto RngShuffle(vector<int> &V) {
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < (int)(V.size()) - 1; i++) {
      int j = (rng() % ((int)(V.size()) - i)) + i;
      swap(V[i], V[j]);
    }
  }
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

auto LineTree(int N, bool Random = false) -> vector<array<int, 2>> { // 1-indexed
  vector<array<int, 2>> V;
  vector<int> Aux(N);
  iota(Aux.begin(), Aux.end(), 1);
  if (Random) RngShuffle(Aux);
  for (int i = 1; i < N; i++) {
    V.push_back({Aux[i - 1], Aux[i]});
  }
  return V;
}

auto CaterpillarTree(int N, int K) -> vector<array<int, 2>> { // 1-indexed
  vector<array<int, 2>> V = LineTree(N);
  vector<int> Aux(N + K);
  iota(Aux.begin(), Aux.end(), 1);
  RngShuffle(Aux);
  for (auto &[a, b] : V) {
    a = Aux[a - 1]; b = Aux[b - 1];
  }
  for (int i = N; i < N + K; i++) {
    int j = (rng() % N - 2) + 1;
    V.push_back({Aux[i], Aux[j]});
  }
  return V;
}

auto StarTree(int N) -> vector<array<int, 2>> {
  vector<array<int, 2>> V;
  vector<int> Aux(N);
  iota(Aux.begin(), Aux.end(), 1);
  RngShuffle(Aux);
  for (int i = 1; i < N; i++) {
    V.push_back({Aux[0], Aux[i]});
  }
  return V;
}

auto NaryTree(int N, int depth, bool Random = false) -> vector<array<int, 2>> { // 1-indexed
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
  cnt = 0;
  map<int, int> cc;
  for (auto e : Aux) cc[e];
  for (auto &[x, y] : cc) y = cnt++;
  iota(Aux.begin(), Aux.end(), 1);
  if (Random) RngShuffle(Aux);
  for (auto &[x, y] : cc) y = Aux[y];
  for (auto &[a, b] : V) a = cc[a], b = cc[b];
  return V;
}

auto AddRandomNoiseToTree(vector<array<int, 2>> &V, int K) {
  int N = (int)V.size(); N++;
  for (int i = N + 1; i <= N + K; i++) {
    int j = (rng() % i - 1) + 1;
    V.push_back({j, i});
  }
}

auto GenerateRandomGraph(int N, int M) -> vector<array<int, 2>> { 
  /*
   * Genera un grafo no dirigido con N nodos y M aristas en esperanza, en O(N + M) tiempo en esperanza. 
   * Es la implementación del algoritmo 1 expuesto en el siguiente artículo:
   * Batagelj, Vladimir; Brandes, Ulrik (2005). Efficient generation of large random networks.
   * doi:10.1103/PhysRevE.71.036113
  */

  vector<array<int, 2>> Edges;
  assert(2LL*M < N*1LL*(N - 1) && N > 0);

  // La probabilidad adecuada para que el valor esperado sea M.
  long double p = ((long double) M*1LL*2 / (N*1LL*(N - 1)));
  int v = 1; long long int w = -1; 
  while (v < N) {
    long double r = ((long double) (rng() % (~0ULL) / (~0ULL)));
    w += 1 + (long long int)(log(1 - r)/log(1 - p));
    while (w >= v && v < N) {
      w -= v; v++;
    }
    if (v < N) Edges.push_back({v, w});
  }
  return Edges;
}

auto GraphWithSpanningTree(int N, int M, vector<array<int, 2>> V) -> vector<array<int, 2>> {
  set<array<int, 2>> S;
  for (auto e : V) S.insert(e);
  vector<array<int, 2>> Aux = GenerateRandomGraph(N, M - N + 1);
  for (auto e : Aux) if (!S.count(e)) V.push_back(e);
  return V;
}

auto GenerateCase(int subtask_num) -> caso {

}


int main() {
}

