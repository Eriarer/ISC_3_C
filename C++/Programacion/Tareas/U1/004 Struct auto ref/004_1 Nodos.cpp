#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

using namespace std;
struct TNodo{
    int info;
    TNodo *liga;
};

TNodo* crea();
TNodo *insertStart(TNodo*, int);
TNodo *delLast(TNodo*);
void show(TNodo*);

int main(){
    TNodo *p=NULL;
    int dato, opc=0;
    do{
        cout << endl << "\t\tMENU" << endl;
        cout << "\tque deceas acer" << endl;
        cout << "1....Insertar al inicio" << endl;
        cout << "2...Eliminar el ultimo" << endl;
        cout << "3...Recorre lista" << endl;
        cout << "4...Salirt" << endl;
        cout << endl << "seleccion: ";
        cin >> opc;
        cin.ignore();
        switch (opc)        {
        case 1:
            cout << endl << "\tINSERTAR AL INICIO" << endl;
            cout << "Que dato quieres insertar: ";
            cin >> dato;
            p = insertStart(p, dato);
            cout << endl << "\tDATO INSERTADO" << endl;
            //sys pause
            cout << endl << "\npresione para continuar" << endl;
            _getch();
            break;
        case 2:
            p = delLast(p);
            cout << endl << "\tDATO ELIMINADO" << endl;

            cout << endl << "\npresione para continuar" << endl;
            _getch();
            break;
        case 3:
            show(p);
            cout << endl;

            cout << endl << "\npresione para continuar" << endl;
            _getch();
            break;
        case 4:
            cout << endl << "\tSALIENDO";
        default:
            break;
        }
    }while(opc !=4);
    return 0;
}

//reserva memoria
TNodo* crea(){
    return(new TNodo);
}

//inserta al inicio otro nodo- estructura LIFO
TNodo* insertStart(TNodo *p, int dato){
    TNodo *q=NULL;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->liga=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->liga=p;
        p=q;
    }
    return p;
}

TNodo *delLast(TNodo*p){
    TNodo *q, *t;
    q=p;
    if(p==NULL){
        cout << endl << "\tLISTA VACIA" << endl;
    }else{
        if(p->liga!=NULL){
            t=q;
            q=q->liga;
        }
        t->liga=NULL;
    }
    delete(q);
    return p;
}

void show(TNodo*p){
    TNodo* q=p;
    if(p==NULL){
        cout << endl << "\tLISTA VACIA" << endl;
    }else{
        while(q != NULL){
            cout << endl << "[" << q->info << "]";
            q = q->liga;
        }
    }
}