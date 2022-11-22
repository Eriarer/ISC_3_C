#include <iostream>

#include "CPersona.h"
//
#include "CEstudiante.h"
//
#include "Empleado.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    CPersona juan("Juan Perez", 19);
    CEstudiante estudia("UAA", 8.9, juan);
    Empleado trabaja(10525.32, juan);
    cout << endl
         << "La persona: " << endl;
    juan.mostrar();
    cout << endl
         << "Es estudiante de: " << endl;
    estudia.mostrar();
    cout << endl
         << endl;
    cout << endl
         << "Y tiene un salario de: " << endl
         << endl;
    trabaja.mostrar();
    return 0;
}
