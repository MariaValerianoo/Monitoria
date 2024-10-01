#include <iostream>
#include <vector>
#include <cmath>  // Para sqrt
#include <iomanip> // Para setprecision

using namespace std;

// Estructura Punto
struct Punto {
    int x, y;
    double distancia;

    // Constructor que calcula la distancia desde el punto (a, b)
    Punto(int x_val, int y_val, int a, int b) x(x_val), y(y_val) {
        distancia = calcularDistancia(a, b);
    }

    // Función para calcular la distancia desde el punto (a, b)
    double calcularDistancia(int a, int b) const {
        return sqrt(pow(x - a, 2) + pow(y - b, 2));
    }

    // Función para imprimir los datos del punto
    void imprimir() const {
        cout << x << "\t" << y << "\t" << fixed << setprecision(6) << distancia << endl;
    }
};

// Función merge para unir dos mitades ordenadas
void merge(vector<Punto*> puntos, int inicio, int mitad, int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad;

    // Crear arreglos temporales para las dos mitades
    vector<Punto> izquierda(n1), derecha(n2);

    // Copiar los datos a los arreglos temporales
    for (int i = 0; i < n1; i++) izquierda[i] = puntos[inicio + i];
    for (int i = 0; i < n2; i++) derecha[i] = puntos[mitad + 1 + i];

    // Mezclar las dos mitades
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (izquierda[i].distancia >= derecha[j].distancia) {
            puntos[k] = izquierda[i];
            i++;
        } else {
            puntos[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes si los hay
    while (i < n1) {
        puntos[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        puntos[k] = derecha[j];
        j++;
        k++;
    }
}
/*
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

*/

// Función mergeSort para ordenar los puntos por distancia
void mergeSort(vector<Punto>& puntos, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        mergeSort(puntos, inicio, mitad);
        mergeSort(puntos, mitad + 1, fin);
        merge(puntos, inicio, mitad, fin);
    }
}

int main() {
    int a = 12, b = 6; // Punto de referencia (12,6)

    // Crear un conjunto de puntos bidimensionales
    vector<Punto> puntos = {
        Punto(1, 6, a, b),
        Punto(6, 1, a, b),
        Punto(9, 13, a, b),
        Punto(14, 13, a, b),
        Punto(6, 2, a, b),
        Punto(11, 13, a, b),
        Punto(14, 12, a, b),
        Punto(6, 6, a, b),
        Punto(14, 2, a, b),
        Punto(8, 5, a, b),
        Punto(9, 6, a, b),
        Punto(10, 7, a, b),
        Punto(12, 8, a, b),
        Punto(14, 6, a, b),
        Punto(12, 7, a, b)
    };

    // Imprimir los puntos originales
    cout << "Puntos originales:\n";
    cout << "X\tY\tDistancia\n";
    for (const auto& punto : puntos) {
        punto.imprimir();
    }

    // Ordenar los puntos por la distancia al punto (a, b) de mayor a menor
    mergeSort(puntos, 0, puntos.size() - 1);

    // Imprimir los puntos ordenados
    cout << "\nPuntos ordenados por distancia (de mayor a menor):\n";
    cout << "X\tY\tDistancia\n";
    for (const auto& punto : puntos) {
        punto.imprimir();
    }

    return 0;
}
