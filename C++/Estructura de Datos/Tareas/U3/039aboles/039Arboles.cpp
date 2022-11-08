#include <iostream>
using namespace std;

class Arbol {
   public:
    class Nodo {
       public:
        Nodo *izq, *der;
        char dato;
    };

   private:
    Nodo *raiz;

   public:
    Arbol() {
        this->raiz = new Nodo();
    };
    Nodo *getRaiz() { return this->raiz; }
    void carga(Nodo *aux) {
        char resp, info;
        Nodo *otro;
        cout << "\nDame el dato: ";
        cin >> info;
        aux->dato = info;
        cout << endl
             << " [ "
             << aux->dato << " ] tiene nodo por la izq ? s/n" << endl;
        fflush(stdin);
        cin >> resp;
        if (resp == 's' || resp == 'S') {
            otro = new Nodo();
            aux->izq = otro;
            carga(aux->izq);
        } else
            aux->izq = NULL;
        cout << endl
             << " [ "
             << aux->dato << " ] tiene nodo por la der ? s/n " << endl;
        fflush(stdin);
        cin >> resp;
        if (resp == 's' || resp == 'S') {
            otro = new Nodo();
            aux->der = otro;
            carga(aux->der);
        } else
            aux->der = NULL;
    }
    void postOrden(Nodo *nodo) {
        if (nodo != NULL) {
            postOrden(nodo->izq);
            postOrden(nodo->der);
            cout << nodo->dato << " ";
        }
    }
    void preOrden(Nodo *nodo) {
        if (nodo != NULL) {
            cout << nodo->dato << " ";
            preOrden(nodo->izq);
            preOrden(nodo->der);
        }
    }
    void enOrden(Nodo *nodo) {
        if (nodo != NULL) {
            enOrden(nodo->izq);
            cout << nodo->dato << " ";
            enOrden(nodo->der);
        }
    }
};

int main() {
    cout << "\t<Abraham Melgoza de la Torre>" << endl;
    Arbol *a = new Arbol();

    a->carga(a->getRaiz());

    cout << endl
         << "Metodo posOrden" << endl;
    a->postOrden(a->getRaiz());
    cout << endl
         << "Metodo preOrden" << endl;
    a->preOrden(a->getRaiz());
    cout << endl
         << "Metodo enOrden" << endl;
    a->enOrden(a->getRaiz());
    return 0;
};