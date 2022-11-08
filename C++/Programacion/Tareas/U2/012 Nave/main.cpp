#include "nave.h"

int main(){
    Nave a;
    Nave *b = new Nave;
    cout << " Numero de naves " << a.cuenta() << endl;
    delete b;
    cout << " Numero de naves " << Nave::cuenta() << endl;
    a.~Nave();
    cout << " Numero de naves " << Nave::cuenta() << endl;
    return 0;
}