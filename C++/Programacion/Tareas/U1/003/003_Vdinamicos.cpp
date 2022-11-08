#include<iostream>
#include<iomanip>
#include<ctime>

int** memoria(int,int);
void fmanual(int **,int,int);
void fauto(int **,int,int);
void mostrar(int **,int,int);

using namespace std;

int main(){
    int opc, n, j;
    int **vec=NULL;
    srand(time(NULL));

    do{
        system("cls");
        cout << "\t\tMENU\n\tQUE DECESAS HACER" << endl;
        cout << "1...Reservar Memoria" << endl;
        cout << "2...Llenar vector manualmente" << endl;
        cout << "3...Llenar vector automaticamente" << endl;
        cout << "4...Mostrar vector" << endl;
        cout << "9...salir" << endl;
        cout << endl << "\tseleccion: ";

        cin >> opc;
        cin.ignore();
        system("cls");

        switch (opc){
        case 1:
        cout << endl << "\t\tASIGNANDO MEMORIA" << endl;
            cout << "\tDe que tamanio quiere matriz: ";
            cout << endl << "\ttamanio filas: ";
            cin >> n;
            cout << endl << "\ttamanio columnas: ";
            cin >> j;

            vec = memoria(n,j);
            cout << "\tMEMORIA RESERVADA" << endl;
            system("pause");
            break;
        case 2:
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENADO MANUAL" << endl;
                fmanual(vec, n, j);
                cout << "\t\tSE HA TERMINADO DE LLENAR" << endl;
            }
            
            system("pause");
            break;
        case 3:
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENANDO AUTOMATICO" << endl;
                fauto(vec, n, j);
               cout << "\n\t\tSE HA TERMINADO DE LLENAR" << endl;
            }            
            system("pause");
            break;
        case 4:
            cout << endl << "\t\tMOSTRANDO VECTOR" << endl;
            mostrar(vec, n, j);
            system("pause");
            break;
        case 9:
            cout << endl << "\t\tSALIENDO" << endl;
            for(int i; i<n; i++){
                delete [] vec[i];
            }
            delete [] vec;
            system("pause");
        default:
            cout << endl << "\t\tINSERTE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        system("pause");
            break;
        }

    } while (opc !=9 );
    return 0;
}
 
int** memoria(int n, int j){
    int **aux;
    aux = new int*[n];
    for(int i=0; i<n; i++){
        aux[i] = new int[j];
    }
    return aux;
}

void fmanual(int **vec,int n, int j){
    int k=0, l=0;
    for(k=0; k<n; k++){
        for(l=0; l<j; l++){
            cout << "\tInserte el numero (" << k+1 << ")(" << l+1 << ")" << endl;
            cin >> vec[k][l];
            cin.ignore();
        }
    }
}

void fauto(int **vec,int n, int j){
    int k=0, l=0;
    for(k=0; k<n; k++){
        for(l=0; l<j; l++){
            vec[k][l] = rand() %10 + 1;
        }
    }
}

void mostrar(int **vec,int n, int j){
    int k=0, l=0;
    for(k=0; k<n; k++){
        for(l=0; l<j; l++){
            cout << "[" << vec[k][l] << "] ";
        }
        cout << endl;
    }
}