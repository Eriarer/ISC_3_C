#include "CPersona.h"

class CEstudiante : protected CPersona {
   protected:
    string escuela;
    float promedio;

   public:
    //=============CONSTRUCTOR=============//
    CEstudiante();
    CEstudiante(string escuela, float promedio, string nombre, int edad);
    CEstudiante(const CEstudiante& eobj, const CPersona& pobj);
    CEstudiante(string escuela, float promedio, const CPersona& obj);
    //=============GET-SET=============//
    inline void setEscuela(string nombre) { this->nombre = nombre; };
    inline void setPromedio(int promedio) { this->promedio = promedio; };
    inline string getEscuela() { return this->escuela; };
    inline int getPromedio() { return this->promedio; };
    //=============FUNCIONES=============//
    void mostrar() override;
};
//=============CONSTRUCTOR=============//
CEstudiante::CEstudiante() : CPersona() {
    escuela = "";
    promedio = 0;
}
CEstudiante::CEstudiante(string escuela, float promedio, string nombre, int edad) : CPersona(nombre, edad) {
    this->escuela = escuela;
    this->promedio = promedio;
};
CEstudiante::CEstudiante(const CEstudiante& eobj, const CPersona& pobj) : CPersona(pobj) {
    this->escuela = eobj.escuela;
    this->promedio = eobj.promedio;
};
CEstudiante::CEstudiante(string escuela, float promedio, const CPersona& obj) : CPersona(obj) {
    this->escuela = escuela;
    this->promedio = promedio;
};
//=============FUNCIONES=============//
void CEstudiante::mostrar() {
    CPersona::mostrar();
    cout << endl
         << "Escuela: " << escuela << endl
         << "Promedio: " << promedio;
}