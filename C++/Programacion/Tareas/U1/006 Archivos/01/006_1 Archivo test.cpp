#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;
void consultagral();
void escribir();

int main(){
    int opc;
    do{
        system("cls");
        cout << endl << "1...Escribir" << endl
             << "2...Leer" << endl
             << "9 salir" << endl
             << endl << "OPCION: ";
        cin  >> opc; cin.ignore();

        switch(opc){
            case 1:
                escribir();
                cout << endl << "Datos almacenados" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 2:
                consultagral();
                cout << "\n\n\tPRESIONE PARA ONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 3:
                break;
            case 9:
                break;
            default:
                cout << "Seleccione una opcion correcta" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
        }
    }while(opc!=9);
    return 0;
}

void escribir(){
    fstream archivo;
    char nombre[100];
    int opc;

    archivo.open("Texto.txt", ios::ate | ios::app);    
    if(!archivo){
        cout<<"Error en la apertura de archivo"<<endl;
        cout << "\n\nFATAL ERROR persione para salir" <<endl; _getch();
        exit(0);
    }
    do{
        system("cls");
        cout<<"\tLEER LISTA DE PERSONA"<<endl;
        cout<<endl<<"Nombre de la persona"<<endl;
        fflush(stdin);
        cin.getline(nombre, 100);
        archivo << nombre << endl;
        cout<<endl<<"Otro nombre 1=Si"<<endl << "Seleccion";
        cin>>opc; cin.ignore();
    }while(opc==1);
    archivo.close();
}

void consultagral(){
    fstream archivo;
    char nombre[100];
    archivo.open("Texto.txt", ios::in);
    if(!archivo){
        cout<<"Error en la apertura de archivo"<<endl;
        cout << "\n\nFATAL ERROR persione para salir" <<endl; _getch();
        exit(0);
    }
    cout<<"\tLEER LISTA DE PERSONA"<<endl;
    while(!archivo.eof()){
        cout<<endl<<"Nombre de la persona"<<endl;
        archivo.getline(nombre, 100); cin.ignore();
        cout<<nombre<<endl;
        archivo.close();
    }
}