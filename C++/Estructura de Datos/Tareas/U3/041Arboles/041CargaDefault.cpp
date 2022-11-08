#include <iostream>

using namespace std;

class Arbol {
   public:
    class Nodo {
       public:
        Nodo *izq;
        Nodo *der;
        char dato;

        Nodo() {
            izq = der = NULL;
            dato = 0;
        };
        Nodo(int dato) {
            izq = der = NULL;
            this->dato = dato;
        }
    };

   private:
    Nodo *raiz;
    void carga(Nodo *aux) {
        char resp, info;
        Nodo *otro;

        cout << "\nDame el dato: ";
        cin >> info;
        aux->dato = info;
        cout << endl
             << aux->dato << " Tiene nodo por la izq? s/n ";
        cin >> resp;

        if (resp == 's' || resp == 'S') {
            otro = new Nodo;
            aux->izq = otro;
            carga(aux->izq);  // recursivo
        } else {
            aux->izq = NULL;
        }
        cout << endl
             << aux->dato << " Tiene nodo por la der? s/n ";
        cin >> resp;

        if (resp == 's' || resp == 's') {
            otro = new Nodo;
            aux->der = otro;
            carga(aux->der);
        } else {
            aux->der = NULL;
        }
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
    void carga1(Nodo *nodo) {
        nodo->dato = 'A';
        nodo->izq = new Nodo('C');
        nodo->der = new Nodo('B');
        nodo->izq->izq = new Nodo('D');
        nodo->izq->der = new Nodo('G');
        nodo->der->izq = new Nodo('H');
        nodo->der->izq->izq = new Nodo('I');
        nodo->izq->izq->izq = new Nodo('F');
        nodo->izq->der->izq = new Nodo('E');
        nodo->izq->der->der = new Nodo('J');
        cout << "\tDEFAULT 1" << endl;
    };
    void carga2(Nodo *nodo) {
        nodo->dato = 'A';
        nodo->izq = new Nodo('B');
        nodo->der = new Nodo('C');
        nodo->izq->izq = new Nodo('D');
        nodo->izq->der = new Nodo('E');
        nodo->der->izq = new Nodo('F');
        nodo->der->der = new Nodo('G');
        nodo->izq->izq->izq = new Nodo('H');
        nodo->izq->izq->der = new Nodo('I');
        nodo->der->izq->izq = new Nodo('J');
        nodo->der->izq->der = new Nodo('K');
        cout << "\tDEFAULT 2" << endl;
    };

   public:
    Arbol() {
        this->raiz = new Nodo;  // crea espacio para el nodo raiz;
    }

    Nodo *getRaiz() { return this->raiz; };
    void carga() { carga(raiz); };
    void postOrden() { postOrden(raiz); };
    void preOrden() { preOrden(raiz); };
    void enOrden() { enOrden(raiz); };
    void carga1() { carga1(raiz); };
    void carga2() { carga2(raiz); };
};

int main() {
    Arbol *a = new Arbol, *b = new Arbol;
    cout << "\t<Abraham Melgoza de la Torre>" << endl;

    b->carga2();
    a->carga1();
    cout << endl
         << "\nA Metodo postOrden\n";
    a->postOrden();
    cout << endl
         << "\nA Metodo preOrden\n";
    a->preOrden();
    cout << endl
         << "\nA Metodo EnOrden\n";
    a->enOrden();
    cout << endl
         << "\nB Metodo postOrden\n";
    b->postOrden();
    cout << endl
         << "\nB Metodo preOrden\n";
    b->preOrden();
    cout << endl
         << "\nB Metodo EnOrden\n";
    b->enOrden();
};