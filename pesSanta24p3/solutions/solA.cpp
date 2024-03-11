#include <bits/stdc++.h>
#include "game.h"

using namespace std;

const int MAXN = 250;
int D_Ans[MAXN * MAXN + 1]; //diferences
int dummy[MAXN + 1];//for function

int A[MAXN + 1];//answer

void recibeRespuesta(int N, int D_Res[]){
	for(int i=0; i<N; i++){
		D_Ans[i] = D_Res[i];
	}
}
vector<int> F(vector<int> &S, int index){
	map<int, int> freq;
	int N = S.size();;
	for(int i=0; i<N; i++){
		dummy[i] = S[i];
	}
	dummy[N] = index;
	diferencias(N + 1, dummy);
	for(int i=0; i<(N * (N + 1))/2; i++){
		freq[D_Ans[i]]++;
	}
	diferencias(N, dummy);
	for(int i=0; i<(N * (N - 1))/2; i++){
		freq[D_Ans[i]]--;
	}
	vector<int> dx;
	for(auto [x, c] : freq) if(c){
		dx.push_back(x);
	}
	return dx;
}

int max_d(int N){
	diferencias(N, dummy);
	return *max_element(D_Ans, D_Ans + (N * (N - 1))/2);	
}

const int LOGN = 7;
set<int> binaryTree[LOGN + 1];

void EncontrarArreglo(int N){
	int logN = 0;
	while((1 << (logN + 1)) <= N) logN++;

	iota(dummy, dummy + N, 0);
	int maxDiff = max_d(N);
	int index1 = 0;
	for(int x = logN; x >= 0; x--){
		if(index1 + (1 << x) >= N) continue;
		if(max_d(index1 + (1 << x)) != maxDiff){
			index1 += (1 << x);
		}
	}

	set<int> D;
	for(int x = 0; x <= logN; x++){
		vector<int> S;
		for(int i = 0; i < N; i++){
			if(i & (1 << x)){
				S.push_back(i);
			}
		}
		vector<int> dx = F(S, index1);
		for(auto d : dx){
			D.insert(d);
			binaryTree[x].insert(d);
		}
	}
	dummy[0] = 0;
	dummy[1] = index1;
	diferencias(2, dummy);
	D.insert(D_Ans[0]);

	int index2 = -1;
	for(auto d : D){
		int idx = 0;
		for(int x = 0; x <= logN; x++){
			if(binaryTree[x].count(d)){
				idx += (1 << x);
			}
		}
		A[idx] = d;
		index2 = idx;
	}
	int x1 = valor(index1);
	int x2 = valor(index2);

	if(x1 < x2){
		for(int i=0; i<N; i++){
			A[i] = x1 + A[i];
		}
	}
	else{
		for(int i=0; i<N; i++){
			A[i] = x1 - A[i];
		}
	}
	respuesta(N, A);
}
