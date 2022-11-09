#include "vector.h"

int main() {
    CVector VecA(10), VecB(10), VecC(10);
    VecA.captura();
    VecB.captura();

    cout << "VecA: ";
    VecA.mostrar();
    cout << "VecB: ";
    VecB.mostrar();

    cout << "VecA + VecB: ";
    VecC.sumar(VecA, VecB);
    VecC.mostrar();

    cout << "VecC ordenado:";
    VecC.ordenar();
    VecC.mostrar();

    CVector VecD(VecC);
    cout << "Copia del vector C: ";
    VecD.mostrar();
    VecA + 2;
    VecA.mostrar();
    return 0;
};