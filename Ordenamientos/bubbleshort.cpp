#include <iostream>
using namespace std;
/* El bubble sort o Ordenamiento de Burbuja, compara pares de elementos 
adyacentes y los intercambia si están en el orden incorrecto. 
Repite este proceso hasta que todos los elementos estén ordenados.*/
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar los elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {54, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Lista original: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Lista ordenada: ";
    printArray(arr, size);

    return 0;
}