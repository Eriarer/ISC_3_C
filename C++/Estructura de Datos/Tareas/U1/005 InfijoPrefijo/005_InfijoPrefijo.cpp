#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

void infpre(); //transformar cadena infija  a posfija ,char cadpos,char cadinf,int &cima
void pop(char*, int &); //pop
void push(char*, int &, char ); // Push a la pila
int jerarquia(char);   //comparar la jerarquia de la cadena
char* invcad(char *, char *);//invierte la cadena


int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    infpre();
    
    return 0;
}

void infpre(){
    char *pila;  pila = NULL;//puntero
    char *cadpre; cadpre = NULL;
    char *cadaux; cadaux = NULL;
    char cadinf[50];
    int cima = -1;
    pila = (char*)malloc(0*sizeof(char)); // vector dinamico
    cadpre = (char*)malloc(0*sizeof(char));//vector dinamico
    cadaux = (char*)malloc(0*sizeof(char));
    if(pila == NULL || cadpre == NULL || cadaux == NULL){
        exit (0);
    }
    char car= '\0', dato= '\0'; //caracter que auxiliara
    int k=0, i=0, len=0; // cont

    cout << endl << "Dame una cadena con caracteres infijos" << endl;
    cin >> cadinf;
    cin.ignore();

    for(i=strlen(cadinf)-1;i>=0; i--){
        car = cadinf[i];
        //hace un push para mantener correspondencia de parentesis
        if(car == ')'){
            push(pila, cima, car);
        }else{
            //si encuentra un ( hay correspondencia y por ende se detiene por que hay que analizar mas caracteres
            if(car == '('){
                while(pila[cima] != ')'){
                    cadpre = (char*)realloc(cadpre,(k+2));
                    dato = pila[cima];
                    pop(pila,cima);
                    cadpre[k] = dato;
                    k++;
                }//fin while
                pop(pila,cima);
            }else{
                //busca si el caracter es un operando
                if(isalpha(car) || isdigit(car)){
                    cadpre = (char*)realloc(cadpre,(k+2));
                    cadpre[k] = car;
                    k++;
                }else{
                    //busca si hay algo en la cima
                    if(cima == -1 || pila[cima] == ')'){
                        push(pila, cima, car);
                    }else{
                        while(cima > -1  &&  pila[cima] != ')' && jerarquia(car)<jerarquia(pila[cima])){
                            cadpre = (char*)realloc(cadpre,(k+2));
                            dato = pila[cima];
                            pop(pila, cima);
                            cadpre[k] = dato;
                            k++;
                        }//fin while
                    push(pila, cima, car);
                    }//fin cima -1 cima ')'
                }//fin isalpha o isdigit
            }//fin car = '('
        }//Fin if car = ')'
    }
    while(cima != -1){
        cadpre = (char*)realloc(cadpre,(k+2));
        dato = pila[cima];
        pop(pila, cima);
        cadpre[k] = dato;
        k++;
    }
    cadpre[k] = '\0';
    cadpre = invcad(cadpre, cadaux);
    cadpre[k] = '\0';

    cout << endl << "CADENA PREFIJA" << endl;
    cout << " [" << cadpre << "]" << endl; 

    free(pila);
    free(cadaux);
    free(cadpre);
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
        vcar=3; break;
    }//end switch
  return vcar;
}

char* invcad(char *cad, char *cadaux){
    int j;
    j=0;
    for(int i=strlen(cad)-1; i>=0; i--){
        cadaux[j]= cad[i];
        j++;
    }
    return cadaux;
}