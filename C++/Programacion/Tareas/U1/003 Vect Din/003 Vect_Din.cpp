#include<iostream>
#include<iomanip>
#include<ctime>

int* memoria(int );
void fmanual(int *,int );
void fauto(int *,int );
void mostrar(int *,int );
void ordenar(int *, int);
int sumatoria(int *, int);
void buscSec(int *, int, int);
void buscBin(int *, int, int);

using namespace std;

int main(){
    int opc=0, tam=0;
    int *vec=NULL;
    int busc=0;
    int suma=0;
    srand(time(NULL));

    do
    {
        system("cls");
        cout << "\t\tMENU\n\tQUE DECESAS HACER" << endl;
        cout << "1...Reservar Memoria" << endl;
        cout << "2...Llenar vector manualmente" << endl;
        cout << "3...Llenar vector automaticamente" << endl;
        cout << "4...Mostrar vector" << endl;
        cout << "5...Ordennar el vector"<< endl;
        cout << "6...Sumar el contenido del vector"<< endl;
        cout << "7...Buscar elemento (sequencial)"<< endl;
        cout << "8...Buscar elemento (binaria)"<< endl;
        cout << "9...salir" << endl;
        cout << endl << "\tseleccion: ";

        cin >> opc;
        cin.ignore();
        system("cls");

        switch (opc){
        case 1:
            cout << endl << "\t\tASIGNANDO MEMORIA" << endl;
            cout << "\tDe que tamanio quiere el vector: ";
            cout << endl << "\ttamanio: ";
            cin >> tam;
            vec = memoria(tam);
            for(int i=0; i<tam; i++){
                vec[i] = 0;
            }
            cout << "\tMEMORIA RESERVADA" << endl;
            system("pause");
            break;
        case 2:
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENADO" << endl;
                fmanual(vec, tam);
                cout << "\t\tSE HA TERMINADO DE LLENAR" << endl;
            }
            
            system("pause");
            break;
        case 3:
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "\t\tLLENANDO" << endl;
                fauto(vec, tam);
               cout << "\t\tSE HA TERMINADO DE LLENAR" << endl;
            }            
            system("pause");
            break;
        case 4:
            cout << endl << "\t\tMOSTRANDO VECTOR" << endl;
            mostrar(vec, tam);
            system("pause");
            break;
        case 5:
            cout << endl << "\t\tORDENAR" << endl;
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << endl << "ORDENANDO" << endl;
                ordenar(vec, tam);
                cout << endl << "ORDENADO" << endl;
            }

            system("pause");
            break;
        case 6:
            cout << endl << "\t\tSUMA" << endl;
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                suma = sumatoria (vec, tam);
                cout << "La suma de todo lo que esta dentro del vector es: [" << suma << "]" << endl;
            }

            system("pause");
            break;
        case 7:
            cout << endl << "\t\tBUSQUEDA SECUENCIAL" << endl;
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << "Dame un numero a buscar" << endl << "numero: ";
                cin >> busc;
                cin.ignore();
                buscSec(vec, tam, busc);                
            }

            system("pause");
            break;
        case 8:
            cout << endl << "\t\tBUSQUEDA BINARIA" << endl;
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{
                cout << "Dame un numero a buscar" << endl << "numero: ";
                cin >> busc;
                cin.ignore();
                buscBin(vec, tam, busc);
            }

            system("pause");
            break;
        case 9:
            cout << endl << "\t\tSALIENDO" << endl;
            if(vec == NULL){
                cout <<  endl << "\t\tPRIMERO ASIGNA MEMORIA" << endl;
            }else{

            }

            system("pause");
            break;
        default:
            cout << endl << "\t\tINSERTE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        system("pause");
            break;
        }

    } while (opc !=9 );
    free(vec);
    return 0;
}
 
int* memoria(int n){
    return (new int[n]);
}

void fmanual(int *vec,int n){
    cout << endl << "\t\tLLENADO MANUAL" << endl;
    for(int i=0; i<n; i++){
        cout << "\tInserte el numero " << i+1 << endl;
        cin >> vec[i];
        cin.ignore();
    }
}

void fauto(int *vec,int n){
    cout << endl << "\t\tLLENADO AUTOMATICO" << endl;
    for(int i=0; i<n; i++){
        vec[i] = rand() %20 + 1;
    }
    cout << endl << "\t\tLLENADO COMPLETADO" << endl;
}

void mostrar(int *vec,int n){
    for(int i=0; i<n; i++){
        cout << "[" << vec[i] << "] ";
    }
}

void ordenar(int *vec, int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vec[j]>vec[j+1]){
                temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

int sumatoria(int *vec, int n){
    int temp=0;
    for(int i=0; i<n; i++){
        temp = temp + vec[i];
    }
    return(temp);
}

void buscSec(int *vec, int tam, int num){
    bool flag= false;
    for(int i=0; i<tam; i++){
        if(num==vec[i]){
            cout << "El numero [" << num << "] se encuentra en el arreglo en la posicion [" << i+1  << "]" << endl;
            flag = true;
        }else{
        }
    }
    if(flag==false){
        cout << "EL numero no se encuentra en el vector" << endl;
    }
}

void buscBin(int *vec, int tam, int clave){
    int up = tam-1;
    int down = 0;
    int centro=0;
    bool flag = false;
    while(down <= up){
        centro = (up + down) / 2;
        if(vec[centro]==clave){
            cout << "El numero [" << clave << "] se encuentra en el arreglo en la posicion [" << centro+1  << "]" << endl;
            flag = true;
            break;
        }else{
            if(clave<vec[centro]){
                up=centro-1;
            }
            else{
                down=centro+1;
            }
        }//fin vec[centro] = clave
    }//fin while

    if(flag==false){
        cout << "EL numero no se encuentra en el vector" << endl;
    }
}