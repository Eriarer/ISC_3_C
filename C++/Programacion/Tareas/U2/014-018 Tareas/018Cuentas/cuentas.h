#include "DFecha.h"

class Persona {
    char nombre[80];
    int edad;
    float estatura;
    float peso;
    CDate fnacimiento;

   public:
    Persona(const std::string& nombre, int edad, float peso, float estatura);
    void saluda();
    void cumpleAnios();
};

class CCuenta {
    Persona cliente;
    double saldo, interes;

   public:
    CCuenta(double saldo_inicial, double inter);
    void ingresar(double i);
    void retirar(double r);
};