#include<bits/stdc++.h>

using namespace std;

void terminate_program(){
    int x = 0;
    while(true){
        x++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int N, M;
    cin>> N>> M;

    if(N < 1 || N > 1e5){
        terminate_program();
    }
    if(M < N-1 || M > 2e5){
        terminate_program();
    }

    set<pair<int, int>> setOfEdges;

    for(int i=0; i<M; i++){
        int u, v, w;
        cin>> u>> v>> w;
        if(u < 1 || u > N){
            terminate_program();
        }
        if(v < 1 || v > N){
            terminate_program();
        }
        if(u == v){
            terminate_program();
        }
        if(w < 1 || w > 1e9){
            terminate_program();
        }
        setOfEdges.insert({u, v});
        setOfEdges.insert({v, u});
    }

    if(setOfEdges.size() != 2 * M){
        terminate_program();
    }

    int Q;
    cin>> Q;

    if(Q != 1){
        terminate_program();
    }

    for(int i=0; i<Q; i++){
        int u, v;
        cin>> u>> v;
        if(u < 1 || u > N){
            terminate_program();
        }
        if(v < 1 || v > N){
            terminate_program();
        }
        if(u == v){
            terminate_program();
        }
    }

    int x;
    while(cin>> x){
        terminate_program();
    }
    return 0;
}