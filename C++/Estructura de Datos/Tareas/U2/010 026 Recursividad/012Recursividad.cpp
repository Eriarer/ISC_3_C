#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;
void menu(int opc, int i, int n);
void multiplicar(int n, int i);
void secuencial(int n, int i);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int opc=0, i=0, n=0;
    menu(opc, i, n);
    return 0;
}

void menu(int opc, int i, int n){
    opc=0; i=0; n=0;
        cout << endl << "\tQUE DESEAS HACER" << endl
             << "1...Tabla de multiplicar 1 a 11" << endl
             << "2...Imprimir serie menor al numero" << endl
             << "3...Salir" << endl
             << "Opcion: ";
        cin >> opc; fflush(stdin);
        switch(opc){
            case 1:
                cout << "Inserta el numero a multiplicar" << endl << "Num: ";
                cin >> n; fflush(stdin);
                i=11;
                multiplicar(n, i);
                cout << "\n\n	PRESIONA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                menu(opc, i, n);
                break;
            case 2:
                cout << "Inserta el numero tope de la serie" << endl << "Num: ";
                cin >> n; fflush(stdin);
                i=2;
                secuencial(n, i);
                cout << "\n\n	PRESIONA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                menu(opc, i, n);
                break;
            case 3:
                cout << "\n\n	SALIR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            default:
                cout << "\n\n	INSERTE UNA OPCION VALIDA" <<endl; _getch(); //Pausa (needs conio.h)
                menu(opc, i, n);
                break;
        }
}

void multiplicar(int n, int i){
    int res;
    if(i>1){
        multiplicar(n, (i-1));
    }
    res = n * i;
    cout << n << " x " << i << " = " << res << endl;
}
void secuencial(int n, int i){
    cout << i << " ";
    if(i<n){
        secuencial(n, i*2);
    }
}
