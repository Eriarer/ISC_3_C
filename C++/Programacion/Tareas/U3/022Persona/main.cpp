#include "CEstudiante.h"

int main() {
    CPersona yo("Eriarer", 20);
    CEstudiante yoE("UAA", 8.7, yo);
    yoE.mostrar();
    cout << endl;
    return 0;
};
/*
#include "CTrabajador"

int main() {
    CPersona yo("Eriarer", 20);
    CTrabajador yoT("Twitch", 500, yo);
    yoE.mostrar();
    cout << endl;
    return 0;
};
*/