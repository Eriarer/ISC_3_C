#include "vector.h"

int main() {
    CVector VecA(10), VecB(15), VecC(5);
    VecA.carga(5, 0);
    VecC.carga();
    cout << "\tVECTOR A\n"
         << VecA << endl
         << "\tVECTOR C\n"
         << VecC << endl
         << "\tVECTOR C\n"
         << VecC << endl;
};