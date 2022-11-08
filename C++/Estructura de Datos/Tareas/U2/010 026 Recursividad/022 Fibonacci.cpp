#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int fib(int n){
    int aux;
    if(n >= 2)
        aux = fib(n-1) + fib(n-2);
    else 
        aux = n;
    return aux;
}

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int n;
    cout << endl << "Dame un numero: ";
    cin >> n;
    cout << endl << "El fibonacci de " << n << " es: " << fib(n) << endl;

    return 0;
}