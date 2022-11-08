#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

void push(char *pila,int &cima);
void pop(char *pila,int &cima);
void buscar(char *pila, char funcion[50]);
int pick(char *palabra,int &cima);

int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    //Variables
    char funcion[50];
    char *pila=NULL;
    pila = (char*)malloc(1*sizeof(char));

    cout << endl << "Insterte una funcion algebraica" << endl;
    cin >> funcion;
    buscar(pila, funcion);//manda a buscar si la funcion tiene correspondencia

    free (pila);//libera vector dimanico
    return 0;
}

void push(char *pila,int &cima){//Aumenta el tamaño de la pila
    cima++;
    pila = (char*)realloc(pila,(cima+2));
    cout << endl << "Se ha encontrado un parentesis" << endl << "\tBuscando correspondencia" << endl;
    cout << endl << "Se ha encontrado un parentesis (" << cima+1 << ")" << endl << "\tBuscando correspondencia" << endl;
}

void pop(char *pila, int &cima){
//Elimina el parentesis ( guardado al encontrar su correspondencia 
//reduce tamaño de pila
        pila[cima] = ' ';
        cima--;

        cout << "Se ha encontrado su correspondencia" << endl;
        cout << "Se ha encontrado su correspondencia (" << cima+2 << ")" << endl;

        
}

void buscar(char *pila, char funcion[50]){
    int len, cont, cima=-1;
    bool flag = true;
    len = strlen(funcion);
    cont = 0;

    while(cont < len){
        if(funcion[cont] == '('){//Si encuenta un parentesis hace push y lo guarda en la pila
            push(pila, cima);
            pila[cima] = '(';
        }else{
            if(funcion[cont] == ')'){//encuentra un parentesis
                if(cima < 0){//verifica que exista almenos un ( guardado
                    flag = false;//Si no manda que se acabe el programa
                    break;
                }else{//Si existe se manda a borrar
                    pop(pila, cima);
                }
            }
        }
        cont++;
    }
    if(cima > -1 || flag == false){ //Ultima comparacion por si quedo un parentesis guardado
        cout << endl << "No se encontro correspondencia\nfalta uno o mas parentesis de apertura '('" << endl;
        cout << "\n\tRESLUTADO\n\n"  << "No hubo correspondencia\n\ta esta funcion le faltan parentesis" << endl;
    }else{
        cout << "\n\tRESLUTADO\n\n"  << "Esta funcion tiene correspondencia de parentesis" << endl;
    }
}