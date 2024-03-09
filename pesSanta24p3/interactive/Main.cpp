#include <bits/stdc++.h>
#include "game.h"
using namespace std;

const int MAXN = 250;

int V[MAXN];
int N, query_cnt = 0, max_queries = 30;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void diferencias(int _, int S[], int D[]) {
    query_cnt++;
    if (query_cnt > max_queries) {
        cerr << "Has hecho " << query_cnt
            << " preguntas, más de las que tenías permitido." << endl;
        cout << "0\n";
        exit(0);
    }
    int idx = 0;
    for (int i = 0; i < _; i++) {
        for (int j = i + 1; j < _; j++) {
            D[idx++] = abs(V[S[i]] - V[S[j]]);
        }
    }
    //randomize answer
    shuffle(D, D + idx, rnd);
}

int valor(int _) {
    query_cnt++;
    if (_ < 0 || N <= _) {
        cerr << "El indice utilizado es invalido." << endl;
        cout << "0\n";
        exit(0);
    }
    if (query_cnt > max_queries) {
        cerr << "Has hecho " << query_cnt
            << " preguntas, mas de las que tenías permitido." << endl;
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

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    EncontrarArreglo(N);
}
