#include <bits/stdc++.h>
#include "game.h"
using namespace std;

const int Max_n = 250;
const int Max_queries = 60;

int Values[Max_n], Diff[Max_n * Max_n];
int NumberOfValues, QueryCounter = 0; 

mt19937 randomSeed(chrono::steady_clock::now().time_since_epoch().count());

void diferencias(int SubsetSize, int Subset[]) {
    QueryCounter++;
    if (QueryCounter > Max_queries) {
        cerr << "Has hecho mas preguntas de las que tenías permitido." << endl;
        cout << "0\n";
        exit(0);
    }
    int currentIndex = 0;
    for (int i = 0; i < SubsetSize; i++) {
        for (int j = i + 1; j < SubsetSize; j++) {
            Diff[currentIndex++] = abs(Values[Subset[i]] - Values[Subset[j]]);
        }
    }
    shuffle(Diff, Diff + currentIndex, randomSeed);
    recibeRespuesta((SubsetSize * (SubsetSize - 1))/2, Diff);
}

int valor(int Index) {
    QueryCounter++;
    if (Index < 0 || NumberOfValues <= Index) {
        cerr << "El indice utilizado es invalido." << endl;
        cout << "0\n";
        exit(0);
    }
    if (QueryCounter > Max_queries) {
        cerr << "Has hecho mas preguntas de las que tenías permitido." << endl;
        cout << "0\n";
        exit(0);
    }
    return Values[Index];
}

void respuesta(int AnwserSize, int AnwserArray[]) {
    if (AnwserSize != NumberOfValues) {
        cerr << "El tamaño del arreglo es distinto a N." << endl;
        cout << "0\n";
        exit(0);
    }
    for (int i = 0; i < NumberOfValues; i++) {
        if (AnwserArray[i] != Values[i]) {
            cerr << "El arreglo en la respuesta es incorrecto." << endl;
            cout << "0\n";
            exit(0);
        }
    }
    if(QueryCounter <= 30){
        cout << "1\n";
    }
    else{
        cout<< 1.0 - ((double)(QueryCounter - 30) / (double)(60 - 30))<< '\n';
    }
    exit(0);
}

int main(){
    cin >> NumberOfValues;
    for (int i = 0; i < NumberOfValues; i++) {
        cin >> Values[i];
    }
    EncontrarArreglo(NumberOfValues);
    cerr<< "No llamaste a la funcion respuesta"<< endl;
    cout<< "0\n";
}
