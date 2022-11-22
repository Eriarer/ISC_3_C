#include <iostream>

#include "Circulo.h"
//
#include "Cilindro.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    Circulo circulo_1, circulo_2(2);  // crea dos objetos Circulo
    Cilindro cilindro_1(3, 4);        // crea un objeto Cilindro
    cout << "El area del circulo_1 es " << circulo_1.area() << endl;
    cout << "El area del circulo_2 es " << circulo_2.area() << endl;
    cout << "El volumen del cilindro_1 es " << cilindro_1.area() << endl;
    circulo_1 = cilindro_1;  // asigna un cilindro a un Circulo
    cout << "\nEl area del circulo_1 ahora es " << circulo_1.area() << endl;
    return 0;
}
