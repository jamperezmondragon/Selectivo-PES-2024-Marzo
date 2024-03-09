#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
const int MAXT = 2000;
struct stvalue{
    long long a, b;
    bool operator < (const stvalue &x) const{
        return x.a * (b + 1) < a * (x.b + 1);
    }
};
stvalue A[MAXN + 1];
int dp[MAXN + 2][MAXT + 1];

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
    for(int i=0; i<=N; i++){
        for(int t=0; t<=T; t++){
            res = max(res, dp[i][t]);
            long long nxt_t = t + 1 + A[i].a * (t + 1) + A[i].b;
            if(i < N){
                dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
                if(nxt_t <= T){
                    dp[i + 1][nxt_t] = max(dp[i + 1][nxt_t], dp[i][t] + 1);
                }
            }
        }
    }
    cout<< res;
    return 0;
}