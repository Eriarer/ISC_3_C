#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int hexdec(char cad[], int indice, int i);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    char cad[]="8F3", cad1[]="BE38";;
    int k = hexdec(cad,strlen(cad)-1,0);
    cout << "El decimal del hexadecimal " << cad << " es: " << k;
    k = hexdec(cad1,strlen(cad1)-1,0);
    cout << endl << "El decimal del hexadecimal " << cad1 << " es: " << k;
    return 0;
}

int hexdec(char cad[], int indice, int i){
    char hex[]="0123456789ABCDEF";
    int res, num;
    if(indice>=0){
        for(int j=0; j<strlen(hex); j++){
            if(cad[indice]==hex[j]){
                num=j;
                break;
            }
        }
        res = num * pow(16,i)+hexdec(cad,indice-1,i+1);
    }else
        res = 0;
    return res;
}