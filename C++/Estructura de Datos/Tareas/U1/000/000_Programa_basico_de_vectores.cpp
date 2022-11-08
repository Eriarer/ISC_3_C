#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//prototipos

void llenar(int *v, int tam); //llenar vector con RNG entre 1 y 1000
void imprimir(int *v, int tam); //imprimir el vector
void ordenar (int *v, int tam); //ordenar el vector ascendendentemente

int main(){
	srand(time(NULL));
	int *v;
	int tam;
	
	cout<<endl<<"\t   <Abraham Melgoza de la Torre>"<<endl;
	cout<<endl<<"\tDe que tamano quie el vector dinamico: ";
	cin>>tam;
		
	v = new int[tam]; //vector dinamico creado
	
	llenar(v,tam);
	imprimir(v,tam);
	ordenar(v,tam);
	imprimir(v,tam);
	
	delete[] v; //elimina el espacio al vector dinamico
}

//llenar vector con RNG entre 1 y 1000
void llenar(int *v, int tam){
	cout<<endl<<"\t LLENANDO VECTOR"<<endl;
	for(int i=0; i<tam;i++){
		v[i] = rand() % 1000 + 1;
	}
}

 //imprimir el vector
void imprimir(int *v, int tam){
	cout<<endl<<"\t IMPIMIENDO VECTOR"<<endl;
	for(int i=0; i<tam;i++){
		cout<<"\t\t"<<v[i]<<endl;
	}
}
 //ordenar el vector ascendendentemente
void ordenar (int *v, int tam){
	int temp, i=1, j;
	cout<<endl<<"\t ORDENANDO VECTOR"<<endl;
	for(i; i<tam;i++){
		temp = v[i];
		j = i-1;
		while(j>=0 && v[j] > temp){
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = temp;
	}
}