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

vector<int> random_distinct_values(int N, long long L, long long R){
    vector<int> A(N);
    set<int> values;
    for(int i = 0; i < N; i++){
        A[i] = get_random(L, R);
        while(values.count(A[i])){
            A[i] = get_random(L, R);
        }
        values.insert(A[i]);
    }
    return A;
}

int main(){
    ///*
    ofstream input;
    ofstream output;

    for(int subtask = 1; subtask <= 4; subtask++){
        int n_limitL, n_limitR, num_of_cases;
        int start_point;
        if(subtask == 1){
            n_limitL = 1;
            n_limitR = 30;
            num_of_cases = 10;
            start_point = 1;
        }
        else if(subtask == 2){
            n_limitL = 1;
            n_limitR = 250;
            num_of_cases = 10;
            start_point = 1;
        }
        else if(subtask == 3){
            n_limitL = 1;
            n_limitR = 250;
            num_of_cases = 10;
            start_point = 1;
        }
        else if(subtask == 4){
            n_limitL = 1;
            n_limitR = 250;
            num_of_cases = 15;
            start_point = 1;
        }
        for(int case_n = 0; case_n < num_of_cases; case_n++){
            int N = get_random(n_limitL, n_limitR);
            if(case_n > num_of_cases/2){
                N = n_limitR;
            }
            vector<int> A;
            if(subtask == 3){
                A = random_distinct_values(N-1, 2, 1e9);
                A.push_back(1);
                swap(A[0], A[N-1]);
            }
            else{
                A = random_distinct_values(N, 1, 1e9);
            }
            if(subtask == 2){
                sort(A.begin(), A.end());
                if(get_random(0, 1)){
                    reverse(A.begin(), A.end());
                }
            }

            int case_number = case_n + start_point;

            std::string casename = "cases/sub" + std::to_string(subtask) + "." +
                             std::to_string(case_number);
            input.open(casename + ".in");

            input<< N<< '\n';
            for(int i=0; i<N; i++){
                input<< A[i]<< " \n"[i == N-1];
            }

            input.close();

            output.open(casename + ".out");
            output<< "1\n";
            output.close();
        }
    }
    //*/

    /*
    ofstream testplan;
    testplan.open("testplan");
    int number_of_cases[5] = {0, 10, 10, 10, 15};
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