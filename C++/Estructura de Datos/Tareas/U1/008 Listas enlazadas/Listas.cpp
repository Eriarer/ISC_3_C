#include<iostream>
#include<cstdlib>
#include<string>
#include<conio.h>

using namespace std;

struct Nodo{
    string nom;
    Nodo *sig;
};

Nodo* crea();
Nodo *insertStart(Nodo*, string);
Nodo *delLast(Nodo*);
void show(Nodo*);

int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    Nodo *inicio = NULL;
    int opc;
    string nombre;
    do{
        cout << endl << "\t\tMENU" << endl;
        cout << "\tque deceas hacer" << endl;
        cout << "1...Insertar al inicio" << endl;
        cout << "2...Eliminar el ultimo" << endl;
        cout << "3...Recorre lista" << endl;
        cout << "4...Salir" << endl;
        cout << endl << "seleccion: ";
        cin >> opc; cin.ignore();
        switch (opc){
        case 1:
            cout << endl << "\tINSERTAR AL INICIO" << endl;
            cout << "INGRESA TU NOMBRE"<< endl;
                fflush(stdin);
                getline(cin, nombre);

                inicio = insertStart(inicio, nombre);
                cout << endl << "\tDATO INSERTADO" << endl;
            //sys pause
            cout << "presione para continuar" << endl; _getch();
            break;
        case 2:
            inicio = delLast(inicio);
            cout << endl << "\tDATO ELIMINADO" << endl;

            cout << "presione para continuar" << endl; _getch();
            break;
        case 3:
            show(inicio);
            cout << endl;

            cout << "presione para continuar" << endl; _getch();
            break;
        case 4:
            cout << endl << "\tSALIENDO";
        default:
            break;
        }
    }while(opc !=4);

    return 0;
}

Nodo* crea(){
    return(new Nodo);
}

/*q es un auxiliar | p es el nodo principal | t es otro auxiliar*/
//inserta al inicio otro nodo- estructura LIFO
Nodo* insertStart(Nodo *p, string dato){
    Nodo *q=NULL;
    if(p==NULL){
        p=crea();
        p->nom=dato;
        p->sig=NULL;
    }else{
        q=crea();
        q->nom=dato;
        q->sig=p;
        p=q;
    }
    return p;
}

Nodo *delLast(Nodo*p){
    Nodo *q=NULL;
    q = crea();
    if(p==NULL){
        cout << endl << "\tLISTA VACIA" << endl;
    }else{
        q = p;
        if(p->sig==NULL){
            p=NULL;
        }else{
            p=p->sig;
        }
    }
    delete(q);
    return p;
}

void show(Nodo*p){
    Nodo* q=p;
    if(p==NULL){
        cout << endl << "\tLISTA VACIA" << endl;
    }else{
        while(q != NULL){
            cout << endl << "[" << q->nom << "]";
            q = q->sig;
        }
    }
}