#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int main(){
    float res=0, sum=0, numrest=0;
    int i=0, lim=0, opc=0;
    cout << "Quieres restar a un numero el resultardo Y-1  N-2" << endl;
    cin >> opc; fflush(stdin);
    if(opc==1){
        cout << "Dame el valor de inicio de i" << endl;
        cin >> i; fflush(stdin);
        cout << "Numero a restar resultado" << endl;
        cin >> numrest; fflush(stdin);
        cout << "Limite de suma" << endl;
        cin >> lim; fflush(stdin);
        cout << "Cantidad a sumar" << endl;
        cin >> sum; fflush(stdin);
        for(i;i<=lim;i++) 
            res = res + sum;
        numrest = numrest - res;
        cout << "El resultado es: " << numrest << endl;
    }else{
        cout << "Dame el valor de inicio de i" << endl;
        cin >> i; fflush(stdin);
        cout << "Limite de suma" << endl;
        cin >> lim; fflush(stdin);
        cout << "Cantidad a sumar" << endl;
        cin >> sum; fflush(stdin);
        for(i;i<=lim;i++) 
            res = res + sum;
        cout << "El resultado es: " << res << endl;
        
    }
    cout << i;
    return 0;
}