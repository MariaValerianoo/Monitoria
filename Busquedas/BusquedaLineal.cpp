/*Recorre secuencialmente cada elemento de la estructura de datos hasta encontrar el
elemento buscado o hasta el final del conjunto de datos.
Ejemplos:*/
#include <iostream>
using namespace std;
#include <vector>
bool linearSearch(const vector<int>& array, int target) {
 for (int element : array) {
 if (element == target) {
 return true; // Elemento encontrado
 }
 }
 return false; // Elemento no encontrado
}
int main() {
 vector<int> numbers = {1, 2, 3, 4, 5};
 int target = 3;
 if (linearSearch(numbers, target)) {
 cout << "El elemento " << target << " está en el arreglo." << std::endl;
 } else {
 cout << "El elemento " << target << " no está en el arreglo." << std::endl;
 }
 return 0;
}
