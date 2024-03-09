#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
struct stvalue{
    long long a, b;
    bool operator < (const stvalue &x) const{
        return b < x.b;
    }
};
stvalue A[MAXN + 1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, T;
    cin>> N>> T;

    for(int i=0; i<N; i++){
        cin>> A[i].a>> A[i].b;
    }
    sort(A, A + N);

    int res = 0;
    long long t = 0;
    for(int i=0; i<N; i++){
        t++;
        t += A[i].a * t + A[i].b;
        if(t > T) break;
        res++;
    }
    cout<< res;
    return 0;
}