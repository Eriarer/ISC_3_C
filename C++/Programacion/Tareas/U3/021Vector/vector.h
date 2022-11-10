#include <time.h>

#include <iostream>

using namespace std;
class CVector {
   private:
    int n;
    int* vec;

   public:
    CVector();
    CVector(int);
    CVector(const CVector&);
    ~CVector();
    void ordenar();  // SORT
    void carga();
    void carga(int, int);
    //*--------------[ + ]--------------*//
    CVector operator+(const CVector&);
    CVector operator+(int);
    friend CVector operator+(int, const CVector&);
    //*--------------[ - ]--------------*//
    CVector operator-(const CVector&);
    CVector operator-(int);
    friend CVector operator-(int, const CVector&);
    //*--------------[ * ]--------------*//
    CVector operator*(int);
    CVector operator*(const CVector&);
    friend CVector operator*(int, const CVector&);
    //*--------------[ = ]--------------*//
    CVector& operator=(const CVector&);
    CVector& operator=(int);
    //*----------[ UNITARIOS ]----------*//
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    //*-----------[ LOGICOS ]-----------*//
    //*---------[ RELACIONALES ]--------*//
    bool operator==(const CVector&);
    bool operator!=(const CVector&);
    bool operator<(const CVector&);
    bool operator>(const CVector&);
    bool operator<=(const CVector&);
    bool operator>=(const CVector&);
    //*=============[ INCERSION EXTRACCION ]=============*//
    //*====================[ FLUJO ]=====================*//
    friend istream& operator>>(istream&, CVector&);
    friend ostream& operator<<(ostream&, CVector&);
};
//==========[IMPLEMENTACION]==========//
CVector::CVector() {
    n = 0;
    vec = new int[n];
    for (int i = 0; i < n; i++) {
        vec[i] = 0;
    }
};
CVector::CVector(int n) {
    this->n = n;
    vec = new int[n];
    for (int i = 0; i < n; i++) {
        vec[i] = 0;
    }
};
CVector::CVector(const CVector& copia) {
    n = copia.n;
    vec = new int[n];
    for (int i = 0; i < n; i++) {
        vec[i] = copia.vec[i];
    }
};
CVector::~CVector() {
    delete[] vec;
};
void CVector::carga() {
    srand(time(NULL));
    for (int i = 0; i < this->n; i++) {
        vec[i] = rand() % 101;
    }
}
void CVector::carga(int limsup, int liminf) {
    srand(time(NULL));
    for (int i = 0; i < this->n; i++) {
        vec[i] = rand() % (limsup + 1) + liminf;
    }
}
void CVector::ordenar() {
    int aux;
    int j = 0;
    for (int i = 0; i < n; i++) {
        aux = vec[i];
        for (j = i; j > 0 && vec[j - 1] > aux; j--) {
            vec[j] = vec[j - 1];
        }
        vec[j] = aux;
    }
};
//============OPERADORES=============//
//*==============[ + ]==============*//
CVector CVector::operator+(int n) {  // suma con un ESCALAR
    if (n == 0)
        return *this;
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] + n;
    return temp;
};
CVector CVector::operator+(const CVector& obj) {  // suma de VECTORES
    if (this->n != obj.n) {
        cout << "Vectores de diferentes tamanios no se puede sumar " << endl;
        return *this;
    }
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] + obj.vec[i];
    return temp;
};
//*------------[ FRIEND ]------------*//
CVector operator+(int n, const CVector& obj) {  // suma de ESCALAR
    if (n == 0)                                 // con VECTOR
        return obj;
    CVector temp(obj.n);
    for (int i = 0; i < obj.n; i++)
        temp.vec[i] = temp.vec[i] + n;
    return temp;
}
//*==============[ - ]==============*//
CVector CVector::operator-(int n) {  // resta con un ESCALAR
    if (n == 0)
        return *this;
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] - n;
    return temp;
};
CVector CVector::operator-(const CVector& obj) {  // resta de VECTORES
    if (this->n != obj.n) {
        cout << "Vectores de diferentes tamanios no se puede sumar ";
        return *this;
    }
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] - obj.vec[i];
    return temp;
};
//*------------[ FRIEND ]------------*//
CVector operator-(int n, const CVector& obj) {  // resta de ESCALAR
    if (n == 0)                                 // con un VECTOR
        return obj;
    CVector temp(obj.n);
    for (int i = 0; i < obj.n; i++)
        temp.vec[i] = obj.vec[i] - n;
    return temp;
};
//*==============[ * ]==============*//
CVector CVector::operator*(int n) {
    if (n == 1)
        return *this;
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] + n;
    return temp;
};
CVector operator*(int n, const CVector& obj) {
    for (int i = 0; i < obj.n; i++)
        obj.vec[i] = obj.vec[i] * n;
    return obj;
};
CVector CVector::operator*(const CVector& obj) {
    if (this->n != obj.n) {
        cout << "No se pueden sumar" << endl;
        return *this;
    }
    CVector temp(this->n);
    for (int i = 0; i < this->n; i++)
        temp.vec[i] = this->vec[i] * obj.vec[i];
    return temp;
}
//*----------[ asignacion ]---------*//
//*==============[ = ]==============*//
CVector& CVector::operator=(const CVector& obj) {
    if (this != &obj) {
        this->n = obj.n;
        delete[] vec;
        vec = new int[obj.n];
        for (int i = 0; i < n; i++)
            vec[i] = obj.vec[i];
    }
    return *this;
};
CVector& CVector::operator=(int a) {
    for (int i = 0; i < n; i++)
        vec[i] = a;
    return *this;
};
//*==========[ UNITARIOS ]==========*//
void CVector::operator++() {  // PREFIJO
    for (int i = 0; i < n; i++)
        ++vec[i];
}
void CVector::operator++(int) {  // POSFIJO
    for (int i = 0; i < n; i++)
        vec[i]++;
}
void CVector::operator--() {  // PREFIJO
    for (int i = 0; i < n; i++)
        --vec[i];
}
void CVector::operator--(int) {  // POSFIJO
    for (int i = 0; i < n; i++)
        vec[i]--;
}
//*===========[ LOGICOS ]===========*//
//*=========[ RELACIONALES ]========*//
bool CVector::operator==(const CVector& obj) {
    if (n != obj.n)
        return false;
    for (int i = 0; i < n; i++)
        if (vec[i] != obj.vec[i])
            return false;
    return true;
}
bool CVector::operator!=(const CVector& obj) {
    return !(*this == obj);
}
bool CVector::operator<(const CVector& obj) {
    return (n < obj.n) ? true : false;
}
bool CVector::operator>(const CVector& obj) {
    return (n > obj.n) ? true : false;
}
bool CVector::operator<=(const CVector& obj) {
    return (n <= obj.n) ? true : false;
}
bool CVector::operator>=(const CVector& obj) {
    return (n >= obj.n) ? true : false;
}
//*=============[ INCERSION EXTRACCION ]=============*//
//*====================[ FLUJO ]=====================*//
istream& operator>>(istream& in, CVector& obj) {
    for (int i = 0; i < obj.n; i++) {
        cout << "Dato [ " << i + 1 << "]->";
        in >> obj.vec[i];
    }
    return in;
}
ostream& operator<<(ostream& out, CVector& obj) {
    for (int i = 0; i < obj.n; i++)
        out << "[ " << obj.vec[i] << " ]";
    return out;
}