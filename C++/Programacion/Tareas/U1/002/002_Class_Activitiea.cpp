#include<iostream>
#include<iomanip>

using namespace std;

void intercambio(int *, int *);
void mostrar(int *, int *);

int main(){
    cout << "\t\t<Abraham Melgoza de la Torre>" << endl;
    int *ptra=NULL, *ptrb=NULL;
    ptra = new int;
    ptrb = new int;
    *ptra = 20; *ptrb = 10;
    mostrar(ptra, ptrb);
    intercambio(ptra, ptrb);
    mostrar(ptra, ptrb);

    delete (ptra);
    delete (ptrb);
    return 0;
}

void mostrar(int *ptra, int *ptrb){
    cout << "El puntero A apunta a: " << ptra << endl;
    cout << "El puntero A almacena el valor de: " << *ptra << endl;

    cout << "El puntero B apunta a: " << ptrb << endl;
    cout << "El puntero B almacena el valor de: " << *ptrb << endl;
}

void intercambio(int *ptra, int *ptrb){
    cout << "\n\nINTERCAMBIO\n" << endl;
    int aux;
    aux = *ptra;
    *ptra = *ptrb;
    *ptrb = aux;
}