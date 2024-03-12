#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

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

    int N, M;
    if(!(fin>> N>> M)){
        fin.close();
        print_error(casename, "There's no 2 integers in the first line");
    }

    //cout<< "*";

    if(N < 1 || N > 1e5){
        fin.close();
        print_error(casename, "N is out of bounds");
    }
    if(M < N-1 || M > 2e5){
        fin.close();
        print_error(casename, "M is out of bounds");
    }

    //cout<< "*";

    adj.resize(N + 1);
    set<pair<int, int>> setOfEdges;
    for(int i=0; i<M; i++){
        int u, v, w;
        if(!(fin>> u>> v>> w)){
            fin.close();
            print_error(casename, "There aren't M edges with cost");
        }
        if(u < 1 || u > N || v < 1 || v > N){
            fin.close();
            print_error(casename, "One edge is out of bounds");
        }
        if(u == v){
            fin.close();
            print_error(casename, "There's a self-edge");
        }
        if(w < 1 || w > 1e9){
            fin.close();
            print_error(casename, "The cost of an edge is out of bounds");
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        setOfEdges.insert({min(u, v), max(u, v)});
    }

    //cout<< "*";

    if(setOfEdges.size() != M){
        fin.close();
        print_error(casename, "There aren't exactly M distinct edges");
    }

    //cout<< "*";

    int Q;
    if(!(fin>> Q)){
        fin.close();
        print_error(casename, "Q doesn't exist");
    }

    //cout<< "*";

    if(Q < 1 || Q > 1e5){
        fin.close();
        print_error(casename, "Q is out of bounds");
    }

    //cout<< "*";

    for(int i=0; i<Q; i++){
        int u, v;
        if(!(fin>> u>> v)){
            fin.close();
            print_error(casename, "There aren't Q queries");
        }
        if(u < 1 || u > N || v < 1 || v > N){
            fin.close();
            print_error(casename, "One query is out of bounds");
        }
        if(u == v){
            fin.close();
            print_error(casename, "There's a query where u == v");
        }
    }

    //cout<< "*";

    char character;
    if((fin >> character)){
        fin.close();
        print_error(casename, "Printed more data");
    }

    //cout<< "*";

    fin.close();

    string subtask = casename.substr(0, 4);
    if(subtask == "sub1"){
        if(Q != 1){
            print_error(casename, "In subtask 1, Q != 1");
        }
    }
    if(subtask == "sub2"){
        if(N > 4000){
            print_error(casename, "In subtask 2, N is out of bounds");
        }
        if(Q > 4000){
            print_error(casename, "In subtask 2, Q is out of bounds");
        }
    }

    //cout<< "*";


    vector<bool> vis(N + 1);
    int cnt = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        for(auto u : adj[v]){
            if(vis[u]) continue;
            q.push(u);
            vis[u] = 1;
        }
    }
    if(cnt != N){
        print_error(casename, "The graph is not connected");
    }
    return 0;
}