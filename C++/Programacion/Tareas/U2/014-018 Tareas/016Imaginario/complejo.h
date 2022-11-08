#include <cmath>
#include <iostream>

using namespace std;

class CComplejo {
    double r, i;

   public:
    //============CONSTRUCTORES============//
    CComplejo() {
        r = 0;
        i = 0;
    }
    CComplejo(double r, double i) {
        this->r = r;
        this->i = i;
    };
    CComplejo(const CComplejo& obj) {
        r = obj.r;
        i = obj.i;
    };
    //============GETS-SETS============//
    //--------GET--------//
    inline double getI() { return i; };
    inline double getR() { return r; };
    //--------SET--------//
    inline void setI(double i) { this->i = i; };
    inline void setR(double r) { this->r = r; };
    //============FUNCIONES============//
    double moduo() { return (sqrt(pow(i, 2) + pow(r, 2))); };
    double argumento() {
        if (r == 0)
            return (i > 0 ? 90 : -90);
        else {
            if (r > 0)  // real positivo
                return (i > 0 ? atan(i / r) : atan(i / r));
            else  // real negativo
                return (i > 0 ? atan(i / r) : atan(i / r));
        }
    };
    void suma(const CComplejo& a, const CComplejo& b) {
        r = a.r + b.r;
        i = a.i + b.i;
    };
    void resta(const CComplejo& a, const CComplejo& b) {
        r = a.r - b.r;
        i = a.i - b.i;
    };
    void imprimir() {
        cout << "( " << r << (i > 0 ? " +" : " ") << i << ")" << endl;
    }
};