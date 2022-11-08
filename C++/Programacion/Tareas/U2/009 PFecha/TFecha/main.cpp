#include "TFecha.h"

int main(){
    int d=1, m=2, a=2024;
    int res;
    CDate Fecha(d,m,a);
    CDate aux(d,m,a+1);
    cout << "\t<DIA ";
    Fecha.showAll();
    cout << ">" << endl;
    if(Fecha.laborable()){
        cout << "El dia ";
        Fecha.showShort();
        cout << " no es laborable" << endl;
    }
    else{
        cout << "El dia ";
        Fecha.showShort();
        cout << " es laborable" << endl;
    }
    if(Fecha.festivo()){
        cout << "El dia ";
        Fecha.showShort();
        cout << " es festivo" << endl;
    }else{
        cout << "El dia ";
        Fecha.showShort();
        cout << " no es festivo" << endl;
    }
    cout << "El dia siguiente es: ";
    Fecha.dayNext(Fecha); cout << endl;
    Fecha.show(); cout << endl;
    cout << "El dia anterior es: ";
    Fecha.dayBack(Fecha); cout << endl;
    Fecha.show(); cout << endl;
    if(Fecha.leap())
        cout << "El anio es bisiesto" << endl;
    else
        cout << "El anio no es bisiesto" << endl;
    cout << "La diferencia de dias entre ";
    Fecha.showShort();
    cout << " ";
    aux.showShort();
    cout << " es: " << Fecha.dayDif(Fecha, aux) << endl;
    return 0;
}