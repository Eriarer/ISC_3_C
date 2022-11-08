#include "Listas.h"

int main(){
    cout << endl << "\t\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int opc=0;
    list list1, list2;
    loop:
    list1.createlist();
    list1.Listprint();
    list2.copyList(list1);
    list2.Listprint();
    cout << endl << "Deseas volver a crear una lista y su copia?\n\t1-Y 2-N" << endl;
    cin >> opc;
    if(opc==1)
        goto loop;
    return 0;
};