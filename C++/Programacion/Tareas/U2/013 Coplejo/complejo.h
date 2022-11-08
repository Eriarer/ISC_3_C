#include <iostream>

using namespace std;

class Complejo{
    private:
        double real, imag;
        friend Complejo suma(Complejo, Complejo);
    public:
        Complejo(double r=0, double i=0){
            real = r;
            imag = i;
        };
        Complejo(const Complejo& obj){
            real = obj.real;
            imag = obj.imag;
        };
        inline void mostrar(){
            cout << real << (imag>0 ? " + ":" - ") << imag << "i" << endl;
        }
        void captura();
};

Complejo suma(Complejo x, Complejo y){
    double r = x.real + y.real;
    double i = x.imag + y.imag;
    return Complejo(r,i);
}

void Complejo::captura(){
    cout << "Dame el real: ";
    cin  >> this->real; cin.ignore();
    cout << "Dame el imaginrio: ";
    cin  >> this->imag;
}