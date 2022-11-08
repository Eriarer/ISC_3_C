#include <conio.h>

#include "reloj.h"

int main() {
    CReloj a(15, 23, 50, 20), b(-12, 59, 59, 1), c(a);
    a.escribe_en_12h();
    cout << endl;
    a.escribe_en_24h();
    cout << endl;
    _getch();  // Pausa (needs conio.h)
    while (a.getBat() != 0) {
        a.tic_tac();
    }
    a.tic_tac();
    a.escribe_en_12h();
    b.escribe_en_12h();
    _getch();  // Pausa (needs conio.h)
    while (b.getBat() > 0) {
        b.tic_tac();
    }
    b.escribe_en_12h();
    _getch();  // Pausa (needs conio.h)
    b.recarga_bateria(60);
    while (b.getBat() != 0) {
        b.tic_tac();
    }
    b.escribe_en_12h();
    c.escribe_en_12h();
    c.sincronizar(b);
    c.escribe_en_12h();
    b.escribe_en_12h();
};