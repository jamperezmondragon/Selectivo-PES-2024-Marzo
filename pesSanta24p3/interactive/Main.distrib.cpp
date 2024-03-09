#include <bits/stdc++.h>
using namespace std;

int V[1024];
int N, query_cnt = 0, max_queries;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



vector<int> diferencias(int _, int S[]) {
  query_cnt++;
 if (query_cnt > max_queries) {
    cerr << "Has llamado la función similitud " << query_cnt
         << " veces, más de las que tenías permitido." << endl;
    cout << "0\n";
    exit(0);
  }
 vector<int> D;
  for (int i = 0; i < _; i++) {
    for (int j = i; j < _; j++) {
      D.push_back(abs(V[S[i]] - V[S[j]]));
    }
  }

  //randomize answer
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < (int)D.size() - 1; i++) {
      int j = (rng() % ((int)D.size() - i)) + i;
      swap(D[i], D[j]);
    }
  }
  return D;
}

int valor(int _) {
  query_cnt++;
  if (_ < N) {
    cerr << "El valor utilizado es inválido." << endl;
    cout << "0\n";
    exit(0);
  }
 if (query_cnt > max_queries) {
    cerr << "Has llamado la función similitud " << query_cnt
         << " veces, más de las que tenías permitido." << endl;
    cout << "0\n";
    exit(0);
  }

  return V[_];
}

void respuesta(int _, int S[]) {
  if (_ != N) {
    cerr << "El tamaño del arreglo es distinto a N." << endl;
    cout << "0\n";
    exit(0);
  }
  for (int i = 0; i < N; i++) {
    if (S[i] != V[i]) {
      cerr << "El arreglo en la respuesta es incorrecto." << endl;
      cout << "0\n";
      exit(0);
    }
  }
  cout << "1\n";
  exit(0);
}

int main() {
  int N; cin >> N >> max_queries;
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  EncontrarArreglo(N);
}
