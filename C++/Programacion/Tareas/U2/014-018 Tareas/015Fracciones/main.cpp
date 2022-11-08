#include "fraccion.h"

int main() {
    fraccion fracA(16, 4), fracB(0, 0), fracC(120, 40);
    fracA.Mostrar();
    fracA.Simplificar();
    fracA.Mostrar();
    fracB.Mostrar();
    fracA.Sumar(fracC);
    fracA.Mostrar();
};