#include <bits/stdc++.h>

using namespace std;

class Solution{
    static const int MAXN = 2e5;
    static const int INF = 1 << 30;
    static const int K = 31;
    struct stvalue{
        long long a, b;
        bool operator < (const stvalue &x) const{
            return x.a * (b + 1) < a * (x.b + 1);
        }
    };
    stvalue A[MAXN + 1];
    int Z[MAXN + 1];
    long long dp[K + 1];
public:
    pair<int, int> mangaMarket(int N, int T, vector<pair<int, int>> &Store){
        int n1 = 0, n2 = 0;
        for(int i=0; i<N; i++){
            auto [a, b] = Store[i];
            if(a == 0){
                Z[n2++] = b;
            }
            else A[++n1] = {a, b};
        }
        sort(A + 1, A + n1 + 1);
        sort(Z, Z + n2);

        for(int k = 1; k <= K; k++){
            dp[k] = INF;
        }
        for(int i = 1; i <= n1; i++){
            for(int k = K - 1; k >= 0; k--){
                dp[k + 1] = min(dp[k + 1], (A[i].a + 1) * (dp[k] + 1) + A[i].b);
            }
        }
        
        pair<int, int> res = {0, 0};
        for(int k=0; k<=K; k++){
            if(dp[k] > T) continue;
            long long currT = dp[k];
            int currRes = k;
            for(int i=0; i<n2; i++){
                if(currT + Z[i] + 1 > T) break;
                currT += Z[i] + 1;
                currRes++;
            }
            res = max(res, {currRes, -currT});
        }
        res.second = -res.second;
        return res;
    }
};
Solution fullScore;

int main(){
    ifstream input;
    ofstream output;
    int number_of_cases[5] = {0, 11, 27, 18, 55};
    pair<int, int> atCoder[5] = {{0, 0}, {1, 1}, {1, 3}, {1, 2}, {1, 18}};

    for(int subtask = 1; subtask <= 4; subtask++){
        for(int case_number = 1; case_number <= number_of_cases[subtask]; case_number++){
            string casename = "sub" + to_string(subtask) + "." + to_string(case_number);
            input.open("old-cases/" + casename + ".in");
            output.open("new-cases/" + casename + ".in");

            int N, T;
            input>> N>> T;
            vector<pair<int, int>> A(N);
            for(int i=0; i<N; i++){
                int a, b; input>> a>> b;
                A[i] = {a, b};
            }

            auto res = fullScore.mangaMarket(N, T, A);
            int nT = res.second;

            output<< N<< ' ';
            if(atCoder[subtask].first <= case_number && case_number <= atCoder[subtask].second){
                output<< T;
            }
            else if(case_number == number_of_cases[subtask]){
                output<< T;
            }
            else if(case_number & 1){
                output<< T;
            }
            else{
                output<< nT;
            }
            output<< '\n';

            for(auto [a, b] : A){
                output<< a<< ' '<< b<< '\n';
            }

            input.close();
            output.close();
        }
    }

    ofstream testplan;
    testplan.open("testplan");
    int addCases[5] = {0, 0, 1, 1, 1};
    for(int subtask = 1; subtask <= 4; subtask++){
        for(int case_number = 1; case_number<=number_of_cases[subtask] + addCases[subtask]; case_number++){
            string casename = "sub" + to_string(subtask) + "." + to_string(case_number);
            testplan<< casename<< " 0\n";
        }
    }
    testplan.close();
    return 0;
}