#include "list.h"
#include<windows.h>
HANDLE console;
void color(int);

int main(){
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    color(11); cout << endl << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int opc=0;
    list lista;
    while (opc!=2){
        color(15); cout << "Inserte un numero: ";
        color(01); cin >> opc;
        lista.insertStart(opc);
        color(15); cout << "Deseas insertar otro numero";
        color(10); cout << " 1-Y"; color(12); cout << " 2-N "; color(15); cout << " = ";
        color(01); cin >> opc;
    }
    cout << endl << endl;
    color(11); cout << "\t<TAMANIO DE LISTA " << lista.gettam()-1 << ">" << endl;
    color(02); lista.Listprint(); color(15);
    lista.Listsort();
    color(10); cout << endl <<"\t<LISTA ORDENADA>" << endl;
    color(03); lista.Listprint();
    color(15);
};
void color(int n){
    SetConsoleTextAttribute(console, n);
};