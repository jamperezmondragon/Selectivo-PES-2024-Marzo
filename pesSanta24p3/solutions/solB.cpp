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

auto cynthia(vector<int> A, vector<int> B, int t) -> vector<int> {
  map<int, int> cc;
  for (auto e : A) cc[e]++;
  for (auto e : B) cc[e]++;
  vector<int> Ans;
  for (auto [x, y] : cc) if (y == t) Ans.push_back(x);
  return Ans;
}

void EncontrarArreglo(int N) {
  int logn = 0;
  while ((1<<(logn + 1)) <= N) logn++;
  for (int i = 0; i < N; i++) dummy[i] = i;
  diferencias(N, dummy);
  int mx = 0;
  for (int i = 0; i < N*(N - 1)/2; i++) mx = max(D[i], mx);
  int pos = 0;
  for (int k = logn; k >= 0; k--) {
    if (pos + (1<<k) >= N) continue;
    for (int i = 0; i <= pos + (1<<k); i++) dummy[i] = i;
    diferencias(pos + (1<<k) + 1, dummy);
    int lmx = 0;
    for (int i = 0; i < (pos + (1<<k))*(pos + (1<<k) + 1)/2; i++) {
      lmx = max(D[i], lmx);
    }
    if (lmx != mx) pos += (1<<k);
  }
  pos++;

  vector<int> ptm;
  for (int i = 0; i < N; i++) {
    if (i == pos) continue;
    ptm.push_back(i);
  }
  ptm = F(ptm, pos);
  ptm.push_back(0);

  int x = valor(pos);

  for (int k = 0; k <= logn; k++) {
    vector<int> V;
    for (int i = 0; i < N; i++) {
      if (i == pos) continue;
      if ((i>>k)&1) V.push_back(i);
    }
    bits[1][k] = F(V, pos);
    if ((pos>>k)&1) bits[1][k].push_back(0);
  }
  for (int i = 0; i <= logn; i++) {
    bits[0][i] = cynthia(ptm, bits[1][i], 1);
  }

  for (int i = 0; i < N; i++) {
    vector<int> X = ptm;
    for (int k = 0; k <= logn; k++) {
      X = cynthia(X, bits[(i>>k)&1][k], 2);
    }
    ans[i] = X[0];
  }

  mx = 0;
  int pos_mx;
  for (auto e : ptm) mx = max(e, mx);
  for (int i = 0; i < N; i++) if (ans[i] == mx) pos_mx = i;
  int y = valor(pos_mx);

  for (int i = 0; i < N; i++) {
    if (x < y) ans[i] = ans[i] + x;
    else ans[i] = x - ans[i];
  }
  respuesta(N, ans);
}
