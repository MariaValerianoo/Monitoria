/*Solo funciona en arreglos ordenados. Divide repetidamente el arreglo por la mitad y compara
el valor medio con el elemento buscado.*/
#include <iostream>
#include <vector>
using namespace std;
bool binarySearch(const std::vector<int>& array, int target) {
 int left = 0;
 int right = array.size() - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (array[mid] == target) {
 return true; // Elemento encontrado
 }
 if (array[mid] < target) {
 left = mid + 1;
 } else {
 right = mid - 1;
 }
 }
 return false; // Elemento no encontrado
}
int main() {
 vector<int> numbers = {1, 2, 3, 4, 5};
 int target = 3;
 if (binarySearch(numbers, target)) {
 cout << "El elemento " << target << " está en el arreglo." << std::endl;
 } else {
 cout << "El elemento " << target << " no está en el arreglo." << std::endl;
 }
 return 0;
}
