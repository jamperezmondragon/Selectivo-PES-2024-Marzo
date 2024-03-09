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

    int N, T;
    cin>> N>> T;

    if(N < 1 || N > 2000){
        terminate_program();
    }
    if(T < 0 || T > 1e9){
        terminate_program();
    }
    
    for(int i=0; i<N; i++){
        int a, b;
        cin>> a>> b;
        if(a < 0 || a > 1e9){
            terminate_program();
        }
        if(b < 0 || b > 1e9){
            terminate_program();
        }
    }
    return 0;
}