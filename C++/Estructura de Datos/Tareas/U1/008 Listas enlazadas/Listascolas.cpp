#include <iostream>

#include <cstdlib>
#include <string>

using namespace std; 

struct nodo{
    string nom;
    int edad;
    nodo *sig;
};

int main(){
cout<<"\tABRAHAM MELGOZA DE LA TORRE" << endl;
nodo *inicio, *fin;
inicio=fin=NULL;
int opc;
string nombre;
int edad;
do{
    cout<<endl<<"Programacion de una cola con una lista enlazadoa";
    cout<<endl<<"1.Insertar";
    cout<<endl<<"2.Eliminar";
    cout<<endl<<"3.Salir";

cout<<endl<<"Elige opcion: ";
cin>>opc;
switch(opc){
    case 1:
        cout<<endl<<"Ingresar un nombre: ";
        fflush(stdin);
        getline(cin,nombre) ;
        cout<<endl<<"Ingresar edad: ";
        cin>>edad;

        nodo *nuevo;

        nuevo=new nodo;
        nuevo->nom=nombre;
        nuevo->edad=edad;
        nuevo->sig = NULL;

        if(inicio == NULL){
        inicio=nuevo;
        }else{
            fin->sig=nuevo;
        }
        fin = nuevo;
        cout<<endl<<"Insertando..."<<nombre<<" edad: "<<edad;
        break;
    case 2:
    if(inicio==NULL){
        cout<<endl<<"\tcolavacia";
    }else{
        nodo *aux=inicio;
        cout<<endl<<"\tEliminando: "<<inicio->nom<<" edad: "<<inicio->edad;
        if(inicio->sig==NULL){
            inicio=fin=NULL;
        }else{
            inicio=inicio->sig;
        }
        delete(aux);
    }
    break;
    case 3:
    cout<<endl<<"Adios";
    break;
    }
}while (opc!=3);
return 0;
}