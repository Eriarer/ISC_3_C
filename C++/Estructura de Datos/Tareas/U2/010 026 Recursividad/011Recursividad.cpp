#include<iostream>
#include<conio.h>

using namespace std;

void binario(int n);
void rev(int n);
void menu(int op);

int main(){
    cout << "    <ABRAHAM MELGOZA DE LA TORRE>" << endl;
    menu(0);
    return 0;
}

void rev(int n){
    int cociente, residuo;
    cociente=n/10;
    residuo=n%10;
    cout << residuo;
    if(cociente != 0)
        rev(cociente);
}

void binario(int n){
    int cociente, residuo;
    cociente=n/2;
    residuo=n%2;
    cout << residuo;
    if(cociente != 0)
        binario(cociente);
}

void menu(int opc){
    int num;
    if(opc!=3){
        cout << endl << "Funciones recursivas" << endl;
        cout << "1...cambiar de decimal a binario" << endl;
        cout << "2...imprimir un numero al reves" << endl;
        cout << "3...salir" << endl;
        cin >> opc; fflush(stdin);

        switch(opc){
            case 1:
                cout << endl << "Ingresar el numero a convertir a binario: ";
                cin >> num; fflush(stdin);
                cout << endl << "El numero en binario es: ";
                binario(num);
                cout << "\n\n	PRESIONA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
            case 2:
                cout << endl << "Ingrese el numero a invertir: ";
                cin >> num; fflush(stdin);
                rev(num);
                cout << "\n\n	PRESIONA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
            case 3:
                cout << "\n\n	HASTA LUEGO" <<endl; _getch(); //Pausa (needs conio.h)
            break;
            default:
                cout << endl <<"IGNRESE UNA OPCION VALIDA\n\n	PRESIONA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
        }
    menu(opc);
    }
}