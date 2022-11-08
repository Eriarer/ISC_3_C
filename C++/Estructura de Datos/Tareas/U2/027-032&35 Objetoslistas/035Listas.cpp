#include "Listas.h"
#include <conio.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    cout << endl << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    Lista milista;
    int op = 0,num = 0, ref=0;
    Lista::Nodo *aux;
    do {
        cout << "\n\t<LISTAS ENLAZADAS SIMPLES>" << endl
             << "1.- Insertar inicio" << endl
             << "2.- Insertar final" << endl
             << "3.- Buscar " << endl
             << "4.- Insertar despues de una referencia" << endl
             << "5.- Anterior a una referencia" << endl
             << "6.- Isertar antes de una referencia" << endl
             << "7.- Mostrar" << endl
             << "8.- Eliminar inicio" << endl
             << "9.- Eliminar final" << endl
             << "10.-Eliminar enmedio" << endl
             << "11.-Salir" << endl;
        cout << "Opcion ";
        cin>>op;
        switch(op) {
            case 1:
                cout << endl << "\tINSERTAR AL INICIO" << endl
                     << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertarInicio(num);
                cout << endl;
                break;
            case 2:
                cout << endl << "\tINSERTAR AL FINAL" << endl
                     << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertarFinal(num);
                cout << endl;
                break;
            case 3:
                cout << endl << "\tBUSQUEDA" << endl 
                     << "Dame el numero a buscar: ";
                cin >> num;
                aux = milista.buscar(num);
                (aux==NULL)? cout << num <<" No esta en la lista":cout << endl << aux->num <<" Si esta en la lista";
                cout << endl << endl;
                break;
            case 4:
                cout << endl << "\tINSERTAR EN REFERENCIA" << endl ;
                milista.imprimir();
                cout << endl << "Dame el numero referencia referencia: ";
                cin >> ref;
                cout << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertaraftRef(ref, num);
                milista.imprimir();
                cout << endl;
                break;
            case 5:
                cout << endl << "\tINSERTAR EN REFERENCIA" << endl;
                milista.imprimir();
                cout << endl << "Dame el numero referencia: ";
                cin >> ref;
                aux = milista.antref(ref);
                if(aux != NULL)
                    cout << "El anterior es: "<< aux->num << endl;
                cout << endl; 
                break;
            case 6:
                cout << endl << "\tINSERTAR ANTES DE REFERENCIA" << endl;
                milista.imprimir();
                cout << endl << "Dame el numero referencia: ";
                cin >> ref;
                cout << endl << "Que numero quieres insertar: ";
                cin >> num;
                milista.insertarBefRef(ref, num);
                milista.imprimir();
                cout << endl;
                break;
            case 7:
                cout << endl << "\tIMPRIMIR" << endl
                     << "Actualmente contiene" << endl;
                milista.imprimir();
                cout << endl;
                break;
            case 8:
                cout << endl << "\tELIMINAR AL INICIO" << endl;
                cout << "ELIMINANDO";
                for(int i=0; i<5; i++){
                    Sleep(250);
                    cout << ".";
                }
                milista.eliminarInicio();
                break;
            case 9:
                cout << endl << "\tELIMINAR AL FINAL" << endl;
                cout << "ELIMINANDO";
                for(int i=0; i<5; i++){
                    Sleep(250);
                    cout << ".";
                }
                milista.eliminaraFin();
                break;
            case 10:
                cout << endl << "\tELIMINAR AL ENMEDIO" << endl;
                cout << endl << "Dame el numero referencia: ";
                cin >> ref;
                cout << "ELIMINANDO";
                for(int i=0; i<5; i++){
                    Sleep(250);
                    cout << ".";
                }
                milista.eliminarMid(ref);
                break;
            case 11:
                cout << "\n   ADIOS\n\tpresione para salir " << endl; _getch(); //Pausa (needs conio.h)
                break;
            default:
                cout << "\n	ERR0R-00 eliga una opcion valida\n\tpresione para continuar" << endl; _getch(); //Pausa (needs conio.h)
            }
    }while (op!=11);
};