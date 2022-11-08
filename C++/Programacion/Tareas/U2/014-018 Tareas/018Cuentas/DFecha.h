#include <iostream>
#include <string>

using namespace std;

class CDate {
   private:
    int DFest[5] = {10, 23, 6, 25, 2};
    int MFest[5] = {5, 5, 2, 12, 10};
    int dd, mm, aa;
    string months[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    string Dweek[7] = {"Sabado", "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    //----------FUNCIONES--------
    int ajustarFecha(int, int);
    int zeller(int, int, int);
    void ajuste2(int &, int &, int &);
    int daystrans(CDate &obj);

   public:
    CDate();
    CDate(int, int, int);
    // CDate(int=0,int=0,int=0);
    CDate(CDate &obj);
    //-------------GET-----------
    int getdd();
    int getmm();
    int getaa();
    //-------------SET-----------
    void setdd(int);
    void setmm(int);
    void setaa(int);
    void ajuste(int, int, int);
    void ajuste(CDate &);
    //----------FUNCIONES--------
    void showShort();                      // muestra la fecha en formato corto
    void show();                           // Muestra fecha en formato semi estandar
    void showAll();                        // Muestra fecha en formato completo
    bool laborable();                      // Tomar los 6 dias que marca la ley
    bool festivo();                        // 10 May, 23 May, 6 Feb, 25 Dic, 2 Nov
    void dayNext(CDate obj);               // muestra el dia de maniana
    void dayBack(CDate obj);               // muestra el dia de ayer
    bool leap();                           // muestra si es bisiesto
    int dayDif(CDate &obj1, CDate &obj2);  // Muestra la diferencia ue hay entre dias
};
//------------------CONSTRUCTORES--------------------
CDate::CDate() {
    dd = mm = aa = 0;
};
CDate::CDate(int dd, int mm, int aa) {
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
};
CDate::CDate(CDate &obj) {
    dd = obj.dd;
    mm = obj.mm;
    aa = obj.aa;
};
//------------------GETS--------------------
int CDate::getdd() {
    return dd;
};
int CDate::getmm() {
    return mm;
};
int CDate::getaa() {
    return aa;
};
//------------------SETS--------------------
void CDate::setdd(int dd) {
    this->dd = dd;
};
void CDate::setmm(int mm) {
    this->mm = mm;
};
void CDate::setaa(int aa) {
    this->aa = aa;
};
//------------------FUNCIONES--------------------
void CDate::ajuste(int d, int m, int a) {
    if (a < 0)
        aa = a * -1;
    if (m < 0)
        mm = m * -1;
    if (d < 0)
        dd = d * -1;
    mm = ajustarFecha(m, 12);
    // primero EXCLUIMOS FEBRERO, SEGUNDO ANTES DE AGOSTO todos los meses impares 31 dias || A PARTIR DE AGOSTO todos los meses pares tienen 31 dias || CASO FEBRERO si es bisiesto tiene 29 dias
    dd = (m != 2)        ? (m <= 7) ? (m % 2 != 0) ? ajustarFecha(d, 31) : ajustarFecha(d, 30) : (m % 2 == 0) ? ajustarFecha(d, 31)
                                                                                                              : ajustarFecha(d, 30)
                : (aa % 4 == 0) ? ajustarFecha(d, 29)
                         : ajustarFecha(d, 28);
};
void CDate::ajuste(CDate &obj) {
    if (obj.getaa() < 0)
        aa = obj.getaa() * -1;
    if (obj.getmm() < 0)
        mm = obj.getmm() * -1;
    if (obj.getdd() < 0)
        dd = obj.getdd() * -1;
    mm = ajustarFecha(obj.getmm(), 12);
    // primero EXCLUIMOS FEBRERO, SEGUNDO ANTES DE AGOSTO todos los meses impares 31 dias || A PARTIR DE AGOSTO todos los meses pares tienen 31 dias || CASO FEBRERO si es bisiesto tiene 29 dias
    dd = (obj.getmm() != 2) ? (obj.getmm() <= 7) ? (obj.getmm() % 2 != 0) ? ajustarFecha(obj.getdd(), 31) : ajustarFecha(obj.getdd(), 30) : (obj.getmm() % 2 == 0) ? ajustarFecha(obj.getdd(), 31)
                                                                                                                                                                   : ajustarFecha(obj.getdd(), 30)
         : (aa % 4 == 0) ? ajustarFecha(obj.getdd(), 29)
                            : ajustarFecha(obj.getdd(), 28);
};
void CDate::ajuste2(int &d, int &m, int &a) {
    if (a < 1)
        a = a * -1;
    if (m < 1)
        m = m * -1;
    if (d < 1)
        d = d * -1;
    m = ajustarFecha(m, 12);
    if (m != 2) {      // EXCLUIMOS FEBRERO
        if (m <= 7) {  // ANTES DE AGOSTO todos los meses impares 31 dias
            if (d != 0)
                d = (m % 2 != 0) ? ajustarFecha(d, 31) : ajustarFecha(d, 30);
            else
                d = (m % 2 != 0) ? 31 : 30;
        } else {  // A PARTIR DE AGOSTO todos los meses pares tienen 31 dias
            if (d != 0)
                d = (m % 2 == 0) ? ajustarFecha(d, 31) : ajustarFecha(d, 30);
            else
                d = (m % 2 == 0) ? 31 : 30;
        }
    } else {  // CASO FEBRERO si es bisiesto tiene 29 dias
        if (d != 0)
            d = (a % 4 == 0) ? ajustarFecha(d, 29) : ajustarFecha(d, 28);
        else
            d = (a % 4 == 0) ? 29 : 28;
    }
};
int CDate::ajustarFecha(int dato, int resta) {
    if (dato <= 0)
        dato++;
    else {
        while (dato > resta)
            dato = dato - resta;
    }
    return dato;
};
void CDate::showShort() {
    ajuste(dd, mm, aa);
    cout << dd << "/" << mm << "/" << aa % 100;
};
void CDate::show() {
    ajuste(dd, mm, aa);
    int diaAux = zeller(dd, mm, aa);
    cout << Dweek[diaAux] << " " << dd << "/" << mm << "/" << aa;
}
void CDate::showAll() {
    ajuste(dd, mm, aa);
    int diaAux = zeller(dd, mm, aa);
    cout << dd << " " << Dweek[diaAux] << " de " << months[mm - 1] << " del " << aa;
};
int CDate::zeller(int d, int m, int a) {
    int diasem = 0, siglo = a / 100, aasiglo = a % 100, auxmes = (m < 3) ? m + 12 : m;
    diasem = (d + (((auxmes + 1) * 26 / 10)) + aasiglo + (aasiglo / 4) + (siglo / 4) - (2 * siglo)) % 7;
    if (diasem < 0)
        diasem = -1 * diasem;
    return diasem;
};
bool CDate::laborable() {
    int diaAux = zeller(dd, mm, aa);
    if (diaAux == 1)
        return true;
    else if (festivo)
        return true;
    else
        return false;
};
bool CDate::festivo() {  // TRUE si es festivo
    int flag = false;
    for (int i = 0; i < 6; i++)
        if (dd == DFest[i] && mm == MFest[i])
            flag = true;
    return flag;
};
void CDate::dayNext(CDate obj) {
    CDate aux(0, 0, 0);
    int daux = 0, maux = 0;
    aux = CDate(obj);
    aux.dd++;
    daux = aux.dd;
    ajuste2(aux.dd, aux.mm, aux.aa);
    if (daux != aux.dd)
        aux.mm++;
    maux = aux.mm;
    ajuste2(aux.dd, aux.mm, aux.aa);
    if (maux != aux.mm)
        aux.aa++;
    aux.show();
};
void CDate::dayBack(CDate obj) {
    CDate aux(0, 0, 0);
    aux = CDate(obj);
    aux.dd--;
    if (aux.dd == 0) {
        aux.mm--;
        if (aux.mm == 0) {
            aux.mm = 12;
            aux.aa--;
        }
        ajuste2(aux.dd, aux.mm, aux.aa);
    }
    ajuste2(aux.dd, aux.mm, aux.aa);
    aux.show();
};
bool CDate::leap() {  // TRUE es bisiesto
    if (aa % 4 == 0)
        return true;
    else
        return false;
};
int CDate::dayDif(CDate &obj1, CDate &obj2) {
    if (obj2.aa < 1)
        obj2.aa = obj2.aa * -1;
    if (obj2.mm < 1)
        obj2.mm = obj2.mm * -1;
    if (obj2.dd < 1)
        obj2.dd = obj2.dd * -1;
    ajuste2(obj1.dd, obj1.mm, obj1.aa);
    if (obj2.aa < 1)
        obj2.aa = obj2.aa * -1;
    if (obj2.mm < 1)
        obj2.mm = obj2.mm * -1;
    if (obj2.dd < 1)
        obj2.dd = obj2.dd * -1;
    ajuste2(obj2.dd, obj2.mm, obj2.aa);
    int contF1 = daystrans(obj1), contF2 = daystrans(obj2);
    return (contF2 - contF1);
};
int CDate::daystrans(CDate &obj) {
    int fechas[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = 0;
    res += obj.dd;
    for (int i = obj.mm - 2; i > 0; i--)
        res += fechas[i];
    res += (obj.aa % 4 == 0) ? +1 : +0;
    obj.aa--;
    res += obj.aa * 365 + obj.aa / 4;
    return res;
};