#include <bits/stdc++.h>

using namespace std;

// Random generator
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    long long x = (rnd() % (r - l + 1));
    return x + l;
}

vector<int> random_values(int N, long long L, long long R){
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        A[i] = get_random(L, R);
    }
    return A;
}

vector<int> in_ten_values(int N, int L, int R){
    vector<int> A;
    long long prev = 1;
    for(int it = 1; it < L; it++){
        prev *= 10;
    }
    long long curr = prev*10;
    int len = R - L + 1;
    for(int it = L; it <= R; it++){
        auto B = random_values(N/len, prev, curr);
        for(auto x : B){
            A.push_back(x);
        }
        if(it < R){
            prev *= 10;
            curr *= 10;
        }
    }
    while(A.size() < N){
        A.push_back(get_random(1, curr));
    }
    shuffle(A.begin(), A.end(), rnd);
    return A;
}

int main(){
    /*
    ofstream input;

    for(int subtask = 2; subtask <= 3; subtask++){
        int n_limitL, n_limitR, t_limitL, t_limitR, num_of_cases;
        int start_point;
        if(subtask == 1){
            n_limitL = 1;
            n_limitR = 2e5;
            t_limitL = 0;
            t_limitR = 1e9;
            num_of_cases = 10;
            start_point = 2;
        }
        else if(subtask == 2){
            n_limitL = 1;
            n_limitR = 2000;
            t_limitL = 0;
            t_limitR = 2000;
            num_of_cases = 10;
            start_point = 18;
        }
        else if(subtask == 3){
            n_limitL = 1;
            n_limitR = 2000;
            t_limitL = 0;
            t_limitR = 1e9;
            num_of_cases = 10;
            start_point = 9;
        }
        vector<int> N = random_values(num_of_cases, n_limitL, n_limitR);
        if(num_of_cases >= 1){
            N[num_of_cases - 1] = n_limitR;
        }
        for(int case_n = 0; case_n < num_of_cases; case_n++){
            int T = get_random(t_limitL, t_limitR);
            if(case_n == num_of_cases - 1){
                T = t_limitR;
            }
            vector<int> A, B;
            if(subtask == 1){
                A.resize(N[case_n]);
                if(case_n == 0){
                    fill(A.begin(), A.end(), 0);
                }
                else if(case_n == 1){
                    fill(A.begin(), A.end(), 1);
                }
                else if(case_n < 5){
                    fill(A.begin(), A.end(), get_random(2, 10));
                }
                else if(case_n < 8){
                    fill(A.begin(), A.end(), get_random(11, 100));
                }
                else if(case_n < 10){
                    fill(A.begin(), A.end(), get_random(100, 1e9));
                }
            }
            else{
                A = in_ten_values(N[case_n], 1, 9);
                auto C = random_values(get_random(1, N[case_n]), 0, N[case_n]-1);
                for(auto x : C){
                    A[x] = 0;
                }
            }

            if(subtask == 1){
                for(long long it=1, prev = 1, curr = 10; it<9; it++){
                    auto C = random_values(N[case_n]/7, prev, curr);
                    for(auto x : C){
                        B.push_back(x);
                    }
                    prev *= 10;
                    curr *= 10;
                }
                while(B.size() < N[case_n]){
                    B.push_back(get_random(0, 1e9));
                }
                shuffle(B.begin(), B.end(), rnd);
            }
            else{
                B = in_ten_values(N[case_n], 1, 9);
            }

            int case_number = case_n + start_point;

            std::string casename = "cases/sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
            input.open(casename + ".in");

            input<< N[case_n]<< ' '<< T<< '\n';
            for(int i = 0; i < N[case_n]; i++){
                input<< A[i]<< ' '<< B[i]<< '\n';
            }

            input.close();
        }
    }
    */

    ///*
    ofstream testplan;
    testplan.open("testplan");
    int number_of_cases[5] = {0, 11, 27, 18, 55};
    for(int subtask = 1; subtask <= 4; subtask++){
        for(int case_number = 1; case_number<=number_of_cases[subtask]; case_number++){
            string casename = "sub" + to_string(subtask) + "." + to_string(case_number);
            testplan<< casename<< " 0\n";
        }
    }
    testplan.close();
    //*/
    return 0;
}