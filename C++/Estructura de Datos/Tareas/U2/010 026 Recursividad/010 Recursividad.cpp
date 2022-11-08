#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#define TAM 6

using namespace std;
void imprimir1(int);
void imprimir2(int);
void imprimir3(int [TAM], int);
void imprimircad(char [30], int);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int vec[TAM] = {10,11,12,13,14,15};
    char cadena[30];

    imprimir1(10);
    cout << endl;
    imprimir2(1);
    cout << endl;
    imprimir3(vec, 0);
    cout << endl << "\nDamen una cadena:";
    fflush(stdin);
    gets(cadena);
    fflush(stdin);
    imprimircad(cadena,0);
    return 0;
}

void imprimir1(int i){
   if(i>=1){
    cout << " " << i;
    imprimir1(i-1);
   } 
}

void imprimir2(int i){
    if(i<=10){
        cout << " " << i;
        imprimir2(i+1);
    }
}

void imprimir3(int vec[TAM], int i){
    if(i>TAM){
        cout << " " << vec[i];
        imprimir3(vec, i+1);
    }
}
void imprimircad(char v[30], int i){
    if(v[i]!='\0'){
        cout << " " << v[i];
        Sleep(500);
        imprimircad(v,i+1);
    }
}