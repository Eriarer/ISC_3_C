#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int invertir(int, int);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int n=0, res=0;
    cout << "Dame un numero: ";
    cin >> n;
    cout << "El inverso del numero es: " << invertir(n,res) << endl;

    return 0;
}

int invertir(int n, int res){
    if(n==0)
        return res;
    else {
        return invertir(n/10,res*10+n%10);
    }
}