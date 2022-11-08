#include<iostream>
#include<iomanip>
#include<conio.h>
#define TAM 8

int sumav(int[], int);

using namespace std;

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int sum;
    int v[TAM] = {2,4,6,8,10,12,14,16};

    sum = sumav(v, TAM-1);
    cout << endl << "La sumatoria de los elemendos del vector es: " << sum;

    return 0;
}

int sumav(int v[], int i){
    int total;
    if(i>0)
        total = v[i] + sumav(v, i-1);
    else
        total = v[0];
    return total;
}