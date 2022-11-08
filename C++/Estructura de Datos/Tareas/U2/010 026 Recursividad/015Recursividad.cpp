#include<iostream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<string.h>

using namespace std;
void menu();
int contdigit(int);
int sumdigit(int);
int facexp(int);
int exp(int);
int division(int, int);
int mcd(int, int);
int inversion(int, int, int);
int mayor(int  *, int , int);
int* crear(int *, int);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    srand(time(NULL));
    menu();
    return 0;
}

void menu(){
    int opc=0, num1=0, num2=0, num3=0, res=0, tam=0, *vec=NULL;
    if(opc!=8){
        res = 0;
        cout << endl << "\tMENU" << endl
             << "1...Cantidad de digitos" << endl
             << "2...Sumatoria de digitos" << endl
             << "3...Factorial al exponente" << endl
             << "4...Division" << endl
             << "5...Maximo comun divisor" << endl
             << "6...Inversion a plazos anuales" << endl
             << "7...Encontrar el numero mas grande" << endl
             << "8...Salir" << endl;
        cin >> opc; fflush(stdin);
        switch (opc)        {
        case 1:
            cout << endl << "\tCANTIDAD DE DIGITOS" << endl
                 << "Dame un digito: ";
            cin >> num1; fflush(stdin);
            res = contdigit(num1);
            cout << endl << "El resultado es: "  << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 2:
            cout << endl << "\tSUMA DE DIGITOS" << endl
                 << "Dame un digito: ";
            cin >> num1; fflush(stdin);
            res = sumdigit(num1);
            cout << endl << "El resultado es: "  << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 3:
            cout << endl << "\tFACTORIAL EXPONENCIAL" << endl
                 << "Dame un digito: ";
            cin >> num1; fflush(stdin);
            res = facexp(num1);
            cout << endl << "El resultado es: "  << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 4:
            cout << endl << "\tDIVISION" << endl
                 << "Dame el numerador: ";
            cin >> num1; fflush(stdin);
            cout << endl << "Dame el denominador: ";
            cin >> num2; fflush(stdin);
            res = division(num1, num2);
            cout << endl << "El resultado de [" << num1 << "] "
                 << "entre [" << num2 << "] es: "
                 << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 5:
            cout << endl << "\tMCD - Maximo Comun Divisor" << endl
                 << "Dame un numero: ";
            cin >> num1; fflush(stdin);
            cout << endl << "Dame otro numero: ";
            cin >> num2; fflush(stdin);
            res = mcd(num1, num2);
            cout << "El MCD [" << num1 << "] "
                 << "entre [" << num2 << "] es: "
                 << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 6:
            cout << endl << "\tINVERSION A PLAZOS ANUALES" << endl
                 << "Dame la cantidad a invertir: ";
            cin >> num1; fflush(stdin);
            cout << endl << "Dame los plazos en anios: ";
            cin >> num2; fflush(stdin);
            cout << endl << "Dame la taza de interes: ";
            cin >> num3; fflush(stdin);
            res = inversion(num1, num2, num3);
            cout << endl << "Despues de " << num2 << " anios la ganancia total es: " << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 7:
            cout << endl << "\tMAYOR DEL VECTOR" << endl
                 << "Dame el tamanio del vector: ";
            cin >> tam; fflush(stdin);
            vec = crear(vec, tam);
            for(int i=0; i<tam; i++){
                vec[i] = rand()%10;
                cout << " [" << vec[i] << "]";
            }
            cout << endl;
            res = mayor(vec, tam-1, 0);
            cout << endl << "El numero mayor es: "  << res << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch();
            break;
        case 8:
            cout << "Adios" << endl;
            cout << "\n	Presiona para salir" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            cout << "\n	Presiona para continuar" <<endl; _getch(); //Pausa (needs conio.h)
            break;
        }
        if(opc!=8)
            menu();
    }
    delete(vec);
}

int contdigit(int n){
    int i=0;
    if(n/10 > 0)
        i = contdigit(n/10);
    return(i+1);
}

int sumdigit(int n){
    int res=0;
    if(n/10 != 0)
        res = n%10 + sumdigit(n/10);
    else
        return(n);
    return(res);
}

int facexp(int n){
    int res=0;
    if(n-1 > 0){
        res = exp(n) + facexp(n-1);
    }
    else
        return(1);
    return (res);
}

int exp(int n){
    int res = 1;
    for(int i=0; i<n; i++)
        res = res * n;
    return (res);
}

int division(int a, int b){
    int i = 0;
    if(a-b > 0)
        i = division ((a-b), b);
    if(a-b >= 0)
        return (i+1);
    else
        return 0;
}

int mcd(int a, int b){
    if(a < b)
        return mcd(b, a);
    else if( b == 0)
            return a;
         else
            return mcd(b, a%b);
}

int inversion(int inv, int anio, int interes){
    if(anio!=0)
        return inversion((inv+((inv*interes)/100)), --anio, interes);
    else
        return inv;
}

int* crear(int *vec, int tam){
    if(vec == NULL)
        vec = (int*)malloc(tam*sizeof(int));
    else
        vec = (int*)realloc(vec,sizeof(int));
    return vec;
}

int mayor(int  *vec, int tam, int m){
    if(tam!=0){
        if(m<vec[tam])
            m = vec[tam];
        return mayor(vec, tam-1, m);
    }
    return m;

}