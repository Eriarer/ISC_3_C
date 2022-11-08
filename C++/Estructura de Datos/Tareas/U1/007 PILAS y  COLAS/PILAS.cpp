#include<iostream>
#include<string.h>
#include<string>
#include<stack>
using namespace std;

int main(){
    cout << "\tABRAHAM MELGOZA DE LA TORRE" << endl;
    //emptystack
    stack<int> pilanum;
    pilanum.push(0);
    pilanum.push(1);
    pilanum.push(2);
    pilanum.push(3);
    pilanum.push(4);
    pilanum.push(5);
    cout << "CIMA DE LA PILA = " << pilanum.top() << endl;//cima
    cout << "TOTAL DE ELEMENTOS = " << pilanum.size() << endl;//tamanio
    cout << endl << "\tVACIANDO PILA" << endl << "\t   ";
    while(!pilanum.empty()){//vacia pila
        cout<< " " << pilanum.top();
        pilanum.pop();
    }
    cout<<endl<<endl;



    stack<char> pila; // otra pila (STUCK)
    string cad;
    char car;
    cout << endl << "Dame la cadena a invertir" << endl;
    cout <<"cadena: ";
    getline(cin, cad);// Se llena a cadena
    for(int i=0;i<cad.size();i++){
        car=cad[i];
        pila.push(car);
    }
    cout<<endl<<"Longitud de candena: " << pila.size() << endl;
    cout << "\tCADENA INVERTIDA" << endl << "\t   ";
    while(!pila.empty()){
        cout <<  pila.top();
        pila.pop();
    }
   cout<<endl<<endl;


    stack<char> pilacorr;
    string cadena;
    int cont=0;
    bool flag=true;


    cout << endl << "Dame la cadena para validar parentesis" << endl;
    cout << "cadena: ";
    getline(cin, cadena);

    while(cont < cadena.size()){
        car=cadena[cont];
        if(car == '('){//Si encuenta un parentesis hace push y lo guarda en la pila
            pilacorr.push(car);
        }else{
            if(car == ')'){//encuentra un parentesis
                if(pilacorr.empty()){//verifica que exista almenos un ( guardado
                    flag = false;//Si no manda que se acabe el programa
                    break;
                }else{//Si existe se manda a borrar
                    pilacorr.pop();
                }
            }
        }
        cont++;
    }
    if(!pilacorr.empty() || flag == false){ //Ultima comparacion por si quedo un parentesis guardado
        cout << endl << "No se encontro correspondencia\nfalta uno o mas parentesis de apertura '('" << endl;
        cout << "\n\tRESLUTADO\n\n"  << "No hubo correspondencia\n\ta esta funcion le faltan parentesis" << endl;
    }else{
        cout << "\n\tRESLUTADO\n\n"  << "Esta funcion tiene correspondencia de parentesis" << endl;
    }
    return 0;
}