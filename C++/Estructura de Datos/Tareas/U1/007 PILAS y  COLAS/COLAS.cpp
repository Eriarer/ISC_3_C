#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<windows.h>
#include<time.h>
using namespace std;

int main(){
    srand(time(NULL));
    cout << endl << "\tABRAHAM MELGOZA DE LA TORRE" << endl;
    cout<<"EJEMPLO insertar y eliminar letras de abecedario en una cola" << endl;
    queue<char> colacar;
    for(int i='A'; i<='Z';i++){
        cout << endl << "Insertando:" << char(i);
        colacar.push(char(i));
    }
    cout << endl;
    while(!colacar.empty()){
        cout << endl << "Eliminando: " << colacar.front();
        colacar.pop();
    }
    cout << endl << endl;

    cout<<"EJEMPLO insertar el nombre de personas para ser atendidos en el banco" << endl;

    char resp;
    string name;
    queue<string> client;
    do{
        cout<<endl<<"Dame el nombre: ";
        getline(cin, name); fflush(stdin);
        client.push(name);
        cout<<endl<<"Desea ingresar datos de otro cliente Y /N"<<"  ";
        cin>>resp;
        fflush(stdin);
    }while(resp=='Y' || resp == 'y');
    cout<<"TOTAL DE CLIENTES"<<client.size();
    cout<<"PRIMER CLIENTE EN COLA"<<client.front();
    cout<<endl<<"\tATENDIENDO"<<endl;
    while(!client.empty()){
        cout << endl << "Atenddiendo a: " << client.front();
        client.pop();
        Sleep(300);
    }
    cout<<"Clientes atentdos, clientes en cola: "<<client.size();
    cout << endl;

    queue<int>infected;
    int total=0, infectados=0, cont=1, opc=0;
    float prom=0;

    do{
        fflush(stdin);
        cout << endl << "\t[ DIA - " << infected.size()+1 << " ]" << endl;
        cout << "Deseas (1) captura automatica (2) captura manual  ";
        cin >> opc; cin.ignore();
        if(opc==1){
            infectados = rand()%100+1;
        }else{
            cout<<endl<<"Cuantos infectados nuevos hay: ";
            cin >> infectados; fflush(stdin);
        }
        infected.push(infectados);
        cout<<endl<<"En el dia no."<< infected.size()+1 << " hay infectados Y /N  ";
        cin>>resp;
    }while(resp=='Y' || resp == 'y');
    while(!infected.empty()){
        total = total + infected.front();
        cout << "REGISTRO DIA-" << cont <<"\tInfectados nuevos [" << infected.front() << "]"<< endl;
        infected.pop();
        cont++;
        Sleep(200);
    }
    cont--;
    prom = total/cont;
    cout << endl << "El promedio de infectados es [" << prom << "]" << endl;
    cout << "TOTAL DE INFECTADOS [" << total << "]" << endl;
    cout << "DIAS TRANSCURRIDOS [" << cont << "]" << endl;
    return 0;
}