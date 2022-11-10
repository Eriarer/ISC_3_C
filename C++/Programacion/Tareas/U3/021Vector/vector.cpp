#include "vector.h"

int main() {
    CVector VecA(10), VecB(10), VecC(10), VecT(0);
    VecA.carga(5, 0);
    VecB.carga(10, 0);
    VecC.carga(15, 0);
    VecT = VecA + VecB;
    cout << "\tVECTOR A\n"
         << VecA << endl
         << "\tVECTOR B\n"
         << VecB << endl
         << "\tVECTOR C\n"
         << VecC << endl
         << "\tSUMA A + B\n"
         << VecT << endl;
};