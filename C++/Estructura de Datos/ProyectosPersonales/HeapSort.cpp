// Programa en C++ para la implementación de Heap Sort
#include <iostream>
using namespace std;

// Prototipos de funciones
void heapSort(int[], int);
void printArray(int[], int);
void heapify(int[], int, int);
//this is a test
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);// Llamada de función

    cout << "El arreglo ordenado es: \n";
    printArray(arr, N);  // Llamando a la funcion imprimir, enviandole como parametro el arreglo y el tamaño
    return 0;
}  // Fin del main

void heapify(int arr[], int N, int i) {  // n es el tamaño del heap
    int largest = i;                     // Inicializar largest como raíz

    int l = 2 * i + 1;  // Izquierda = 2*i + 1

    int r = 2 * i + 2;  // Derecha = 2*i + 2

    if (l < N && arr[l] > arr[largest])  // Si el hijo izquierdo es más grande que la raíz
        largest = l;

    if (r < N && arr[r] > arr[largest])  // Si el hijo derecho es más grande que la raiz
        largest = r;

    if (largest != i) {  // Si largest(Nuestra variable entera declarada) no es raiz
        swap(arr[i], arr[largest]);

        // Amontonar recursivamente a los afectados
        // sub-arbol
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {         // Función principal para hacer heap sort
    for (int i = N / 2 - 1; i >= 0; i--)  // Construir heap (reorganizar arreglo)
        heapify(arr, N, i);

    // Uno por uno extraer un elemento
    // Desde el heap
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Mover la raíz actual al final

        heapify(arr, i, 0);  // llamar a max heapify en el heap reducido
    }
}

void printArray(int arr[], int N) {  // Funcion de utilidad para imprimir el arreglo de tamaño n
    for (int i = 0; i < N; ++i)
        cout << "[" << arr[i] << "]"
             << " ";
    cout << "\n";
}