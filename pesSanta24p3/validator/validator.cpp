#include<bits/stdc++.h>

using namespace std;

void print_error(string casename, string text){
    ofstream fout;
    fout.open("invalid-cases.txt", ios::app);
    fout<< casename<< " -> "<< text<< '\n';
    fout.close();
    exit(0);
}

int main(int argc, char* argv[]){
    string filename = argv[1];
    ifstream fin;
    fin.open(filename);

    string casename = filename.substr(6);

    int N;
    if(!(fin>> N)){
        fin.close();
        print_error(casename, "There's no integer in the first line");
    }

    vector<int> A(N);
    for(int i=0; i<N; i++){
        if(!(fin>> A[i])){
            fin.close();
            print_error(casename, "There's less than N integers");
        }
    }

    char character;
    if((fin >> character)){
        fin.close();
        print_error(casename, "Printed more data");
    }

    fin.close();

    set<int> A_values;
    for(int i = 0; i < N; i++){
        A_values.insert(A[i]);
    }
    if(A_values.size() != N){
        print_error(casename, "The elements of A are not distinct");
    }

    string subtask = casename.substr(0, 4);
    if(subtask == "sub1"){
        if(N > 30){
            print_error(casename, "In subtask 1, N > 30");
        }
    }
    if(subtask == "sub2"){
        bool inOrDec = false;

        vector<int> sortedA = A;
        sort(sortedA.begin(), sortedA.end());
        if(sortedA == A) inOrDec = true;
        reverse(sortedA.begin(), sortedA.end());
        if(sortedA == A) inOrDec = true;

        if(!inOrDec){
            print_error(casename, "In subtask 2, The numbers are not in order");
        }
    }
    if(subtask == "sub3"){
        if(A[0] != 1){
            print_error(casename, "In subtask 3, The first element is not 1");
        }
    }

    return 0;
}