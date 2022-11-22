#include <cmath>
#include <iostream>
using namespace std;

class Circulo {
   protected:
    double radio;

   public:
    Circulo(double = 1.0);  // constructor
    double area();
};
// seccion de implementacion de la clase
// constructor
Circulo::Circulo(double r) {
    radio = r;
}
// calcula el �rea de un c�rculo
double Circulo::area() {
    return (3.1415 * radio * radio);
}
