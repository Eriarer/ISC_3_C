#include<iostream>
#include<windows.h>
#include<conio.h>
#define TAM 5

using namespace std;

void insert(int cola[TAM], int &st, int &end);
void del(int cola[TAM], int &st, int &end);

int main(){
    int cola[TAM];
    int st=-1, end=-1, opc=0;
    
//menu
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    cout << "TAMANIO:" << TAM << endl;
    while(opc!=3){
        system("cls");

        cout << endl << "\tCOLA CIRUCLAR" << endl;
        cout << endl << "\tQue deseas hacer" <<  endl;
        cout << endl << "1....Ingresar un numero"<< endl;
        cout << "2....Quitar un numero" << endl;
        cout << "3....Salir" << endl;
        cout << endl <<  endl << "Seleccion: ";
        cin >> opc;
        cin.ignore ();
        system("cls");
        switch(opc){
            case 1:
                cout << endl << "\tCOLA CIRCULAR" << endl << "\tingresando numero" << endl;               
                insert(cola, st, end);
                for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << endl << "\n\n\n\npresione cualquier tecla para continuar" <<endl;
                _getch();
                break;
            case 2:
                cout << endl << "\tCOLA CIRCULAR" << endl << "\tquitando numero" << endl;
                del(cola, st, end);
                for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << endl << endl << "\n\n\n\npresione cualquier tecla para continuar" <<endl;
                _getch();
                break;
            case 3:
                cout << endl << "\nSALIENDO" << endl << "buen dia";
                for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\n\n\npresione cualquier tecla para salir" <<endl;
                _getch();
                break;
            default:
                cout << "SELECCIONE UNA OPCION VALIDA";
                for(int i=0; i<3; i++){
                    Sleep(500);
                    cout << ".";
                }
                break;
        }
    }

    return 0;
}

void insert(int cola[TAM], int &st, int &end){
    int dato=0;
    if(end == TAM-1 && st == 0){//revisa que la cola no este 
        cout << endl << "Cola llena" << endl;
    }else{
        if(end == st-1){
            cout << endl << "Cola llena" << endl;
        }else{
            cout << endl << "Dame el numero a ingresar: ";
            cin >> dato;
            cin.ignore ();
            if(end==TAM-1){//reinicia "CIRCULAR"
                end = 0;
            }else{
                end++;
            }//end IF end == -1
            cola[end] = dato;
            if(end==0 && st ==-1){
                st = 0;
            }
        }        
    }//end IF (end == TAM-1 && st == 0) || end+1 == st
}

void del(int cola[TAM], int &st, int &end){
    if(end == -1){//valida que la cola no este vacia
        cout << endl << "COLA VACIA NO SE PUEDEN ELIMINAR DATOS" << endl;
    }else{
        cout << endl << "Eliminando [" << cola[end] << "]" << endl;
        if(end==st){//al solo quedar un elemento se resetea la cola
            end = -1;
            st = -1;
            cout << endl << "La cola ha quedado vacia" << endl;        
        }else{
            if(end == TAM-1){
                end = 0;//circular
            }else{
                end++;//aumenta el final
            }//end end == tam-1
        }//end end == st
    }//end end == -1
}