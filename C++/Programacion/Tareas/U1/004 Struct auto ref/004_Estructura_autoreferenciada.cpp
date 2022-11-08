#include<iostream>
#include<iomanip>

using namespace std;
struct TNodo{
    int info;
    TNodo *liga;
};

TNodo* crea();
TNodo* insertaInicio(TNodo *, int);

int main(){
    TNodo *p=NULL;
    int dato;

    insertaInicio(p,dato);
    return 0;
}

//reserva memoria
TNodo* crea(){
    return(new TNodo);
}

//inserta al inicio otro nodo- estructura LIFO
TNodo* insertaInicio(TNodo *p, int dato){
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