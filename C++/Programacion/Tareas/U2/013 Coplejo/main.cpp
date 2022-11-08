#include "complejo.h"

int main(){
    Complejo x(2,5), y, z;
    cout << "complejo x:";
    x.mostrar();
    cout << endl << "VALORES DE y " << endl;
    y.captura();
    y.mostrar();
    z = suma(x,y);
    cout << endl << "Resultado de suma en z:" << endl;
    z.mostrar();
    return 0;
};