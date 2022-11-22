#include <iostream>

#include "Reloj.h"
//
#include "Radio.h"
//
#include "RadioReloj.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    RadioReloj casio;
    int h, m, s, ah, am, as;

    cout << "Ingrese la hora acual : ";
    cin >> h >> m >> s;

    casio.DefineTiempo(h, m, s);

    cout << "Ingrese la hora de Aviso : ";
    cin >> ah >> am >> as;

    casio.ProgramarAlarma(ah, am, true);
    casio.CambiaFrecuencia(95.5);

    while (1) {
        casio.IncTiempo();
        if (casio.VerificaAlarma()) {
            casio.SuenaAlarma();
            break;
        }
    }
}
