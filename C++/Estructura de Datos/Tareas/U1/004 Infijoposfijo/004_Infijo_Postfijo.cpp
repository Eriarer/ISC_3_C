#include<iostream>
#include<ctype.h>
#include<string.h>

using namespace std;


void infpos(); //transformar cadena infija  a posfija ,char cadpos,char cadinf,int &cima
void pop(char*, int &); //pop
void push(char*, int &, char ); // Push a la pila
int jerarquia(char);   //comparar la jerarquia de la cadena


int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    infpos();

    return 0;
}

void infpos(){ /// cadinf = cadena || cadpos = aux
    char *pila;  pila = NULL;//puntero
    char cadinf[50] , cadpos[50];
    int cima = -1;
    pila = (char*)malloc(0*sizeof(char)); // vector dinamico
    if(pila == NULL){
        exit (0);
    }
    char car= '\0', dato= '\0'; //caracter que auxiliara
    int k=0, i=0, len=0; // cont
    
    cout << "Dame un problema algebraico infijo para transformar a posfijo" << endl;
    cin >> cadinf;
    cin.ignore();

    len = strlen(cadinf);

    for(i=0; i<len; i++){//ciclo while para recorrer la cadena
        car = cadinf[i];
                if(car == '(' ){//busca caracteres ( [ {, si los encuentra los guarda
                    push(pila, cima, car);
                }else{
                    if(car == ')'){//si encuentra } ] ), va sacando lo de la pila en orden
                        while (pila[cima] != '('){
                            dato = pila[cima];
                            pop(pila, cima);
                            cadpos[k] = dato;
                            k++;
                        }//fin while pila[cima] != '(' || pila[cima] == '[' || pila[cima] == '{' 
                        pop(pila,cima);
                    }else{// fin al if car == ')' || car == ']' || car == '} empieza else
                        if(isalpha(car) || isdigit(car)){//checa si es letra o numero, si lo es lo guarda en la cadena posfija; ispunctcheca si es alguno de estos signos !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~.
                            cadpos[k] = car;
                            k++;
                        }else{//fin cadena is alpha is digit
                            if(cima == -1 || pila[cima] == '('){// si la pila esta vacia o tiene un parentesis abierto hace un push al operador
                                push(pila, cima, car);
                            }else{//fin if cima -1 o pila + (, por lo tanto se calcula el operador actual conforme el que este en la cima
                                while( cima != -1 && pila[cima] != '(' && jerarquia(car)<=jerarquia(pila[cima])){//se ejecutara comparaciones 
                                            dato = pila[cima];
                                            pop(pila, cima);
                                            cadpos[k] = dato;
                                            k++;                                      
                                }//end while
                            push(pila, cima, car);
                            }
                        } // fin al else isalpha o difit
                    }//se termina el else de car == ')' || car == ']' || car == '}
                }//fin if(car == '(' || car == '[' || car == '{')
        }//Fin for
    while(cima != -1){
        dato = pila[cima];
        pop(pila, cima);
        cadpos[k] = dato;
        k++;
    }
    cadpos[k] = '\0';
    cout << "\nCadena de modo posfijo\n [" << cadpos << "]" << endl;
    free (pila); // liberar puntero
}

void push(char *pila, int &cima, char car){
    cima++;
    pila = (char*)realloc(pila,(cima+1));//aumenta el tamaño de la pila
    pila[cima] = car;

}

void pop(char *pila, int &cima){
    pila[cima] = '\0';
    cima--;
}

//Si son menor igual TRUE  se guarda en pila
//Si es mayor FALSE se guarda en pila e imprime
int jerarquia(char vcar){//la jerarquia mas altea es 2=^, 1= *,/,% , 0= +, -. a jerarquia mas alta del caracter actual se imprime la pila si no, se guarda el caracter actual en la pila, si son de la misma jerarquia se imprime
    switch (vcar){//asigna un valor al operador actual
    case '+':
        vcar=0; break;
    case '-':
        vcar=0; break;
    case '*':
        vcar=1; break;
    case '/':
        vcar=1; break;
    case '%':
        vcar=1; break;
    case '^':
        vcar=2; break;
    }//end switch
    return (vcar);
}