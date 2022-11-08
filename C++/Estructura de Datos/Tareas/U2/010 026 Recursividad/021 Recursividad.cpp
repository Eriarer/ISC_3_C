#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int par(int n);
int impar(int n);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int n=4;
    par(n)==1 ? cout << endl << n << " es par" << endl : cout << endl << n << " es impar" << endl;
    n=3;
    par(n)==1 ? cout << endl << n << " es par" << endl : cout << endl << n << " es impar" << endl;
    n=2;
    impar(n)==1 ? cout << endl << n << " es impar" << endl : cout << endl << n << " es par" << endl;
    n=5;
    impar(n)==1 ? cout << endl << n << " es impar" << endl : cout << endl << n << " es par" << endl;
    return 0;
}

int par(int n){
    if(n==0)
        return n+1;
    return impar(n-1);
}
int impar(int n){
    if(n==0)
        return 0;
    return par(n-1);
}