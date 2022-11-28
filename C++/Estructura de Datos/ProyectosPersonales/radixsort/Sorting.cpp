#include <Windows.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

#include "ChronoTime.h"
#include "QuickSort.h"
#include "RadixSort.h"
using namespace std;

#define EXIT 12

typedef int* (RadixSort::*RadixMethod)(bool);

int* Impl(int* arr, int length, RadixMethod rdxMethod, string title) {
    int* newArr;
    CTime chronometer;
    RadixSort rdx1(arr, length);
    cout << title << endl;
    cout << "Ordenando " << length << " numeros..." << endl;
    chronometer.chrono.Start();
    newArr = (rdx1.*rdxMethod)(false);
    chronometer.chrono.CheckCurrentTime();
    chronometer.Update();
    cout << "Ordenamiento completado en: " << chronometer << endl
         << endl;
    return newArr;
}

int GenerateArray(int*& arr) {
    if (arr != NULL) {
        delete[] arr;
    }
    int length;
    cout << "tamanio del arreglo: ";
    cin >> length;
    arr = new int[length];
    cout << "Creando arreglo..." << endl;
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % length + 1;
    }
    cout << "Arreglo creado!";
    return length;
}

void RunRadixImpls(int* arr, int length) {
    int* radixArr = NULL;
    radixArr = Impl(arr, length, &RadixSort::RadixSortLSD1, "~Radix Sort implementacion 1 ~");
    delete[] radixArr;
    radixArr = Impl(arr, length, &RadixSort::RadixSortLSD2, "~Radix Sort implementacion 2 ~");
    delete[] radixArr;
    radixArr = Impl(arr, length, &RadixSort::RadixSortLSD3, "~Radix Sort implementacion 3 ~");
    delete[] radixArr;
    radixArr = Impl(arr, length, &RadixSort::RadixSortMSD4, "~Radix Sort implementacion 4 ~");
    delete[] radixArr;
    system("pause");
}

int* Compare(int* arr, int length) {
    int* radixArr = Impl(arr, length, &RadixSort::RadixSortLSD3, "~Radix Sort implementacion 3 ~");
    delete[] radixArr;
    CTime chronometer;
    QuickSort qckAlgo(arr, length);
    chronometer.chrono.Start();
    int* quickArr = qckAlgo.quicksort(0, length - 1);
    chronometer.chrono.CheckCurrentTime();
    chronometer.Update();
    cout << "QuickSort\nOrdenamiento completado en: " << chronometer << endl
         << endl;
    return quickArr;
}

void printArray(int* arr, int length) {
    string sArr = " [";
    for (size_t i = 0; i < length; i++) {
        sArr += to_string((arr[i]));
        sArr += (i < length - 1 ? ", " : "");
    }
    sArr += "]";
    cout << sArr;
}

void MejorCaso() {
    int mejorCaso[] = {1, 4, 2, 9, 5, 7, 3, 4, 2};
    RadixSort rdx(mejorCaso, 9);
    printArray(mejorCaso, 9);
    cout << endl
         << endl;
    rdx.RadixSortLSD2(true);
}

void PeorCaso() {
    int peorCaso[] = {1098, 650, 125, 99, 90, 67, 24, 15, 2};
    RadixSort rdx(peorCaso, 9);
    printArray(peorCaso, 9);
    cout << endl
         << endl;
    rdx.RadixSortLSD2(true);
}

void MedioCaso() {
    int casoMedio[] = {70, 45, 75, 90, 80, 24, 2, 66};
    RadixSort rdx(casoMedio, 8);
    printArray(casoMedio, 8);
    cout << endl
         << endl;
    rdx.RadixSortLSD2(true);
}

void ExplanationCase() {
    int casoMedio[] = {25, 57, 48, 37, 12, 92, 86, 33};
    RadixSort rdx(casoMedio, 8);
    printArray(casoMedio, 8);
    cout << endl
         << endl;
    rdx.RadixSortLSD2(true);
}

void Print(int*& ordenedArr, int length) {
    char answer = 0;
    do {
        // system("pause");
        cout << "Quieres Imprimir el arreglo ordenado?(y/n)";
        cin >> answer;
        answer = tolower(answer);
    } while (!(answer == 'y' || answer == 'n'));
    if (answer == 'y') printArray(ordenedArr, length);
    delete[] ordenedArr;
}

void Menu() {
    int opc = 0;
    int* arr = NULL;
    int* ordenedArr = NULL;
    int length = 0;

    do {
        cout << "  ~ Radix Sort Menu ~" << endl;
        cout << "Crear Arreglo-----------1" << endl;
        cout << "Imprimir arreglo--------2" << endl;
        cout << "Mejor caso--------------3" << endl;
        cout << "peor caso---------------4" << endl;
        cout << "Caso medio--------------5" << endl;
        cout << "Implementacion 1--------6" << endl;
        cout << "Implementacion 2--------7" << endl;
        cout << "Implementacion 3--------8" << endl;
        cout << "Implementacion 4--------9" << endl;
        cout << "Comp. Radix-------------10" << endl;
        cout << "Comp. con QuickSort-----11" << endl;
        cout << "Salir-------------------" << EXIT << endl;
        cout << "Long. del arr. actual: " << length << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                length = GenerateArray(arr);
                break;
            case 2:
                printArray(arr, length);
                break;
            case 3:
                MejorCaso();
                break;
            case 4:
                PeorCaso();
                break;
            case 5:
                MedioCaso();
                break;
            case 6:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else {
                    ordenedArr = Impl(arr, length, &RadixSort::RadixSortLSD1, "~ Radix Sort implementacion 1 ~");
                    Print(ordenedArr, length);
                }
                break;
            case 7:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else {
                    ordenedArr = Impl(arr, length, &RadixSort::RadixSortLSD2, "~ Radix Sort implementacion 2 ~");
                    Print(ordenedArr, length);
                }
                break;
            case 8:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else {
                    ordenedArr = Impl(arr, length, &RadixSort::RadixSortLSD3, "~ Radix Sort implementacion 3 ~");
                    Print(ordenedArr, length);
                }
                break;
            case 9:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else {
                    ordenedArr = Impl(arr, length, &RadixSort::RadixSortMSD4, "~Radix Sort implementacion 4 ~");
                    Print(ordenedArr, length);
                }
                break;
            case 10:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else
                    RunRadixImpls(arr, length);
                break;
            case 11:
                if (arr == NULL)
                    cout << "Primero genera un arreglo!" << endl;
                else {
                    ordenedArr = Compare(arr, length);
                    Print(ordenedArr, length);
                }
                break;
            case EXIT:
                cout << "Saliendo..." << endl;
                break;
            case 13:
                ExplanationCase();
                break;
            default:
                cout << "opcion invalida.";
                break;
        }
        cin.ignore();
        cin.get();
        system("cls");
    } while (opc != EXIT);
}

int main() {
    srand(time(NULL));
    Menu();
}
