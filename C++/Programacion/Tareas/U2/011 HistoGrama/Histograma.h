#include<iostream>
#include<string.h>

using namespace std;

class CHistograma{
private:
    struct Datos{
        int frecuencia;
        char entidad[5];
    };
    Datos *vec;
    int n;
public:
//===========CONSTRUCTORES===========
    CHistograma(int = 1);
    CHistograma(const CHistograma&);
    ~CHistograma();
//=============FUNCIONES=============
    void captura();
    void histograma(); // Lo muestra con formato
};


//===========CONSTRUCTORES===========
CHistograma::CHistograma(int n){
    this->n = n;
    vec = new Datos[n];
    for(int i=0; i<n; i++){
        vec[i].frecuencia = 0;         
        strcpy(vec[i].entidad,"");
    }
};
CHistograma::CHistograma(const CHistograma&original){
    this->n = original.n;
    for(int i=0; i<n; i++){
        vec[i].frecuencia = original.vec[i].frecuencia;
        strcpy(vec[i].entidad, original.vec[i].entidad);
    }
};
CHistograma::~CHistograma(){
    delete[] vec;
};
//=============FUNCIONES=============
void CHistograma::captura(){
    for(int i=0; i<n; i++){
        cout << "Dame la entidad correspondiente (abreviatura): ";
        cin  >> vec[i].entidad;
        cout << "Cuantos insidentes se han tenido: ";
        cin  >> vec[i].frecuencia;
    }
};
void CHistograma::histograma(){
    cout << "\t<<HISTOGRAMA>>" << endl;
    for(int i=0; i<n; i++){
        cout << vec[i].entidad << "\t";
        for(int j=0; j<vec[i].frecuencia; j++){
            cout << "*";
        }
        cout << endl;
    }
};