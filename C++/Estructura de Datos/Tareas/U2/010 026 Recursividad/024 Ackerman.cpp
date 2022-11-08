#include<iostream>

using namespace std;
int ack(int m, int n){
    int aux;
    if(m==0)
        aux = n+1;
    else if(n==0)
            aux = ack(m-1,1);
         else
            aux = ack(m-1, ack(m,n-1));
    return aux;
};  

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    cout << endl << "El resultado de [1,2] es: " << ack(1,2) << endl
         << "El resultado de [2,5] es: " << ack(2,5) << endl;

    return 0;
}