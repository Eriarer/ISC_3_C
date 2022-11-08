#include <cstring>

#include "CFecha.h"
class CDisco {
   private:
    char titulo[50];
    int canciones;
    float precio;
    CDate Fcompra;

   public:
    //============CONSTRUCTORES============//
    CDisco();
    CDisco(char*, int, float, int, int, int);
    CDisco(char*, int, float, CDate&);
    CDisco(CDisco&);
    //============GETS-SETS============//
    //--------GET--------//
    inline char* getTitulo() { return titulo; };
    inline int getCanciones() { return canciones; };
    inline float getPrecio() { return precio; };
    inline CDate* getFcompra() { return &Fcompra; };
    inline int getFcompraDD() { return Fcompra.getdd(); };
    inline int getFcompraMM() { return Fcompra.getmm(); };
    inline int getFcompraAA() { return Fcompra.getaa(); };
    //--------SET--------//
    inline void setTitulo(char* titulo) { strcpy(this->titulo, titulo); };
    inline void setCanciones(int canciones) { this->canciones = canciones; };
    inline void setPrecio(float precio) { this->precio = precio; };
    inline void setFcompra(const CDate& Fcompra) { this->Fcompra = Fcompra; };
    inline void setFcompra(int dd, int mm, int aa) { Fcompra.ajuste(dd, mm, aa); };
    inline void setFcompraDD(int dd) { Fcompra.setdd(dd); };
    inline void setFcompraMM(int mm) { Fcompra.setmm(mm); };
    inline void setFcompraAA(int aa) { Fcompra.setaa(aa); };
    //============FUNCIONES============//
    void mostrar();
};

//============CONSTRUCTORES============//
CDisco::CDisco() {
    strcpy(titulo, "");
    canciones = 0;
    precio = 0;
    Fcompra.setdd(0);
    Fcompra.setmm(0);
    Fcompra.setaa(0);
};
CDisco::CDisco(char* titulo, int canciones, float precio, int dd, int mm, int aa) {
    strcpy(this->titulo, titulo);
    this->canciones = canciones;
    this->precio = precio;
    setFcompra(dd, mm, aa);
};
CDisco::CDisco(char* titulo, int canciones, float precio, CDate& obj) {
    strcpy(this->titulo, titulo);
    this->canciones = canciones;
    this->precio = precio;
    Fcompra.ajuste(obj);
};
CDisco::CDisco(CDisco& obj) {
    strcpy(titulo, obj.titulo);
    canciones = obj.canciones;
    precio = obj.precio;
    Fcompra = obj.Fcompra;
};
//============FUNCIONES============//
void CDisco::mostrar() {
    cout << "El titulo del disco es: " << titulo
         << "Tiene: " << canciones << " canciones"
         << "Precio de compra:" << precio
         << "Fecha de compra" << Fcompra.getdd() << "/"
         << Fcompra.getmm() << "/"
         << Fcompra.getaa();
};