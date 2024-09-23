/*
La búsqueda por interpolación es una variante de la búsqueda binaria que funciona mejor
cuando los datos están uniformemente distribuidos. En lugar de dividir uniformemente el
espacio de búsqueda, como en la búsqueda binaria, la búsqueda por interpolación hace una
estimación inteligente de la posición del elemento basada en su valor.
Algoritmo básico de búsqueda por interpolación:
• Calcula la posición estimada del elemento utilizando una función de interpolación.
• Compara el valor en la posición estimada con el valor buscado.
• Si son iguales, se ha encontrado el elemento.
• Si el valor buscado es menor que el valor en la posición estimada busca en la parte
izquierda del espacio de búsqueda.
• Si el valor buscado es mayor que el valor en la posición estimada busca en la parte
derecha del espacio de búsqueda.
*/
#include <iostream>
#include <vector>
using namespace std;
// Función de búsqueda por interpolación
int interpolationSearch(const vector<int>& arr, int key) {
 int low = 0;
 int high = arr.size() - 1;
 while (low <= high && key >= arr[low] && key <= arr[high]) {
 int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
 if (arr[pos] == key) {
 return pos;
 }
 if (arr[pos] < key) {
 low = pos + 1;
 } else {
 high = pos - 1;
 }
 }
 return -1; // Elemento no encontrado
}
int main() {
 vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
 int key = 14;
 int index = interpolationSearch(arr, key);
 if (index != -1) {
 cout << "Elemento encontrado en la posición: " << index << endl;
 } else {
 cout << "Elemento no encontrado." << endl;
 }
 return 0;
}