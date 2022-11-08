#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class ListaCircular{
    public:
        class Nodo{
            public:
                string nombre;
                Nodo *sig;

                Nodo(string nombre){
                    this->nombre = nombre;
                    this->sig = NULL;
                };
        };
    public:
        Nodo *actual;
        ListaCircular(){ actual=NULL; };
        ~ListaCircular(){ delete[]actual;};
        Nodo *buscar(string nombre){
            Nodo *aux;
            if(nombre==actual->nombre){
                return actual;
            }else{
                aux = actual->sig;
                do{
                    if(aux->nombre ==nombre){
                        return aux;
                    }
                    aux = aux->sig;
                }while(aux != actual);
            }
            return NULL;
        };
        void insertar(string nombre){
            Nodo *nuevo;
            nuevo=new Nodo(nombre);
            if(actual==NULL){
                nuevo->sig=nuevo;
            }else{
                nuevo->sig = actual->sig;
                actual->sig = nuevo;
            }
            actual = nuevo;
            imprimir();
        };        
        void eliminar(string nombre){
            if(actual==NULL){
                cout<<"No hay nombres";
                return;
            }
            if(actual->sig==NULL || actual->nombre==nombre){
                delete (actual);
                return;
            }
            Nodo *aux, *ant;
            aux = buscar(nombre);
            ant = aux;
            while(ant->sig!=aux){
                ant = ant->sig;
            }
            ant->sig = aux->sig;
            delete (aux);
        };
        void imprimir(){
            if(actual !=NULL){
                Nodo *aux;
                aux=actual;
                cout<<endl;
                do{
                    cout<<aux->nombre<<"-";
                    aux=aux->sig;
                } while(aux != actual);
            }else{
                cout<<endl<<"Lista Vacia";
            }
        };
        void imprimirecursivo(Nodo *aux){
            if(aux->sig != actual){
                cout << aux->nombre;
                imprimirecursivo(aux->sig);
            }else{
                cout << "-" << aux->nombre << endl;
            }
        };
};



int main(int argc, char *argv[]){
    ListaCircular miLista;
    ListaCircular :: Nodo *aux;
    int opc;
    string nom;
    cout << endl << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    do{
        cout << "Accion a realizar"     << endl
             << "1.-Insertar"           << endl
             << "2.-Eliminar"           << endl
             << "3.-Buscar"             << endl
             << "4.-Imprimir"           << endl
             << "5.-Imprimir recursivo" << endl
             << "6.-Salir"              << endl
             << "Ingrese opcion: ";
        cin  >> opc;
        switch(opc) {
            case 1:
                cout << endl << "Dame el nombre: ";
                cin  >> nom;
                miLista.insertar(nom);
                cout << endl; fflush(stdin);
                break;
            case 2:
                cout << endl << "Nombre a eliminar: ";
                cin  >> nom;
                miLista.eliminar(nom);
                cout << endl; fflush(stdin);
                break;
            case 3:
                cout << endl << "Buscar nombre: ";
                cin  >> nom; fflush(stdin);
                aux = miLista.buscar(nom);
                if(aux!=NULL){
                    cout << endl << nom << " Nombre localizado";
                }else{
                    cout << endl << nom << " Nombre no localizado";
                }
                cout << endl;
                break;
            case 4:
                miLista.imprimir();
                cout << endl;
                break;
            case 5:
                aux = miLista.actual;
                miLista.imprimirecursivo(aux);
                break;
            case 6:
                cout << endl << "Programa finalizado ";
                cout << endl;
                break;
            default:
                cout << endl << "Opcion invalida" << endl;
        }
    }while(opc!=6);
    miLista.~ListaCircular();
    return 0;
};