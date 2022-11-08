#include<iostream>

using namespace std;

class CVector{
private:
    int n;
    int *vec;
public:
    CVector(int = 1);
    CVector(const CVector&);
    ~CVector();
    void captura();
    void mostrar();
    void sumar(const CVector&, const CVector&);
    void ordenar();
    CVector operator +(const CVector&);
    CVector operator +(int);
    CVector& operator =(const CVector&);
    friend CVector operator +(int, const CVector&);
    CVector operator *(int);
};

CVector::CVector(int n){
    this->n = n;
    vec = new int[n];
    for (int i = 0; i < n; i++){
        vec[i] = 0;
    }
};

CVector::CVector(const CVector &copia){
    n = copia.n;
    vec = new int[n];
    for (int i = 0; i < n; i++){
        vec[i] = copia.vec[i];
    }
};

CVector::~CVector(){
        delete[] vec;
};

void CVector::captura(){
    for (int i = 0; i < n; i++){
        //cout << "Dame el dato: ";
        vec[i] = n-i;
    }
    
};

void CVector::mostrar(){
    for (int i = 0; i < n; i++){
        cout << "[" << vec[i] << "] ";
    }
    cout << endl << endl;;   
};

void CVector::sumar(const CVector& a, const CVector& b){
    if (a.n == b.n){
        delete[] vec;
        n = a.n;
        vec = new int[n];
        for (int i = 0; i < n; i++){
            vec[i] = a.vec[i] + b.vec[i];
        }
    }else{
        cout << "No se pueden sumar";
    }
};

void CVector::ordenar(){
    int aux;
    int j = 0;
    for (int i = 0; i < n; i++){
        aux = vec[i];
        for (j = i; j > 0 && vec[j-1] > aux; j--){
            vec[j] = vec[j-1];
        }
        vec[j] = aux;
    }
};
CVector CVector::operator +(const CVector&obj){
    if(this->n != obj.n){
        cout << "Vectores de diferentes tamanios, no se puede sumar" << endl;
        return;
    }
    CVector temp(this->n);
    for(int i=0; i<this->n;i++)
        temp.vec[i] = this->vec[i] + obj.vec[i];
    return temp;
};
CVector CVector::operator +(int n){
    if(n==0)
        return;
    CVector temp(this->n);
    for(int i=0; i<this->n;i++)
        temp.vec[i] = this->vec[i] + n;
    return temp;

};
CVector& CVector::operator =(const CVector&obj){
    if(this != &obj){
        this->n = obj.n;
        delete []vec;
        vec = new int[this->n];
        for(int i=0; i<n; i++)
            vec[i] = obj.vec[i];
    }
    return *this;
};
CVector operator +(int n, const CVector&obj){

};
CVector CVector::operator *(int){

};