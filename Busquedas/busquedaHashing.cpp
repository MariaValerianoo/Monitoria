/*
La búsqueda por hashing utiliza una función de hash para mapear claves (por ejemplo, valores)
a ubicaciones en una tabla de hash. La función de hash calcula una ubicación en la tabla de
hash para cada clave, lo que permite un acceso rápido a los datos. Cuando necesitas buscar
un elemento, aplicas la función de hash a la clave y obtienes la ubicación en la tabla donde
podría estar el elemento.
Algoritmo básico de búsqueda por hashing:
• Aplica la función de hash a la clave.
• Busca la ubicación obtenida en la tabla de hash.
• Si hay colisiones (es decir, dos claves tienen el mismo valor hash y se asignan a la
misma ubicación), generalmente se utiliza una técnica de resolución de colisiones,
como encadenamiento o sondaje lineal, para manejarlas.*/

#include <iostream>
using namespace std;
int main() {
 unordered_map<int, string> hashTable;
 // Insertar elementos en la tabla hash
 hashTable[1] = "Alice";
 hashTable[2] = "Bob";
 hashTable[3] = "Charlie";
 int targetKey = 2;
 // Buscar un elemento en la tabla hash
 auto it = hashTable.find(targetKey);
 if (it != hashTable.end()) {
 cout << "Elemento encontrado en la tabla hash: " << it->second << endl;
 } else {
 cout << "Elemento no encontrado en la tabla hash." << endl;
 }
 return 0;
}