#include "discografia.h"

class CColeccion {
    CDisco* disco;
    int indice, ndiscos;

   public:
    //============CONSTRUCTORES============//
    CColeccion(int n) {
        indice = 0;
        ndiscos = n;
        disco = new CDisco[n];
    };
    ~CColeccion() { delete[] disco; }
    //============GETS-SETS============//
    //--------GET--------//
    char* getCTitulo(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getTitulo();
    };
    int getCCanciones(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getCanciones();
    };
    float getCPrecio(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getPrecio();
    };
    CDate* getCFcompra(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getFcompra();
    };
    int getCFcompraDD(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getFcompraDD();
    };
    int getCFcompraMM(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getFcompraMM();
    };
    int getCFcompraAA(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n].getFcompraAA();
    };
    inline int getCIndice() { return indice; };
    inline int getCNdiscos() { return ndiscos; };
    CDisco getCDisco(int n) {
        if (indice < n) {
            cout << "No existe ese indice" << endl;
            return;
        } else
            return disco[n];
    };
    //--------SET--------//
    inline void setCTitulo(int n, char* titulo) { disco[n].setTitulo(titulo); };
    inline void setCCanciones(int n, int canciones) { disco[n].setCanciones(canciones); };
    inline void setCPrecio(int n, float precio) { disco[n].setPrecio(precio); };
    inline void setCFcompra(int n, const CDate Fcompra) { disco[n].setFcompra(Fcompra); };
    inline void setCFcompra(int n, int dd, int mm, int aa) { disco[n].setFcompra(dd, mm, aa); };
    inline void setCFcompraDD(int n, int dd) { disco[n].setFcompraDD(dd); };
    inline void setCFcompraMM(int n, int mm) { disco[n].setFcompraMM(mm); };
    inline void setCFcompraAA(int n, int aa) { disco[n].setFcompraAA(aa); };
    inline void setCIndice(int indice) { this->indice = indice; };
    inline void setCNdiscos(int ndiscos) { this->ndiscos = ndiscos; };
    inline void setCDicso(int n, CDisco& obj) { this->disco[n] = obj; };
    //============FUNCIONES============//
    inline bool llena() { return (indice == ndiscos ? true : false); }
    inline bool vacia() { return (indice == 0 ? true : false); }
    bool insertar(CDisco&);
    float costo();
    int buscar(string);
    void imprimir(int);
};
//============FUNCIONES============//
bool CColeccion::insertar(CDisco& obj) {
    if (llena())
        return false;
    setCDicso(indice, obj);
    indice++;
};
float CColeccion::costo() {
    if (vacia()) {
        cout << "No hay discos en la collecion";
        return -1;
    }
    float costo = 0;
    for (int i = 0; i < indice; i++) {
        costo += disco[i].getPrecio();
    };
    return costo;
};
int CColeccion::buscar(string titulo) {
    if (vacia()) {
        cout << "No hay discos en la collecion";
        return -1;
    }
    bool flag = false;
    int i;
    for (i = 0; i < indice; i++) {
        if (disco[i].getTitulo() == titulo) {
            flag = true;
            break;
        }
    };
    if (!flag) {
        cout << "No se encuentra ese titulo en la coleccion" << endl;
        return -1;
    }
    cout << "Encontrado..." << endl;
    return i;
};
void CColeccion::imprimir(int indice) {
    if (vacia()) {
        cout << "No hay discos en la collecion";
        return;
    };
    cout << "\t[TITULOS DE COLECCION]" << endl;
    for (int i = 0; i < indice; i++) {
        cout << disco[i].getTitulo() << endl;
    };
};