#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int octal(int n, int i);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int k=0;
    cout << "En octal 114 es: " << octal(114,0) << endl;
    cout << "En octal 2357 es: " << octal(2357,0) << endl;  
    return 0;
}

int octal(int n, int i){
    int coc, residuo, res;
    coc = n/8;
    residuo = n%8;
    if(coc!=0)
        res = residuo*pow(10,i)+octal(coc,i+1);
    else
        res = residuo*pow(10,i);
    return res;
}