#include <iostream>
using namespace std;



/*  
Selection Sort o Ordenamiento por Selección, busca el elemento más pequeño en el conjunto de elementos y
lo coloca en la posición correcta. Luego, busca el siguiente elemento más pequeño y lo coloca en la 
siguiente posición correcta. Repite este proceso hasta que todos los elementos estén ordenados.
*/
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr, size);

    cout << "Lista ordenada: ";
    printArray(arr, size);

    return 0;
}