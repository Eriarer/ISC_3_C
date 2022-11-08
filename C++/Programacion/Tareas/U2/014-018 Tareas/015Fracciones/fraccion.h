#include <iostream>
using namespace std;

class fraccion {
    int numerador, denominador;
    int MCD(int, int);

   public:
    //============CONSTRUCTORES============//
    fraccion() {
        numerador = 0;
        denominador = 1;
    };
    fraccion(int n, int d) {
        numerador = n;
        denominador = d;
    };
    fraccion(const fraccion& obj) {
        numerador = obj.numerador;
        denominador = obj.denominador;
    };
    //============GETS-SETS============//
    //--------GET--------//
    inline int getNum() { return numerador; };
    inline int getDen() { return denominador; };
    //--------SET--------//
    inline void setNum(int n) { numerador = n; };
    void setDen(int n) {
        if (n == 0) {
            cout << "Denominador ivalido inserte otro" << endl;
            return;
        }
        denominador = n;
    };
    //============FUNCIONES============//
    void Simplificar();
    void Sumar(fraccion& obj);
    void Mostrar();
};
//============FUNCIONES============//
//--------PRIV--------//
int fraccion::MCD(int a, int b) {
    if (a > b)
        return (MCD(a - b, b));
    else if (b > a)
        return (MCD(b - a, a));
    else if (a == b)
        return a;
};
//--------PUB---------//
void fraccion::Simplificar() {
    if (denominador == 0) {
        cout << endl
             << "Indeterminacion division entre 0";
        return;
    }
    int mcd = MCD(numerador, denominador);
    if (mcd == 0)
        return;
    numerador = numerador / mcd;
    denominador = denominador / mcd;
};
void fraccion::Sumar(fraccion& obj) {
    if (denominador == 0 || obj.denominador == 0) {
        cout << endl
             << "Indeterminacion division entre 0";
        return;
    }
    if (denominador == obj.denominador) {
        numerador += obj.numerador;
        return;
    }
    numerador = numerador * obj.denominador + obj.numerador * denominador;
    denominador = denominador * obj.denominador;
    Simplificar();
};
void fraccion::Mostrar() {
    if (denominador == 0) {
        cout << endl
             << "Indeterminacion division entre 0";
        return;
    }
    if (numerador == 0 || denominador == 1) {
        cout << endl
             << numerador;
        return;
    }
    cout << endl
         << numerador << "/" << denominador;
};