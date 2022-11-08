#include <iostream>
#include <time.h>

using namespace std;

class Lista{
    public:
        class Nodo{
            public:
                int num;
                Nodo *izq, *der;
                Nodo(int num){
                    this->num = num;
                    this->izq = NULL;
                    this->der = NULL;
                };
        };
    private:
        Nodo *pivote;
    public:
        Lista(){pivote=NULL;};
        void insertar(int);
        void eliminar(int);
        void imprimir();
        Nodo* buscar(int, bool);
};

void Lista::insertar(int n){
    Nodo *nuevo = new Nodo(n);
    if(pivote == NULL){
        nuevo->izq = nuevo;
        nuevo->der = nuevo;
        pivote = nuevo;
    }else{
        nuevo->izq = pivote->izq;
        pivote->izq->der = nuevo;
        pivote->izq = nuevo;
        nuevo->der = pivote;
    }
};
void Lista::eliminar(int ref){
    if(pivote == NULL){
        cout << endl << "\t[LISTA VACIA]" << endl;
        return;
    }
    Nodo* aux = buscar(ref, false);
    if(aux == NULL)
        return;
    if(pivote == pivote->izq){
        pivote = NULL;
    }else{
        if(pivote == aux){
            pivote->der->izq = pivote->izq;
            pivote->izq->der = pivote->der;
            pivote = pivote->der;
            return;
        }else{
            aux->der->izq = aux->izq;
            aux->izq->der = aux->der;
        }
    }
};
Lista::Nodo* Lista::buscar(int ref, bool flag){
    if(pivote == NULL){
        cout << endl << "\t[LISTA VACIA]" << endl;
        return NULL;
    }
    Nodo* aux = pivote;
    int cont=1;
    do{
        if(aux->num == ref){
            if(flag)
                cout << endl << "El numero " << aux->num << " se encuentra en la posicion no." << cont << endl;
            return aux;
            }
        aux = aux->der;
        cont++;
    }while(pivote != aux);
    cout << endl << "No se encuentra el nodo" << endl;
    return NULL;
};
void Lista::imprimir(){
    if(pivote == NULL){
        cout << endl << "\t[LISTA VACIA]" << endl;
        return;
    }
    Nodo* aux=pivote;
    cout << endl << "[ " << aux->num;
    aux = aux->der;
    while (aux != pivote){
        cout << " - " << aux->num;
        aux = aux->der;
    }
    cout << " ]" << endl;
};

int main(){
    srand(time(NULL));
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    Lista list;
    int opc=-1, num=0;
    do{
        cout << endl << "\t[LISTA DOBLEMENTE ENLAZADA CIRCULAR]"
             << endl << "0.-Salir"
             << endl << "1.-Insertar"
             << endl << "2.-Imprimir"
             << endl << "3.-Buscar"
             << endl << "4.-Eliminar"
             << endl << "opcion:";
        cin  >> opc;
        switch(opc){
            default:
                cout << "OPCION INVALIDA - SELECCIONE OTRA OPCION CORRECTA" << endl;
                break;
            case 0:
                cout << "FINALIZANDO PROGRAMA" << endl;
                break;
            case 1:
                cout << endl << "\t[INSERTANDO]" << endl;
                for(int i=0;i<10;i++)
                    list.insertar(rand()%21);
                break;
            case 2:
                cout << endl << "\t[IMPRIMIENDO]";
                list.imprimir();
                break;
            case 3:
                cout << endl << "\t[BUSCAR]" << endl;
                cout << "Inserte el numero a buscar: ";
                cin  >> num;
                list.buscar(num, true);
                break;
            case 4:
                cout << endl << "\t[ELIMINAR]" << endl;
                cout << "Dame el numero a eliminar: ";
                cin  >> num;
                list.eliminar(num);
                break;
        }
    }while(opc!=0);
    return 0;
};
