#include "game.h"
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 250;
int V[MAXN];

void recibeRespuesta(int N, int A[]){
  
}

void EncontrarArreglo(int N){
    for(int i=0; i<N; i++){
        V[i] = valor(i);
    }
    respuesta(N, V);
}
