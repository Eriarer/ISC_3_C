#include<iostream>
#include<string>
#include<conio.h>
#include<stack>

using namespace std;
void mostrar(stack<string>);
void push(stack<string> &, string);
void pop(stack<string>&, string);

int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl << "\t\t\tSTACK" << endl;
    stack<string> tren;
string pasajeros, maquina("maquina"), cabus("cabus");
    int opc;
    tren.push(maquina);
    tren.push(cabus);
    cout << "\tMI LOCOMOTORA "; mostrar(tren); cout << endl;
    do{
        cout << endl << "\tQue deseas hacer" << endl;
        cout << "1...Ingresar un pasajeros" << endl;
        cout << "2...Sacar un pasajeros" << endl;
        cout << "3...Mostrar estado del tren" << endl;
        cout << "4...Salir" << endl;
        cout << "Eleccion:";
        cin >> opc; fflush(stdin);
        switch(opc){
        case 1:
            insert:
            cout << "Ingresando numero de pasajeros" << endl;
            cout << "Cantidad: ";
            getline(cin, pasajeros); fflush(stdin);
            if(pasajeros==maquina || pasajeros==cabus){
                    cout << "porfavor inserte un numero de pasajeros valido" << endl;
                    goto insert;
            }
            push(tren, pasajeros);
            cout << "\n  PRESIONE CUALQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;   
        case 2:
            out:
            tren.pop();
            if(tren.top()==maquina){
                tren.push(cabus);
                cout << "NO HAY VAGONES CONECTADOS A LA LOCOMOTORA" << endl;
            }else{
                tren.push(cabus);
                cout << "Que vagon quieres desconectar"<< endl;
                mostrar(tren);
                cout << endl;
                cin >> pasajeros; cin.ignore();
                if(pasajeros==maquina || pasajeros==cabus){
                    cout << "porfavor inserte un numero de pasajeros valido" << endl;
                    goto out;
                }
            pop(tren, pasajeros);
            }
            cout << "\n  PRESIONE CUALQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        case 3:
            mostrar(tren);
            cout << "\n	 PRESIONA CUALQUEIR TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        case 4:
            cout << endl << "\tHASTA LUEGO"  << endl;
            cout << "\n  PRESIONE PARA SALIR" <<endl; _getch(); //Pausa (needs conio.h) 
            fflush(stdin);
            break;          
        default:
            cout << endl << "\tERROR01-SELECCIONE UNA OPCION VALIDA"<< endl;
            cout << "\n  PRESIONE CULQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        }
    } while (opc!=4); 
    return 0;
}

void push(stack<string> &tren, string pasajeros){
    stack<string> aux;
    string cabus("cabus");
    if(tren.top() == cabus){
        aux.push(tren.top());
        tren.pop();
    }
    tren.push(pasajeros);
    while(!aux.empty()){
        tren.push(aux.top());
        aux.pop();
    }
}

void pop(stack<string> &tren, string pasajeros){
    stack<string> aux;
    bool flag=false;
    while(!tren.empty()){
        if(tren.top()==pasajeros){
            tren.pop();
            flag = true;
            break;
        }else{
            aux.push(tren.top());
            tren.pop();
        }
    }
    while (!aux.empty()){
        tren.push(aux.top());
        aux.pop();
    }
    if(flag==false){
        cout << "NO SE ENCONTRO NINGUN VAGON; NO HAY CAMBIOS" << endl;        
    }else{
        cout << "VAGON ENCONTRADO Y DESCONECTADO" << endl;
    }
}

void mostrar(stack<string> tren){
    stack<string> aux;
    string maquina("maquina"), cabus("cabus");
    while(!tren.empty()){
        aux.push(tren.top());
        tren.pop();
    }
    while(!aux.empty()){
        if(aux.top() == maquina){
            cout << "<" << aux.top() << ">-o-";
                tren.push(aux.top());
                aux.pop();
        }else{
            if(aux.top() == cabus){
                cout << "<" << aux.top() << ">";
                tren.push(aux.top());
                aux.pop();
            }else{
                cout << "[" << aux.top() << "]-o-";
                tren.push(aux.top());
                aux.pop();
            }          
        }
    }
}