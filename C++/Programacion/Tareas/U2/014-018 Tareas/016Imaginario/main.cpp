#include "complejo.h"

int main() {
    CComplejo a(-1, 1), b(1, 2), c;
    cout << "A" << endl;
    a.imprimir();
    cout << "modulo a " << a.moduo() << endl
         << "argumento a " << a.argumento() << endl;
    cout << "B" << endl;
    b.imprimir();
    cout << " A + B" << endl;
    c.suma(a, b);
    c.imprimir();
    cout << " A - B" << endl;
    c.resta(a, b);
    c.imprimir();
    return 0;
};