#include "Listas.h"
#include<conio.h>

int main(int argc, char *argv[]) {
    cout << endl << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    Lista milista;
    int op,num;
    do {
        cout << "Listas enlazadas simples" << endl;
        cout << "1.-Insertar inicio" << endl;
        cout << "2.-Insertar final" << endl;
        cout << "3.-pendiente" << endl;
        cout << "4.-pendiente" << endl;
        cout << "5.-pendiente" << endl;
        cout << "6.-pendiente" << endl;
        cout << "7.-Mostrar" << endl;
        cout << "8.-Salir" << endl;
        cout << "Opcion ";
        cin >> op;
        switch(op) {
            case 1:
                cout << endl << "Dame el numero a insertar: ";
                cin >>num;
                milista.insertarInicio(num);
                break;
            case 2:
                cout << endl << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertarFinal(num);
                break;
            case 7:
                cout << endl << "Muestra Lista: ";
                milista.imprimir();
                break;
            case 8:
                cout << "\n	Adios" << endl; _getch(); //Pausa (needs conio.h)
                break;
            default:
                cout << "\n\n	ERROR INSERT VALID OPTION" << endl; _getch(); //Pausa (needs conio.h)
        }
    }while (op!=8);
}