#include <windows.h>

#include <iostream>
#include <queue>
#include <stack>

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
        cout << "\tCARGANDO ARBOL";
        Sleep(250);
        for (int i = 4; i != 0; i--) {
            cout << ".";
            Sleep(250);
        }
    };
    void Amplitud(Nodo *node) {
        Nodo *aux;
        if (node != NULL) {
            queue<Nodo *> cola;
            cola.push(node);
            while (!cola.empty()) {
                aux = cola.front();
                cola.pop();
                cout << aux->dato << " ";
                if (aux->izq != NULL) cola.push(aux->izq);
                if (aux->der != NULL) cola.push(aux->der);
            }
        }
    }
    void NodosInternos(Nodo *node) {  // Funcion de nodos internos
        Nodo *aux;
        if (node != NULL) {
            queue<Nodo *> cola;
            cola.push(node);
            while (!cola.empty()) {
                aux = cola.front();
                cola.pop();
                if (aux != raiz && (aux->izq != NULL || aux->der != NULL))
                    cout << aux->dato << " ";
                if (aux->izq != NULL) cola.push(aux->izq);
                if (aux->der != NULL) cola.push(aux->der);
            }
        }
    }
    void AmplitudStack(Nodo *node) {  // lo debe de imrimir a la inversa
        Nodo *aux;                    // debido a la pila
        if (node != NULL) {
            stack<Nodo *> pila;
            pila.push(node);
            while (!pila.empty()) {
                aux = pila.top();
                pila.pop();
                cout << aux->dato << " ";
                if (aux->izq != NULL) pila.push(aux->izq);
                if (aux->der != NULL) pila.push(aux->der);
            }
        }
    }
    bool busqueda(Nodo *node, char num) {
        if (node == NULL)
            return false;
        else if (node->dato < num)
            return busqueda(node->izq, num);
        else if (node->dato > num)
            return busqueda(node->der, num);
        else
            return true;
    }
    void mostrar(Nodo *arbol, int n) {
        if (arbol == NULL)
            return;
        mostrar(arbol->der, n + 1);
        for (int i = 0; i < n; i++)
            cout << " ";
        cout << arbol->dato << endl;
        mostrar(arbol->izq, n + 1);
    }                        // MISTERIO 1
    int hojas(Nodo *node) {  // Cuenta la cantidad de hojas que existe
        if (node == NULL)    //   en el arbol, 0 no hay arbol
            return 0;        //   res tot hojas
        else if (node->izq == NULL && node->der == NULL)
            return 1;
        else
            return hojas(node->izq) + hojas(node->der);
    }                                     // MISTERIO 2
    bool existe(Nodo *node, char info) {  // Buscar un dato en el arbol
        if (node == NULL)                 //     dentro del arbol de manera recursiva
            return false;                 //     true = encontrado, false = no encontrado
        if (node->dato == info)
            return true;
        bool flag = existe(node->izq, info);
        if (flag == true)
            return true;
        flag = existe(node->der, info);
        return flag;
    }                          // MISTERIO 3
    int Niveles(Nodo *node) {  // Cuenta los niveles del arbol
        int der = (node->der == NULL ? 0 : 1 + Niveles(node->der));
        int izq = (node->izq == NULL ? 0 : 1 + Niveles(node->izq));
        return (der > izq) ? der : izq;
    }                        // MISTERIO 4
    int nodos(Nodo *node) {  // Cuenta la cantidad de nodos
        return (node != NULL) ? 1 + nodos(node->izq) + nodos(node->der) : 0;
    }

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
    void Amplitud() { Amplitud(raiz); };
    void AmplitudStack() { AmplitudStack(raiz); };
    void NodosInternos() { NodosInternos(raiz); };
    void mostrar() { mostrar(raiz, 0); };
    int hojas() { return hojas(raiz); };
    bool existe(char info) { return existe(raiz, info); };
    int Niveles() { return Niveles(raiz); };
    int nodos() { return nodos(raiz); };
};

int main() {
    Arbol *a = new Arbol;
    cout << "\t<Abraham Melgoza de la Torre>" << endl;
    char dato;
    a->carga1();
    cout << endl;
    a->mostrar();
    cout << endl
         << "\tNodods interiores" << endl;
    a->NodosInternos();
    cout << endl
         << "MISTERIO 1 -- HOJAS" << endl
         << a->hojas() << endl;
    cout << endl
         << "MISTERIO 2 -- BUSCAR" << endl
         << "Dame el dato a buscar: ";
    cin >> dato;
    cout << (a->existe('C') ? "existe " : "no existe ") << dato << " en el arbol" << endl;
    cout << endl
         << "\tMISTERIO 3 --  NIVELES" << endl
         << "Hay un total de: " << a->Niveles() + 1 << " niveles en el arbol";
    cout << endl
         << "\tMISTERIO 4 -- NODOS" << endl
         << "Existen un totlal de: " << a->nodos() << " nodos en el arbol" << endl;
};