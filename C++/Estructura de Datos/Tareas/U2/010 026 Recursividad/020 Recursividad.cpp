#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

bool pos(int);
bool neg(int);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int n=4;
    pos(n)==true ? cout << endl << n << " Es positivo" << endl : cout << endl << n << " No es positivo" << endl;
    n=-4;
    pos(n)==true ? cout << endl << n << " Es positivo" << endl : cout << endl << n << " No es positivo" << endl;
    n=6;
    neg(n)==true ? cout << endl << n << " Es positivo" << endl : cout << endl << n << " No es positivo" << endl;
    n=-6;
    neg(n)==true ? cout << endl << n << " Es positivo" << endl : cout << endl << n << " No es positivo" << endl;

    return 0;
}

bool pos(int n){
    if(n>0)
        return true;
    else
        return neg(n);
}

bool neg(int n){
    if(n<0)
        return false;
    else
        return pos(n);
}
