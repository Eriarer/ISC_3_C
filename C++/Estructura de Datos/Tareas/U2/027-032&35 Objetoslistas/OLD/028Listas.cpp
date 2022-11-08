#include "Listas.h"

int main(int argc, char *argv[]) {
    cout << endl << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    Lista milista;
    int op,num;
    Lista::Nodo *aux;
    do {
        cout << "Listas enlazadas simples" << endl;
        cout << "1.-Insertar inicio" << endl;
        cout << "2.-Insertar final" << endl;
        cout << "3.-Buscar " << endl;
        cout << "4.-pendiente" << endl;
        cout << "5.-pendiente" << endl;
        cout << "6.-pendiente" << endl;
        cout << "7.-Mostrar" << endl;
        cout << "8.-Salir" << endl;
        cout << "Opcion ";
        cin>>op;
        switch(op) {
            case 1:
                cout << endl << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertarInicio(num);
                break;
            case 2:
                cout << endl << "Dame el numero a insertar: ";
                cin >> num;
                milista.insertarFinal(num);
                break;
            case 3:
                cout << endl << "Dame el numero a buscar";
                cin >> num;
                aux=milista.buscar(num);
                if(aux==NULL)
                    cout << endl << num <<" No esta en la lista";
                else
                    cout << endl << num <<" Si esta en la lista";
                break;
            case 7:
                cout << endl << "Muestra Lista: ";
                milista.imprimir();
                break;
            case 8:
                cout << endl << "Fin del programa";
                break;
            default:
                cout << "Error de opcion" << endl;
            }
    }while (op!=8);
}

