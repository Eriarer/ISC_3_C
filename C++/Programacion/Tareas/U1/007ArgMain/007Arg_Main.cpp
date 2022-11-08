#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int main(int arg, char *argv[]){
    if(arg < 2){
        cout << "NO HAY SUFICIENTES VARIABLES" << endl;
    }else{
        int i;
        float val;
        cout << "Se ha pasado un total de " << arg-1 << " arguentos" << endl;
        for(i=1;i<arg;i++){
            cout << "Argumento no " << i << "es el valor: " << argv[i] << endl;
        }
        val = atof(argv[1]);
        cout << "Flotante es: " << setprecision(5) << val << " listo" << endl;
    }
    return 0;
}