#include <windows.h>

#include <iostream>

using namespace std;

class CReloj {
   private:
    int h, m, s;
    int bat;
    void ajuste();

   public:
    //============CONSTRUCTORES============//
    CReloj() {
        h = 0;
        m = 0;
        s = 0;
        bat = 0;
    };
    CReloj(int h, int m, int s, int bat) {
        this->h = h;
        this->m = m;
        this->s = s;
        this->bat = bat;
        ajuste();
    };
    CReloj(const CReloj& obj) {
        h = obj.h;
        m = obj.m;
        s = obj.s;
        bat = obj.bat;
        ajuste();
    };
    //============GETS-SETS============//
    //--------GET--------//
    inline int getH() { return h; };
    inline int getM() { return m; };
    inline int getA() { return s; };
    inline int getBat() { return bat; };
    //--------SET--------//
    inline void setH(int n) {
        h = n;
        ajuste();
    };
    inline void setM(int n) {
        m = n;
        ajuste();
    };
    inline void setS(int n) {
        s = n;
        ajuste();
    };
    inline void setBat(int n) { bat = n; };
    //============FUNCIONES============//
    void tic_tac();
    void avanza(int, int, int);
    void atrasa(int, int, int);
    bool esta_parado();
    void recarga_bateria(int);
    void escribe_en_12h();
    void escribe_en_24h();
    void sincronizar(CReloj&);
};
//============FUNCIONES============//
void CReloj::ajuste() {
    avanza(0, 0, 0);
    atrasa(0, 0, 0);
};

void CReloj::tic_tac() {
    system("CLS");
    if (bat != 0) {
        escribe_en_12h();
        Sleep(250);
        cout << "tick";
        Sleep(250);
        cout << " - ";
        Sleep(250);
        bat--;
        s++;
        ajuste();
        cout << "tack!" << endl;
        Sleep(250);
    } else
        cout << "Bateria descargada" << endl;
};
void CReloj::avanza(int h, int m, int s) {
    this->s = this->s + s;
    while (this->s >= 60) {
        this->s = this->s - 60;
        this->m++;
    }
    this->m = this->m + m;
    while (this->m >= 60) {
        this->m = this->m - 60;
        this->h++;
    }
    this->h = this->h + h;
};
void CReloj::atrasa(int h, int m, int s) {
    this->s = this->s - s;
    while (this->s < 0) {
        this->s += +60;
        this->m++;
    }
    this->m = this->m - m;
    while (this->m < 0) {
        this->m += +60;
        this->h++;
    }
    this->h = this->h - h;
    while (this->h < 0)
        this->h += +24;
};
bool CReloj::esta_parado() {
    return (bat == 0 ? true : false);
};
void CReloj::recarga_bateria(int bat) {
    this->bat += bat;
};
void CReloj::escribe_en_12h() {
    cout << (h > 12 ? (h - 12) : h) << ":" << m << ":" << s << (h > 12 ? ".PM" : ".AM") << endl;
};
void CReloj::escribe_en_24h() {
    cout << h << ":" << m << ":" << s << endl;
};
void CReloj::sincronizar(CReloj& obj) {
    h = (h + obj.h) / 2;
    m = (m + obj.m) / 2;
    s = (s + obj.s) / 2;
    obj.h = h;
    obj.m = m;
    obj.s = s;
};