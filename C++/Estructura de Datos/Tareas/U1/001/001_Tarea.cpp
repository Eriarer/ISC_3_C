#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void imprimir(int *vec, int tam);
void llenar(int *vec, int tam);
void ordenar(int *vec, int tam);

int main(){
	srand(time(0));
	cout << endl << "\t\t<Abraham Melgoza de la Torre>" << endl;
	int num, res, tam, cont=0;
 	int *vec;
	bool band;

	tam = rand() % 7 + 6; //genera lo que sera el tamaño del vector dinamico
	
	cout << endl << "\tTamano del vector: " << tam << endl;
	vec = new int[tam]; // Se genera el vector de X tamaño
	llenar(vec,tam); //se llena el vector con ceros
	cout<<endl;
	
	do{
	 	cout << endl << "\tIngrese un numero entero: ";
		cin >> num;
		fflush (stdin);
		vec[cont] = num;
		cout << "\t\tANADIENDO AL VECTOR" << endl;
		imprimir(vec, tam);
		cout << endl <<"\t\tORDENANDO" << endl;
		ordenar(vec, tam);
		cout << endl << "\t\tORDENADO\n\n\t\tIMPRIMIENDO" << endl;
		imprimir(vec, tam);
		if(cont >= tam-1){
			cout << "EL VECTOR ESTA LLENO" << endl << endl;
			system("pause");
			break;
		} 
		cout << endl << "\t\tSeguir ingresando numeros\n\t\t1(si)\t2(no)\n\t\tSeleccion: ";
		cin>>res;
		fflush (stdin);
		cont++; 
	}while(res == 1);
	
	return 0;
}

void imprimir(int *vec, int tam){
	cout << endl;
	for(int i=0;i<tam;i++){
		cout << " [ " << vec[i] << " ]";
	}
	cout << endl;
}

void llenar(int *vec, int tam){
	for(int i=0; i<tam; i++){
		vec[i] = 0;
	}
}

void ordenar(int *vec, int tam){
	int i=0, j=0, temp=0;
	for(j=0 ;j<tam; j++){
		for(i=0; i<=tam; i++){
			if(vec[i]==0 || vec[i+1]==0){
				break;
			}else{
				if(i+1 > tam){
					if(vec[i-1]>=vec[i]){
					temp = vec[i-1];
					vec[i-1] = vec[i];
					vec[i] = temp;
					}
				}else{
					if(vec[i]>=vec[i+1]){
					temp = vec[i+1];
					vec[i+1] = vec[i];
					vec[i] = temp;
					}
				}
			}
		}
	}
}