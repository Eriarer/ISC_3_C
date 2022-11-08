#include<iostream>
#include<iomanip>
#include<conio.h>

int factorial (int);
using namespace std;

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int n, fac;

    cout << endl << "El factorial de que numero: ";
    cin >> n;
    fac = factorial(n);
    cout << endl << "El factorial es: " << fac;

    return 0;
}

int factorial(int n){
    int f;
    if(n>1)
        f = n * factorial(n-1);
    else
        f = 1;
    return f;
}