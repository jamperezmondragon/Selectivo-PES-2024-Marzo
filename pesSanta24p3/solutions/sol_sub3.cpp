#include <bits/stdc++.h>
#include "game.h"
using namespace std;


int D[250*250];
void recibeRespuesta(int N, int A[]) {
  for(int i = 0; i < N; i++) {
    D[i] = A[i];
  }
}

vector<int> bits[2][9];
int dummy[250];
int ans[250];



auto F(vector<int> V, int X) -> vector<int> {
  int N = V.size();
  map<int, int> cc;
  vector<int> Ans;
  {
    int i = 0;
    for(auto e : V) dummy[i++] = e;
  }
  dummy[N] = X;
  diferencias(N + 1, dummy);
  for (int i = 0; i < N*(N + 1)/2; i++) cc[D[i]]++;
  diferencias(N, dummy);
  for (int i = 0; i < N*(N - 1)/2; i++) cc[D[i]]--;
  for (auto [x, y] : cc) if (y) Ans.push_back(x);
  return Ans;
}


auto symmetricDiff(vector<int> A, vector<int> B) -> vector<int> {
  map<int, int> cc;
  for (auto e : A) cc[e]++;
  for (auto e : B) cc[e]++;
  vector<int> Ans;
  for (auto [x, y] : cc) if (y == 1) Ans.push_back(x);
  return Ans;
}

auto intersection(vector<int> A, vector<int> B) -> vector<int> {
  map<int, int> cc;
  for (auto e : A) cc[e]++;
  for (auto e : B) cc[e]++;
  vector<int> Ans;
  for (auto [x, y] : cc) if (y == 2) Ans.push_back(x);
  return Ans;
}

void EncontrarArreglo(int N) {
  int logn = 0;
  map<int, int> cc;
  while ((1<<(logn + 1)) <= N) logn++;
  for (int k = 0; k <= logn; k++) {
    vector<int> V;
    for (int i = 1; i < N; i++) {
      if ((i>>k)&1) V.push_back(i);
    }
    bits[1][k] = F(V, 0);
    for (auto &e : bits[1][k]) cc[++e];
  }
  ans[0] = 1;
  vector<int> V;
  for (auto [x, y] : cc) V.push_back(x);
  for (int i = 0; i <= logn; i++) {
    bits[0][i] = symmetricDiff(V, bits[1][i]);
  }

  for (int i = 1; i < N; i++) {
    vector<int> X = V;
    for (int k = 0; k <= logn; k++) {
      X = intersection(X, bits[(i>>k)&1][k]);
    }
    ans[i] = X[0];
  }
  respuesta(N, ans);
}
