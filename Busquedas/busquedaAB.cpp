/*La búsqueda por árbol binario se basa en una estructura de datos llamada árbol binario de
búsqueda (BST, por sus siglas en inglés). En un BST, cada nodo tiene hasta dos hijos: uno
izquierdo y uno derecho. Los nodos en el subárbol izquierdo tienen valores menores que el
nodo raíz, y los nodos en el subárbol derecho tienen valores mayores que el nodo raíz. Esto
permite una búsqueda eficiente, ya que en cada comparación se puede reducir a la mitad el
espacio de búsqueda.
Algoritmo básico de búsqueda en un árbol binario de búsqueda:
• Comienza en la raíz del árbol.
• Si el elemento buscado es igual al valor en el nodo actual, se ha encontrado.
• Si el elemento es menor que el valor en el nodo actual, buscar en el subárbol izquierdo.
• Si el elemento es mayor que el valor en el nodo actual, buscar en el subárbol derecho.
*/

#include <iostream>
using namespace std;
// Definición de la estructura de un nodo del árbol binario
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
// Función para buscar un elemento en un árbol binario de búsqueda
Node* search(Node* root, int key) {
 if (root == nullptr || root->data == key) {
 return root;
 }
 if (root->data < key) {
 return search(root->right, key);
 }
 return search(root->left, key);
}
int main() {
 // Construcción del árbol binario de búsqueda
 Node* root = new Node(10);
 root->left = new Node(5);
 root->right = new Node(15);
 root->left->left = new Node(3);
 root->left->right = new Node(7);

 int target = 7;
 Node* result = search(root, target);

 if (result != nullptr) {
 cout << "Elemento encontrado en el árbol." << endl;
 } else {
 cout << "Elemento no encontrado en el árbol." << endl;
 }
 return 0;
}
