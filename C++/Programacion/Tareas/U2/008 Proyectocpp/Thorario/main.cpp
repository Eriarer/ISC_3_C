#include "THorario.h"

using namespace std;

int main(){
    THorario ahora(8,12,15);
    ahora.militar();
    ahora.standar();    

    // modificcando mediante set
    ahora.sethh(17);
    ahora.setmm(15);
    ahora.setss(5);

    // consulta mediante get
    cout<< "La hora es: "
        << ahora.gethh() << ":"
        << ahora.getmm() << ":"
        << ahora.getss() << endl;
}