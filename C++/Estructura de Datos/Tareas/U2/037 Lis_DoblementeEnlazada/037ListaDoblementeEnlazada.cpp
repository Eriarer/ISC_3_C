#include<iostream>

using namespace std;

class ListaDoble{
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
                ~Nodo(){delete[]izq; delete[]der;}
        };
    private:
        Nodo *inicio, *fin, *nref;
    public:
        ListaDoble(){ inicio=fin=NULL; }
        ~ListaDoble(){ delete[]inicio; delete[] fin;}
        void insertaAntes(int, int);
        void insertaInicio(int);
        void insertaFinal(int);
        void imprimir(Nodo*, bool);
        void imprimiratras();
        void eliminar(int);
        int promedio();
        Nodo* getinicio(){ return inicio; };
        Nodo* getfinal(){ return fin; };
        Nodo* buscar(int);
};
void ListaDoble::imprimiratras(){
    Nodo *aux = fin;
    cout << "[ ";
    while (aux->izq != NULL){
        cout << " " << aux->num << " -";
        aux = aux->izq;
    }
    cout << " " << aux->num << " ]" << endl;
};
ListaDoble::Nodo* ListaDoble::buscar(int ref){
    if(inicio == NULL){
        cout << endl << "Lista vacia" << endl;
        return NULL;
    }
    nref = inicio;
    while(nref->der != NULL){
        if(nref->num == ref){
            return nref;
        }
        nref = nref->der;
    }
    if(nref->num != ref){
        cout << endl << "No se encuentra la referencia" << endl;
        return NULL;
    }
    cout << "Encontrado" << endl;
    return nref;
};
void ListaDoble::insertaAntes(int n, int ref){
    Nodo *nref = buscar(ref);
    if(nref == NULL){
        cout << endl << "No se encuentra a referencia" << endl;
        return;
    } 
    Nodo *nuevo = new Nodo(n);
    if(nref->izq == NULL){
        nuevo->der = nref;
        nuevo->izq = NULL;
        inicio = nuevo;
    }else{
        nuevo->der = nref;
        nuevo->izq = nref->izq;
        nref->izq->der = nuevo;
        nref->izq = nuevo;
    }
    imprimir(inicio, true);
};
void ListaDoble::insertaInicio(int n){
    Nodo *nuevo;
    nuevo = new Nodo(n);
    if(inicio==NULL){
        inicio = fin = nuevo;
    }else{
        nuevo->der = inicio;
        inicio->izq = nuevo;
        inicio = nuevo;
    }
    imprimir(inicio, true);
};
void ListaDoble::insertaFinal(int n){
    Nodo *nuevo;
    nuevo = new Nodo(n);
    if(inicio==NULL){
        inicio = fin = nuevo;
    }else{
        nuevo->izq = fin;
        fin->der = nuevo;
        fin = nuevo;
    }
    imprimir(inicio, true);
};
void ListaDoble::imprimir(Nodo* aux, bool flag){
    if(aux == NULL){
        cout << endl << "Lista vacia" << endl;
        return;
    }
    if(flag == true){
        if(inicio == aux)
            cout << endl << "\t[";
        if(aux->der != NULL){
            cout << " " << aux->num << " -";
            imprimir(aux->der, true);
        }else
            cout << " " << aux->num << " ]";
    }else{
        if(fin == aux)
            cout << endl << "\t[";
        if(aux->izq != NULL){
            cout << " " << aux->num << " -";
            imprimir(aux->izq, false);
        }else
            cout << " " << aux->num << " ]";
    }
};
void ListaDoble::eliminar(int ref){
    Nodo *eliminar = buscar(ref);
    if(eliminar == NULL){
        cout << endl << "No se encuentra el nodo" << endl;
        return;
    }
    if(inicio == fin){
        fin = inicio = NULL;
    }
    if(eliminar == inicio){
        inicio = inicio->der;
        inicio->izq = NULL;
    }
    if(eliminar == fin){
        fin = fin->izq;
        fin->der = NULL;
    }
    if(eliminar->izq != NULL && eliminar->der != NULL){
        eliminar->izq->der = eliminar->der;
        eliminar->der->izq = eliminar->izq;
    }
    cout << endl << "Eliminado";
    free(eliminar);
};
int ListaDoble::promedio(){
    int prom = 0, cont = 0;
    Nodo* aux = inicio;
    while (aux->der != NULL){
        prom += aux->num;
        aux = aux->der;
        cont++;
    }
    prom += aux->num;
    cont++;
    prom = prom / cont;
    return prom;
};

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl << endl;
    int opc,num,ref;
    ListaDoble milista;
    do{
        cout << endl
             << endl << "\t<LISTAS DOBLEMENTE ENLAZADAS>"
             << endl << "1. Insertar inicio"
             << endl << "2. Insertar final"
             << endl << "3. Insertar antes de una referencia"
             << endl << "4. Promedio de los numeros almacenados en la lista"
             << endl << "5. Eliminar"
             << endl << "6. Imprimir recursivamente"
             << endl << "7. Imprimir empezando en el final"
             << endl << "8. Imprimir empezando en el final(recursivo)"
             << endl << "0. Salir "
             << endl << "\nOpcion: ";
        cin>>opc; fflush(stdin);
        switch(opc){
            case 1:
                cout << endl << "Dame el numero a insertar al inicio: ";
                cin  >> num;
                milista.insertaInicio(num);
                break;
            case 2:
                cout << endl << "Dame el numero a insertar al final: ";
                cin  >> num;
                milista.insertaFinal(num);
                break;
            case 3: 
                cout << endl << "Dame el numero a insertar: ";
                cin  >>num; 
                cout << endl << "Dame la referencia para insertar: ";
                cin  >> ref;
                milista.insertaAntes(num, ref);
                break; 
            case 4:
                cout << endl << "El promedio es: " << milista.promedio() << endl;
                break; 
            case 5: 
                cout << endl << "Dame el numero a eliminar: ";
                cin  >> ref; 
                milista.eliminar(ref);
                break;
            case 6:
                cout << endl << "Imprimir Lista recursivamente: ";
                milista.imprimir(milista.getinicio(), true);
                break;
            case 7:
                cout << endl << "Imprimir empezando desde el fin: ";
                milista.imprimiratras();
                break;
            case 8:
                cout << endl << "Imprimir empezando desde el fin: ";
                milista.imprimir(milista.getfinal(), false);
                break;
            case 0:
                cout << endl << "Fin del programa";
                break;
            default:
                cout << endl << "opcion invalida" << endl;
        }
        cout<<endl;
    }while (opc!=0);   
    return 0;
};