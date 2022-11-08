#include <iostream>
#include <queue>

using namespace std;
//HOLA
class Arbol {
   public:
    class Nodo {
       public:
        Nodo *izq, *der;
        int dato;
        Nodo() {
            izq = der = NULL;
            dato = 0;
        }
        Nodo(int dato) {
            izq = der = NULL;
            this->dato = dato;
        }
    };

   private:
    Nodo *raiz;
    Nodo *insertar(Nodo *nodo, int num) {
        if (nodo == NULL)
            nodo = new Nodo(num);
        else if (num < nodo->dato)
            nodo->izq = insertar(nodo->izq, num);
        else if (num > nodo->dato)
            nodo->der = insertar(nodo->der, num);
        return nodo;
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

   public:
    Arbol(int num) { raiz = new Nodo(num); };
    Arbol() { this->raiz = new Nodo; };  // crea espacio para el nodo raiz
    Nodo *getRaiz() { return raiz; };
    Nodo *insertar(int num) {
        raiz = insertar(raiz, num);
        return raiz;
    }
    void postOrden() { postOrden(raiz); };
    void preOrden() { preOrden(raiz); };
    void enOrden() { enOrden(raiz); };
    void Amplitud() { Amplitud(raiz); };
};

int main() {
    int num, total;
    cout << endl
         << "Cuatos numeros vas a ingresar: ";
    cin >> total;
    cout << endl
         << "Dame el numero raiz: ";
    cin >> num;
    Arbol *a = new Arbol(num);

    cout << endl
         << "Ingresa el resto de los numeros" << endl;
    for (int i = 2; i <= total; i++) {
        cout << "#" << i << "->";
        cin >> num;
        a->insertar(num);
    }
    cout << endl
         << "\nMetodo postOrden\n";
    a->postOrden();
    cout << endl
         << "\nMetodo preOrden\n";
    a->preOrden();
    cout << endl
         << "\nA Metodo EnOrden\n";
    a->enOrden();
    cout << endl
         << "\nA Metodo Amplitud\n";
    a->Amplitud();
};
