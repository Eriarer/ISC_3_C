#include <iostream>
#include <cstdlib>

using namespace std;

class Lista{
public:
    class Nodo{
        public:
            int num;
            Nodo *sig;

            Nodo(int num){
                this->num = num;
                this->sig = NULL;
            };
    };

private:
    Nodo *inicio;
    Nodo *fin;
public:
    Lista(){inicio = fin = NULL;};
    //==================INSERCIONES=============
    void insertarInicio(int n);
    void insertarFinal(int n);
    void insertaraftRef(int ref, int n);
    void insertarBefRef(int ref, int n);
    //==================ELIMINACIONES=============
    void eliminarInicio();
    void eliminaraFin();
    void eliminarMid(int ref);
    //==================FUNCIONES=============
    Nodo *buscar(int n);
    Nodo *antref(int nref);
    void imprimir();
};

//==================INSERCIONES=============
void Lista::insertarInicio(int n){
    Nodo *aux;
    aux = new Nodo(n);
    if(inicio == NULL)
        inicio = fin = aux;
    else{
        aux->sig = inicio;
        inicio = aux;
    }
};
void Lista::insertarFinal(int n){
    Nodo *aux;
    aux = new Nodo(n);
    if(inicio == NULL)
        inicio = aux;
    else
        fin->sig = aux;
    fin = aux;
};  
void Lista::insertaraftRef(int ref, int n){
    if(inicio==NULL){
        cout << "Lista vacia" << endl;
    }
    else{
        Nodo *aux = buscar(ref);
        if(aux == NULL)
            cout << "La referencia no esta en la lista" << endl;
        else{
            if(aux->sig==NULL)
                insertarFinal(n); 
            else{
                Nodo *insert = new Nodo(n);
                insert->sig = aux->sig;
                aux->sig = insert;
            } 
        }
    }
};
void Lista::insertarBefRef(int ref, int n){
    Nodo *anterior = antref(ref);
    if(anterior != NULL){
        if(inicio == anterior)
            insertarInicio(n);
        else{
            Nodo *temp = anterior->sig, *insert = new Nodo(n);
            insert->sig = anterior->sig;
            anterior->sig = insert;
        }
    }
    else
        cout << endl << "No se puede insertar antes de una referencia, Lista vacia" << endl; 
};
//==================ELIMINACIONES=============
void Lista::eliminarInicio(){
    if(inicio->sig==NULL || inicio == fin){
        cout << endl << "Lista vaica" << endl;
        delete inicio;
        inicio = fin = NULL;
    }else{
        Nodo *aux = inicio;
        inicio = aux->sig;
        delete aux;
    }
};
void Lista::eliminaraFin(){
    if(inicio->sig==NULL || inicio == NULL){
        cout << "Lista vaica" << endl;
        delete inicio;
        inicio = fin = NULL;
    }else{
        Nodo *aux = antref(fin->num);
        aux->sig = NULL;
        delete fin;
        fin = aux;
    }
};
void Lista::eliminarMid(int ref){
    if(ref == inicio->num){
        eliminarInicio();
        return;
    }
    if(ref == fin->num){
        eliminaraFin();
        return;
    }
    Nodo *aux = buscar(ref);
    if(aux == NULL){
        cout << endl << "NO SE ENCUENTRA REFERENCIA" << endl;
        return;
    }
    Nodo *ant = antref(ref);
    ant->sig = aux->sig;
    delete aux;
};
//==================FUNCIONES=============
Lista::Nodo *Lista::buscar(int n){
    if(inicio == NULL){
        cout << endl << "LISTA VACIA" << endl;
        return NULL;
    }
    Nodo *aux = inicio;
    while (aux != NULL){
        if(aux->num == n){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
};
void Lista::imprimir(){
    if(inicio==NULL)
        cout << endl << "Lista vacia";
    else{
        Nodo *aux = inicio;
        cout << "\t[ ";
        while(aux!=NULL){
            cout << aux->num;
            if(aux->sig!=NULL)
                cout <<" - ";
            aux = aux->sig;
        }
        cout << " ]";
    }
    cout << endl;
};
Lista::Nodo *Lista::antref(int nref){
    if(inicio == NULL){
        cout << endl << "LISTA VACIA" << endl;
        return NULL;
    }
    Nodo *aux = inicio, *ref = buscar(nref);
    if(aux == NULL || ref == NULL || inicio->sig == NULL || inicio==NULL) goto out;
    if(inicio->num == nref)
        return inicio;
    while(aux->sig != ref){
        aux = aux->sig;
    }
    return aux;
    out:
    cout << "La lista esta vacia|No hay anterior|No se encuentra la referencia" << endl;
    return NULL;
};