#include <bits/stdc++.h>
#include "game.h"
using namespace std;

int D[250*250];
int dummy[250];
int ans[250];

vector<int> F(vector<int> V, int X){
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

void recibeRespuesta(int N, int A[]){
  for(int i=0; i<N; i++){
    D[i] = A[i];
  }
}

void EncontrarArreglo(int N) {
  int x = valor(0), y = valor(N - 1);
  vector<int> V(N - 1);
  iota(V.begin(), V.end(), 1);
  vector<int> X = F(V, 0);
  if (x < y) {
    for (auto &e : X) e += x;
  } else {
    for (auto &e : X) e = x - e;
  }
  reverse(X.begin(), X.end());
  X.push_back(x);
  reverse(X.begin(), X.end());
  for (int i = 0; i < X.size(); i++) ans[i] = X[i];
  respuesta(X.size(), ans);
}
