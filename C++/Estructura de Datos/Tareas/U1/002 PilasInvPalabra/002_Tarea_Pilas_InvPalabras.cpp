#include<iostream>
#include<iomanip>

using namespace std;

void pop(char *palabra,int &cima);
void peak(char *palabra,int &cima);
void push(char *palabra,int &cima,int tam);
void invertir(char *palabra,int &cima);
void submenu();
void menu();

int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    
    menu();
    return 0;
}

void menu(){
    int opc;
    do
    {
        cout << "\tQUE DESEAS HACER" << endl;
        cout << "1....Invertir Palabra" << endl;
        cout << "2....Salir" << endl;
        cout << "selecciona opcion: ";
        cin >> opc; cin.ignore();
        switch (opc)
     {
        default:{
            cout << "INSERTE UNA OPCION VALIDA" << endl;
            break;
        }
     case 1:{
        submenu();
        break;
     }
     case 2:{
        cout << "SLAIENDO\n\n\n";
        system("pause");
        break;
     }
     }   
    } while (opc != 2);
}

void submenu(){
    int cima, opc, tam;
    char *palabra;
    tam= rand() %20 + 5;
    palabra = new char(tam);
    cima = -1;
    do{
        cout << "\n\n\tQUE DESEAS HACER" << endl;
        cout << "1....PUSH" << endl;
        cout << "2....POP" << endl;
        cout << "3....PEAK" << endl;
        cout << "4....INVERTIR PALABRA" << endl;
        cout << "5....SALIR" << endl;
        cout << "Selecciona opcion: ";
        cin >> opc;
        fflush(stdin);
        switch(opc){
            default:{
                cout << "INSERTE UNA OPCION VALIDA" << endl;
                break;
            }
            case 1:{
                push(palabra, cima, tam);
                break;
            }
            case 2:{
                pop(palabra, cima);
                break;
            }
            case 3:{
                peak(palabra, cima);
                break;
            }
            case 4:{
                invertir(palabra, cima);
                break;
            }
            case 5:{
                cout << endl << "\tSALIENDO" << endl;
                cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
                menu();
                break;
            }
        }
    }while (opc != 5);
}

void push(char *palabra,int &cima,int tam){
    if(cima == tam - 1){
        cout << endl << "La pila esta llena" << endl;
    }else{
        cout << endl << "Dame el caracter numero " << cima + 2 << " de la palabra: ";
        cin >> palabra[cima];
        fflush(stdin);
        cout << endl;
        cima++;
    }
 
}

void peak(char *palabra, int &cima){
    cout << endl << "El ultimo caracter ingresado (posicion numero " << cima + 1 << ") es: " << palabra[cima-1] << endl;
}

void pop(char *palabra, int &cima){
    if(cima < 0){
        cout << endl << "Cima vale " << cima;
        cout << endl << "La pila esta vacia, primero ingrese datos por favor" << endl;
    }else{
        cima--;
        cout << endl << "Cima vale " << cima;
        cout << endl << "Eliminando valor en la posicion: " << cima + 2 << endl;
        cout << "El caracter era: '" << palabra[cima] << "'" <<  endl;
        
    }
}

void invertir(char* palabra, int &cima){
    cout << endl;
    do{
        cout << palabra[cima-1];
        cima--;
    }while(cima > -1);
    cout << endl << "Palabra invertida y eliminda" << endl;
}