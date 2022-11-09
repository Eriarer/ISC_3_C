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
    bool busqueda(Nodo *node, char info) {  // Buscar un dato en el arbol
        if (node == NULL)                   //     dentro del arbol de manera recursiva
            return false;                   //     true = encontrado, false = no encontrado
        if (node->dato == info)
            return true;
        bool flag = existe(node->izq, info);
        if (flag == true)
            return true;
        flag = existe(node->der, info);
        return flag;
    }
    void mostrar(Nodo *arbol, int n) {
        if (arbol == NULL)
            return;
        mostrar(arbol->der, n + 1);
        for (int i = 0; i < n; i++)
            cout << " ";
        cout << arbol->dato << endl;
        mostrar(arbol->izq, n + 1);
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
    void carga2() { carga2(raiz); };
    void Amplitud() { Amplitud(raiz); };
    void AmplitudStack() { AmplitudStack(raiz); };
    void mostrar() { mostrar(raiz, 0); };
    bool busqueda(char num) { return busqueda(raiz, num); };
};

int main() {
    Arbol *a = new Arbol, *b = new Arbol;
    cout << "\t<Abraham Melgoza de la Torre>" << endl;
    char dato;
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
         << "\nA Metodo Amplitud QUEUE\n";
    a->Amplitud();
    cout << endl
         << "\nA Metodo Amplitud STACK\n";
    a->AmplitudStack();
    cout << endl
         << "Que dato quieres buscar: ";
    cin >> dato;
    cout << endl
         << (a->busqueda(dato) ? "encontrado" : "no encontrado") << endl;
    cout << endl
         << "Que dato quieres buscar: ";
    cin >> dato;
    cout << endl
         << (a->busqueda(dato) ? "encontrado" : "no encontrado") << endl;
    a->mostrar();
};