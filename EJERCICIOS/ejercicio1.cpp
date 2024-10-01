/*En una tienda, se tiene un listado de productos con sus precios. 
Escribe un programa que ordene los productos de mayor a menor precio utilizando Insertion Sort.*/
#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};
void insertionsort(Producto arr[],int size){
    for(int i = 1; i < size; ++i){
        Producto key=arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].precio < key.precio) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
void printProducto(Producto arr[],int size){

    for (int i = 0; i < size; ++i) {
        cout << arr[i].nombre << "-$"<<arr[i].precio;
    }
    cout << endl;
}
int main() {
    Producto productos[] = {{"Laptop", 1200.50}, {"Smartphone", 800.99}, {"Tablet", 450.75}, {"Monitor", 299.99}};
    int n = sizeof(productos)/sizeof(productos[0]);
    insertionsort(productos, n);
    cout << "Productos ordenados por precio (de mayor a menor): \n";
    printProducto(productos, n);
    return 0;
}