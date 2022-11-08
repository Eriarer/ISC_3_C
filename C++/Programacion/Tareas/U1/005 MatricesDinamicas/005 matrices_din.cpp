#include<iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>

int** memoria(int,int);
void fmanual(int **,int,int);
void fauto(int **,int,int);
void mostrar(int **,int,int);
void sumatoria(int **, int, int);
void buscar(int **, int, int, int);
void espejo(int **, int, int);
void escalar(int **, int , int , int);

using namespace std;

int main(){
    int opc, fila, colum;
    int **mat=NULL;
    int clave=0, esc=0;
    srand(time(NULL));

    do{
        system("cls");
        cout << "\t\tMENU\n\tQUE DECESAS HACER" << endl;
        cout << "1...Reservar Memoria" << endl;
        cout << "2...Llenar matriz manualmente" << endl;
        cout << "3...Llenar matriz automaticamente" << endl;
        cout << "4...Mostrar matrizr" << endl;
        cout << "5...Sumar el triangulo superior, inferior y la diagonal principal" << endl;
        cout << "6...Buscar un elemento de la matriz" << endl;
        cout << "7...Hacer un espejo a la derecha de la matriz" << endl;
        cout << "8...Multiplicar matriz por escalar" << endl;
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
            cin >> fila;
            cout << endl << "\ttamanio columnas: ";
            cin >> colum;

            mat = memoria(fila,colum);

            cout << "\tMEMORIA RESERVADA" << endl;
            
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 2:
            if(mat == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENADO MANUAL" << endl;
                fmanual(mat, fila, colum);
                cout << "\t\tSE HA TERMINADO DE LLENAR" << endl;
            }
            
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 3:
            if(mat == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENANDO AUTOMATICO" << endl;
                fauto(mat, fila, colum);
               cout << "\n\t\tSE HA TERMINADO DE LLENAR" << endl;
            }            
            
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 4:
            cout << endl << "\t\tMOSTRANDO MATRIZ" << endl;
            mostrar(mat, fila, colum);
            
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 5:
            cout << endl << "\t\tSUMANDO MATRIZ" << endl;
            sumatoria(mat, fila, colum);

        for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 6:
            cout << endl << "\t\tBUSCAR ELEMENTO" << endl;
            cout  << endl << "Que elemento queires buscar: ";
            cin >> clave;
            cin.ignore();
            buscar(mat, fila, colum, clave);
            
        for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 7:
            cout << endl << "\t\tESPEJO MATRIZ" << endl;
            espejo(mat, fila, colum);
            
        for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 8:
            cout << endl << "\t\tMULTIPLICAR POR ESCALAR" << endl;
            cout << endl << "Por cual escalar quieres multiplicar la matriz: ";
            cin >>  esc;
            cin.ignore();

            escalar(mat, fila, colum, esc);
            
        for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        case 9:
            cout << endl << "\t\tSALIENDO";
            for(int i; i<fila; i++){
                delete [] mat[i];
            }
            delete [] mat;
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para salir" <<endl;
            _getch();
            break;
        default:
            cout << endl << "\t\tINSERTE UNA OPCION VALIDA";
            for(int i=0; i<4; i++){
                    Sleep(200);
                    cout << ".";
                }
                cout << "\n\npresione para continuar" <<endl;
            _getch();
            break;
        system("pause");
            break;
        }

    } while (opc !=9 );
    return 0;
}
 
int** memoria(int fila, int colum){
    int **aux;
    aux = new int*[fila];
    for(int i=0; i<fila; i++){
        aux[i] = new int[colum];
    }
    return aux;
}

void fmanual(int **mat,int fila, int colum){
    int i=0, j=0;
    for(i=0; i<fila; i++){
        for(j=0; j<colum; j++){
            cout << "\tInserte el numero (" << i+1 << ")(" << j+1 << ")" << endl;
            cin >> mat[i][j];
            cin.ignore();
        }
    }
}

void fauto(int **mat,int fila, int colum){
    int i=0, j=0;
    for(i=0; i<fila; i++){
        for(j=0; j<colum; j++){
            mat[i][j] = rand() %10 + 1;
        }
    }
}

void mostrar(int **mat,int fila, int colum){
    int i=0, j=0;
    for(i=0; i<fila; i++){
        for(j=0; j<colum; j++){
            cout << "[" << mat[i][j] << "] ";
        }
        cout << endl;
    }
}

void sumatoria(int **mat, int fila, int colum){
    int sumsup=0, suminf=0, sumdiag=0;
    int i, j;
    for(i=0;i<fila-1;i++){//sacar suma superior
        for(j=colum-1;j>0;j--){
            sumsup = sumsup + mat[i][j];
        }
    }
    cout << endl <<  "La suma del triangulo superior es [" << sumsup << "]" << endl;

    for(i=fila-1;i>0;i--){//sacar suma inferior
        for(j=0;j<colum-1;j++){
            suminf = suminf + mat[i][j];
        }
    }
    cout << endl <<  "La suma del triangulo inferior es [" << suminf << "]" << endl;
    
    for(i=0;i<fila;i++){//sacar suma diagonal principal
            sumdiag = sumdiag + mat[i][i];
    }
    cout << endl <<  "La suma de la diagonal principal es [" << sumdiag << "]" << endl;
}

void buscar(int **mat, int fila, int colum, int clave){
    bool flag = false;
    int i=0, j=0;
    for(i=0; i<fila;i++){
        for(j=0; j<colum;j++){
            if(mat[i][j]==clave){
                flag = true;
                cout << endl << "El elemento ["<< mat[i][j] << "] se encontro en la posiciom ["<< i+1 <<"] ["<< j+1 << "]"<< endl;
            }
        }
    }
    if(flag==false){
        cout << endl << "El elemento no se encontro en la  matriz" << endl;
    }// end if
}

void espejo(int **mat, int fila, int colum){
    int i=0, j=0, k=0/*filas*/, l=colum-1/*columas*/;
    int **aux=NULL;
    aux = memoria(fila,colum);

    if(aux!=NULL)cout << "\tMEMORIA RESERVADA" << endl;

    for(i=0; i<fila; i++){
        for(j=0; j<colum; j++){
            aux[k][l] = mat [i][j];
            l--;
        }
    k++;
    l=colum-1;
    }

    cout << endl << "MATIRZ NORMAL" << endl;
    mostrar(mat, fila, colum);

    cout << endl << "MATIRZ ESPEJO" << endl;
    mostrar(aux, fila, colum);
}

void escalar(int **mat, int fila, int colum, int esc){
    int i=0, j=0;
    for(i=0; i<fila;i++){
        for(j=0; j<colum;j++){
                mat[i][j] = mat[i][j] * esc;
        }
    }
    mostrar(mat, fila, colum);
}