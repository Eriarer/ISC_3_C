#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>

using namespace std;

string cambia(int n);
int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    cout << cambia(36);
    return 0;
}

string cambia(int n){
    string dig, bin;
    int res=n%2, coc=n/2;
    if(res==0)
        dig = "0";
    else
        dig = "1";
    if(coc==0)
        bin=dig;
    else
        bin = cambia(coc)+dig;
    return bin;
}