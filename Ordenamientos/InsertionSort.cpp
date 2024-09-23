#include <iostream>
using namespace std;


/* El Insertion Sort o Ordenamiento por Inserción, divide el conjunto de elementos en una parte ordenada y otra desordenada. 
Toma un elemento de la parte desordenada y lo inserta en la posición correcta en la parte ordenada. 
Repite este proceso hasta que todos los elementos estén ordenados.*/
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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

    insertionSort(arr, size);

    cout << "Lista ordenada: ";
    printArray(arr, size);

    return 0;
}