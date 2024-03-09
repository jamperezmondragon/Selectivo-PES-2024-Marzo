#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
struct stvalue{
    long long a, b;
    bool operator < (const stvalue &x) const{
        return x.a * (b + 1) < a * (x.b + 1);
    }
};
stvalue A[MAXN + 1];
long long dp[MAXN + 1][MAXN + 1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, T;
    cin>> N>> T;

    for(int i=1; i<=N; i++){
        cin>> A[i].a>> A[i].b;
    }
    sort(A + 1, A + N + 1);
    
    int res = 0;
    dp[1][1] = 1 + A[1].a + A[1].b;
    dp[1][0] = 0;
    for(int i=2; i<=N; i++){
        dp[i][0] = 0;
        for(int j=1; j<=i; j++){
            if(j < i) dp[i][j] = dp[i-1][j];
            else dp[i][j] = INT32_MAX;
            if(dp[i-1][j-1] < INT32_MAX){
                dp[i][j] = min(dp[i][j], (A[i].a + 1) * (dp[i-1][j-1] + 1) + A[i].b);
            }
            if(dp[i][j] > T){
                dp[i][j] = INT32_MAX;
            }
            else res = max(res, j);
        }
    }
    cout<< res;
    return 0;
}