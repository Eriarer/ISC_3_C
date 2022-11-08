#include <iostream>
#include <cstring>

using namespace std;

bool permutaciones(char cad[], int l, int r){
    char pass[]="21Kzm#";
    char temp;
    char aux[60];
    bool flag = false;
    strcpy(aux, cad);
    if(strcmp(aux, pass) == 0){
        return true;
    }
    else{
        if(l==r)
            cout << endl << aux;
        else{
            for(int i=l; i<r; i++){
                if(!flag){
                    temp=aux[l];
                    aux[l] = aux[i];
                    aux[i] =temp;
                    cad = aux;
                    flag = permutaciones(cad, l+1, r);
                }
            }
        }
    }
    return flag;
}


int main(){
    char cad[]="mK2#z1";
    bool flag= permutaciones(cad,0,strlen(cad));
    if(flag)
        cout << endl << "Bienvenido al sistema" << endl;
    else
        cout << endl << "No hay coincidencias" << endl;
    return 0;
}