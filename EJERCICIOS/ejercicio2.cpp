/*Escribe un programa que organice una lista de tareas en función de su fecha límite (días restantes). 
Utiliza el algoritmo Selection Sort para ordenar las tareas de forma ascendente (de la tarea con menos días 
restantes a la de más días).
*/


#include <iostream>
#include <string>
using namespace std;

struct Tarea {
    string descripcion;
    int diasRestantes;
};




















void selectionSort(Tarea arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].diasRestantes < arr[min_idx].diasRestantes) {
                min_idx = j;
            }
        }
        // Intercambiar la tarea con menos días restantes
        Tarea temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printTareas(Tarea arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].descripcion << " - " << arr[i].diasRestantes << " días restantes" << endl;
    }
}

int main() {
    Tarea tareas[] = {{"Hacer el reporte", 5}, {"Estudiar para el examen", 2}, {"Comprar materiales", 7}, {"Preparar la presentación", 3}};
    int n = sizeof(tareas)/sizeof(tareas[0]);
    selectionSort(tareas, n);
    cout << "Tareas organizadas por fecha límite: \n";
    printTareas(tareas, n);
    return 0;
}