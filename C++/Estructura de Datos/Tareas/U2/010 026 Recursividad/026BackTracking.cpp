#include<iostream>
#include<iomanip>
#include<windows.h>
#define COL 6
#define REN 11

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void imprimir(char lab[REN][COL]);
bool resuelve(char lab[REN][COL], int x, int y);

int main(int arg, char **argv){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    SetConsoleTextAttribute(color,14);
    char lab[REN][COL] ={
        {'#','#','#','#','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#','#','#','#'},
    };
    SetConsoleTextAttribute(color,11);
    cout << endl << "\tSITUACION ACTUAL" << endl;
    imprimir(lab);
    SetConsoleTextAttribute(color,12);
    if(resuelve(lab,1,1)){
        SetConsoleTextAttribute(color,13);
        cout << endl << "\tSOLUCION ENCONTRADA" << endl;
        SetConsoleTextAttribute(color,10);
        imprimir(lab);
    }else
        cout << endl << "\tNO TIENE SOLUCION" << endl;
    
    char lab3[REN][COL]={
        {'#','#','#','#','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#','#','#','#'},
    };
    SetConsoleTextAttribute(color,11);
    cout << endl << "\tSITUACION ACTUAL" << endl;
    imprimir(lab3);
    SetConsoleTextAttribute(color,12);
    if(resuelve(lab3,4,1)){
        SetConsoleTextAttribute(color,13);
        cout << endl << "\tSOLUCION ENCONTRADA" << endl;
        SetConsoleTextAttribute(color,10);
        imprimir(lab3);
    }else
        cout << endl << "\tNO TIENE SOLUCION" << endl;

    SetConsoleTextAttribute(color,14);

    char lab1[REN][COL]={
        {'#','#','#','#','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#','#','#','#','#','#'},
    };
    SetConsoleTextAttribute(color,11);
    cout << endl << "\tSITUACION ACTUAL" << endl;
    imprimir(lab1);
    SetConsoleTextAttribute(color,12);
    if(resuelve(lab1,4,1)){
        SetConsoleTextAttribute(color,13);
        cout << endl << "\tSOLUCION ENCONTRADA" << endl;
        SetConsoleTextAttribute(color,10);
        imprimir(lab1);
    }else
        cout << endl << "\tNO TIENE SOLUCION" << endl;

    SetConsoleTextAttribute(color,14);
    char lab2[REN][COL]={
        {'#','#','#','#','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ','#','#',' ','#'},
        {'#','#','#',' ',' ','#'},
        {' ',' ','#','#',' ','#'},
        {'#',' ','#',' ',' ','#'},
        {'#',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#'},
    };
    SetConsoleTextAttribute(color,11);
    cout << endl << "\tSITUACION ACTUAL" << endl;
    imprimir(lab2);
    SetConsoleTextAttribute(color,12);
    if(resuelve(lab2,1,1)){
        SetConsoleTextAttribute(color,13);
        cout << endl << "\tSOLUCION ENCONTRADA" << endl;
        SetConsoleTextAttribute(color,10);
        imprimir(lab2);
    }else
        cout << endl << "\tNO TIENE SOLUCION" << endl;
    SetConsoleTextAttribute(color,7);
    return 0;
}

void imprimir(char lab[REN][COL]){
    cout << endl;
    for(int i=0; i<REN;i++){
        for(int j=0; j<COL;j++){
            cout << setw(4) << lab[i][j];
        }
    cout << endl;
    }
}

bool resuelve(char lab[REN][COL], int x, int y){
    bool temp;
    lab[y][x]='.';
    if(x == 0 || y == 0 || x == COL-1 || y == REN -1)
        return true;
    //arriba
    if(lab[y-1][x]== ' '){
        temp = resuelve (lab,x,y-1);
        if(temp)
            return true;
    }
    //abajo
    if(lab[y+1][x] == ' '){
        temp = resuelve(lab,x,y+1);
        if(temp)
            return true;
    }
    //izquierda
    if(lab[y][x-1] == ' '){
        temp = resuelve(lab,x-1,y);
        if(temp)
            return true;
    }
    //derecha
    if(lab[y][x+1] == ' '){
        temp = resuelve(lab,x+1,y);
        if(temp)
            return true;
    }
    lab[y][x] = ' ';
    return false;
}