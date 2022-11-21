#include "CPersona.h"
// libreria hredada
#include "CEstudiante.h"
#include "CTrabajador.h" /

int main() {
    CPersona yo("Eriarer", 20);
    CTrabajador yoT("Twitch", 500, yo);
    CEstudiante yoE("UAA", 8.7, yo);
    cout << yo << endl;
    yoE.mostrar();
    cout << endl;
    yoT.mostrar();
    cout << endl
         << yo << endl
         << yoT;
    return 0;
};