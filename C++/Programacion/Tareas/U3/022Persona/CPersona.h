#include <string.h>

#include <iostream>

using namespace std;

class CPersona {
   protected:
    string nombre;
    int edad;

   public:
    //=============CONSTRUCTOR=============//
    CPersona() {
        this->nombre = "";
        this->edad = 0;
    };
    CPersona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    };
    CPersona(const CPersona &obj) {
        this->nombre = obj.nombre;
        this->edad = obj.edad;
    };
    //=============GET-SET=============//
    inline string getNombre() { return this->nombre; };
    inline int getEdad() { return this->edad; };
    inline void setNombre(string nombre) { this->nombre = nombre; };
    inline void setEdad(int edad) { this->edad = edad; };
    //=============FUNCIONES=============//
    virtual void mostrar() {
        cout << "Nombre: " << this->nombre << "\nEdad: " << this->edad;
    };
    friend ostream &operator<<(ostream &out, CPersona &obj) {
        out << "Nombre: " << obj.nombre << "\nEdad: " << obj.edad;
        return out;
    };
    friend istream &operator>>(istream &in, CPersona &obj) {
        cout << "Dame el nombre de la persona: ";
        getline(in, obj.nombre);
        cout << "Dame la edad: ";
        in >> obj.edad;
        return in;
    };
};