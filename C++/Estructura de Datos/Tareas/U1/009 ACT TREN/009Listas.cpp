#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>

using namespace std;

struct Nodo{
    string vagon;
    Nodo *liga;
};

Nodo *crea();
Nodo *push(Nodo *tren, string pasajeros);
Nodo *pop(Nodo *tren);
Nodo *invert(Nodo *tren);
Nodo *buscar(Nodo *tren, string pasajeros);
void show(Nodo *tren);
Nodo *meter(Nodo *tren, string pasajeros);

int main(){
    cout << "\t\t<ABRAHAM MELGOZA DE LA TORRE>" << endl << "\t\t\tLISTAS" << endl;
    Nodo *tren=NULL, *aux=NULL;
    string pasajeros;
    string maquina("maquina");
    string cabus("cabus");
    int opc=0;
    tren = push(tren, maquina);// empuja los primeros vagons
    tren = push(tren, cabus);
    aux = crea();
    aux = invert(tren);//invertir esta cadenas es crcial para mi para poder realizar una correcta impresion
    cout << "\tMI LOCOMOTORA "; show(aux);  cout << endl;
    do{
        aux = tren; // resetea el auxiliar para lo que se llegue a ocupar
        cout << endl << "\tQue deseas hacer" << endl;
        cout << "1...Ingresar un pasajero" << endl <<"2...Sacar un pasajero" << endl;
        cout << "3...Mostrar estado del tren" << endl << "4...Salir" << endl << "Eleccion:";
        cin >> opc; fflush(stdin);

        switch(opc){
        case 1:
            insert:
            cout << "Ingresando nombre y cantidad de pasajeros en vagon" << endl;
            cout << "Cantidad: ";
            getline(cin, pasajeros); fflush(stdin);
            if(pasajeros==maquina || pasajeros==cabus){//verificamos que no se intente meter otra maquina o cabus, daria problemas
                cout << "porfavor inserte un nombre y numero de vagon valido" << endl;
                goto insert;
            }
            tren = meter(tren, pasajeros);//va a la funcion meter que hara el llamado a push
            cout << "\n  PRESIONE CUALQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;   
        case 2:
            aux = invert(aux);//reinicia el aux
            out:
            tren = pop(tren);// desconectamos el cabus
            if(tren->vagon==maquina){//si solo queda la maquina por ende no hay nada que vaciar
                tren = push(tren,cabus);//conectamoscabus
                cout << "NO HAY VAGONES CONECTADOS A LA LOCOMOTORA" << endl;
            }else{
                tren = push(tren,cabus);//conectamos cabus
                cout << "Que vagon quieres vaciar"<< endl;
                show(aux);
                cout << endl;
                getline(cin,pasajeros); fflush(stdin);
                if(pasajeros==maquina || pasajeros==cabus){//si se quiere retirar un vagon irremobible no lo permitimos
                    cout << "porfavor inserte un nombre de pasajero valido" << endl;
                    goto out;
                }
                tren = buscar(tren,pasajeros); //se busca, lo cual hara el pop si es requerido
            }
            cout << "\n  PRESIONE CUALQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        case 3:
            aux = invert(aux); //aux se invierte por obejtivo de formato
            show(aux);
            cout << "\n	 PRESIONA CUALQUEIR TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break; 
        case 4:
            cout << endl << "\tHASTA LUEGO"  << endl;
            cout << "\n  PRESIONE PARA SALIR" <<endl; _getch(); //Pausa (needs conio.h) 
            break;    
        default:
            cout << endl << "\tERROR01-SELECCIONE UNA OPCION VALIDA"<< endl;
            cout << "\n  PRESIONE CULQUIER TECLA PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        }
    } while (opc!=4); 
    delete (aux);
    delete (tren);
    return 0;
}

Nodo *crea(){//aparta la memoria
    return (new Nodo);
}

Nodo* push(Nodo *tren, string pasajeros){
    Nodo *aux=NULL;
    if(tren==NULL){// PRIMERA INSERCION
        tren=crea();//al ser nulo se crea 
        tren->vagon=pasajeros;//iguala el dato a lo recibido
        tren->liga=NULL;//NULL
    }else{
        aux=crea();//al no ser asi, asignamos memoria
        aux->vagon=pasajeros;//llenamos con los datos llegados
        aux->liga=tren;// la liga apunta a TODO lo contenido a tren por ende aux es un plus mas lo antes contenido
        tren=aux;//se iguala el tren ya que es lo que nos interesa
    }
    return tren;//se retorna
}

void show(Nodo *tren){
    Nodo* aux=NULL;
    aux = crea();
    aux = tren;//delcaramos un auxiliar igual a lo que mandan
    string cabus("cabus"), maquina("maquina");//declaramos comparaciones paradar formato
    if(aux==NULL){
        cout << endl << "ESTA VACIO" << endl;//si es nulo no se hace nada
    }
    while(aux!=NULL){
        if(aux->vagon == cabus || aux->vagon==maquina){// se compara para formato
            cout << "<" << aux->vagon << ">"; 
            if(aux->vagon==maquina) cout << "-o-";
        }else{
            cout << "[" << aux->vagon << "]-o-";
        }//IMPORTANTE
        aux = aux->liga;//una vez impreso  se amputa al siguiente para seguir imprimiendo
    }
    delete (aux);
}

Nodo *pop(Nodo*tren){//pop basico
    if(tren==NULL){// si es vacio no se saca nada
        cout << endl << "\tLIST//si esA VACIA" << endl;
    }else{
        if(tren->liga==NULL){//si el puntero apunta a nulo, por ende 
            tren=NULL;//al hacer pop se quedara nulo, simplemente hacemos la lista NULL
        }else{
            tren=tren->liga;//si no se cumple, el tren es todo lo de la siguiente
        }
    }
    return tren;//regresa el tren con el pop
}

/*
Genera una pila auxiliar donde se guardan los datos
al guardar en esa pila se almacenan invertidos
retorna auxiliar
*/
Nodo *invert(Nodo *tren){
    Nodo *aux=NULL;
    while(tren!=NULL){
        aux = push(aux, tren->vagon);
        tren = pop(tren);
    }
    tren = aux;
    return tren;
}
/*
Compara los vagones existentes con los vagones que se tienen
esto permite validar
se realiza una busqueda secuencial
*/
Nodo *buscar(Nodo *tren, string pasajeros){
    Nodo *aux=NULL;
    bool flag=false;
    while(tren != NULL){//busqueda secuencial
        if(tren->vagon == pasajeros){
            tren = pop(tren);
            flag = true;
            break;//si se encuentra se elimina y detiene 
        }else{
            aux = push(aux, tren->vagon);//si no se encuentra se hace un pop
            tren = pop(tren);//se guarda en un auxiliar
        }
    }
    while(aux != NULL){//al final se encuentre o no, se regresa todo el auxiliar a la funcion
        tren = push(tren, aux->vagon);
        aux = pop(aux);
    }
    if(flag==true){
        cout << "SE ENCONTRO Y DESCONECTO EL VAGON" << endl;
    }else{
        cout << "EL VAGON NO EXISTE; NO HUBO CAMBIOS" << endl;
    }
    delete (aux);
    return tren;
}

Nodo *meter(Nodo *tren, string pasajeros){//saca cabus, empuja valor, mete cabus
    string cabus("cabus");
    tren = pop(tren);
    tren = push(tren, pasajeros);
    tren = push(tren, cabus);
    return tren;
}