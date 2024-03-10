#include <bits/stdc++.h>
#include "game.h"
using namespace std;

const int Max_n = 250;
const int Max_queries = 30;

int Values[Max_n], Diff[Max_n * Max_n];
int NumberOfValues, QueryCounter = 0; 

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
    recibeRespuesta((SubsetSize * (SubsetSize - 1))/2, Diff);
}

int valor(int _) {
    QueryCounter++;
    if (_ < 0 || NumberOfValues <= _) {
        cerr << "El indice utilizado es invalido." << endl;
        cout << "0\n";
        exit(0);
    }
    if (QueryCounter > Max_queries) {
        cerr << "Has hecho mas preguntas de las que tenías permitido." << endl;
        cout << "0\n";
        exit(0);
    }
    return Values[_];
}

void respuesta(int _, int AnwserArray[]) {
    if (_ != NumberOfValues) {
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
    cout << "1\n";
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
