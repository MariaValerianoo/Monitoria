/*La empresa Mattel les ha pedido que creen una versión digital del sistema para calcular el puntaje de su 
juego UNO-Simple. En este juego cuenta con cartas de cuatro colores y solo numéricas (0-9). 
Los puntos de un jugador se calcular con base en el valor de número, y la carta 0, que se considera una 
carta castigo y vale 20 puntos. El juego debe tener entre 3 y 6 jugadores (se debe definir al instanciar 
la clase principal del juego. En lo posible, la estructura que almacena los jugadores debería ser dinámica). 
Cada jugador tiene una estructura de datos en donde almacena las cartas que tiene (alguna estructura lineal 
vista en clase). 
El sistema reparte las cartas en una simulación de partida final a cada y uno de los jugadores. 
Uno de los jugadores tiene 0 cartas, y el resto de las cartas deben repartirse, de manera aleatoria entre 
los jugadores.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // Para generar números aleatorios
#include <ctime>    // Para inicializar la semilla de los números aleatorios

using namespace std;
















// Clase Carta
class Carta {
public:
    int numero; // Valor de la carta (0-9)
    string color; // Color de la carta ("Rojo", "Verde", "Azul", "Amarillo")

    Carta(int num, string col) : numero(num), color(col) {}

    // Método para calcular el puntaje de la carta
    int obtenerPuntaje() const {
        return (numero == 0) ? 20 : numero;
    }

    // Método para imprimir la carta
    void imprimirCarta() const {
        cout << color << " " << numero;
    }

    // Comparador para ordenar por número y luego por color
    bool operator<(const Carta& otra) const {
        if (numero == otra.numero) {
            return color < otra.color;
        }
        return numero < otra.numero;
    }
};

// Clase Jugador
class Jugador {
public:
    string nombre;
    vector<Carta> cartas; // Almacena las cartas del jugador
    int puntajeTotal;

    Jugador(string nom) : nombre(nom), puntajeTotal(0) {}

    // Método para agregar una carta al jugador
    void agregarCarta(const Carta& carta) {
        cartas.push_back(carta);
        puntajeTotal += carta.obtenerPuntaje();
    }

    // Método para imprimir las cartas del jugador
    void imprimirCartas() const {
        cout << nombre << " tiene las siguientes cartas:\n";
        for (const auto& carta : cartas) {
            carta.imprimirCarta();
            cout << ", ";
        }
        cout << endl;
    }

    // Método para imprimir el puntaje del jugador
    void imprimirPuntaje() const {
        cout << nombre << " tiene un puntaje de: " << puntajeTotal << " puntos\n";
    }

    // Función de merge para MergeSort
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Carta> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = cartas[left + i];
        for (int i = 0; i < n2; ++i)
            R[i] = cartas[mid + 1 + i];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] < R[j]) {
                cartas[k] = L[i];
                i++;
            } else {
                cartas[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            cartas[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            cartas[k] = R[j];
            j++;
            k++;
        }
    }

    // Función de MergeSort para ordenar las cartas
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    // Ordenar las cartas del jugador usando MergeSort
    void ordenarCartas() {
        mergeSort(0, cartas.size() - 1);
    }
};

// Clase JuegoUNO
class JuegoUNO {
private:
    vector<Jugador> jugadores;
    vector<string> colores = {"Rojo", "Verde", "Azul", "Amarillo"};

public:
    JuegoUNO(int numJugadores) {
        if (numJugadores < 3 || numJugadores > 6) {
            throw invalid_argument("El número de jugadores debe estar entre 3 y 6.");
        }

        // Crear los jugadores
        for (int i = 0; i < numJugadores; i++) {
            jugadores.push_back(Jugador("Jugador " + to_string(i + 1)));
        }
    }

    // Método para repartir cartas aleatoriamente
    void repartirCartas() {
        srand(time(0)); // Inicializar semilla aleatoria
        int cartasTotales = 40; // Suponemos 40 cartas totales

        // Asignar todas las cartas a los jugadores menos uno (que tendrá 0 cartas)
        for (int i = 0; i < cartasTotales; i++) {
            int jugadorIndex = rand() % jugadores.size();
            int numeroCarta = rand() % 10; // Cartas numeradas de 0 a 9
            string colorCarta = colores[rand() % 4]; // Seleccionar color aleatorio
            jugadores[jugadorIndex].agregarCarta(Carta(numeroCarta, colorCarta));
        }
    }

    // Imprimir cartas de los jugadores
    void imprimirCartasJugadores() const {
        for (const auto& jugador : jugadores) {
            jugador.imprimirCartas();
        }
    }

    // Imprimir puntajes de los jugadores
    void imprimirPuntajesJugadores() const {
        for (const auto& jugador : jugadores) {
            jugador.imprimirPuntaje();
        }
    }

    // Ordenar cartas de cada jugador usando MergeSort
    void ordenarCartasDeJugadores() {
        for (auto& jugador : jugadores) {
            jugador.ordenarCartas();
        }
    }
};


int main() {
    int numJugadores;
    cout << "Ingrese el número de jugadores (entre 3 y 6): ";
    cin >> numJugadores;

    // Verificar manualmente si el número de jugadores es válido
    if (numJugadores < 3 || numJugadores > 6) {
        cout << "Error: El número de jugadores debe estar entre 3 y 6." << endl;
        return 1; // Termina el programa con un código de error
    }

    // Crear el juego y continuar con el flujo normal
    JuegoUNO juego(numJugadores);

    // Repartir cartas a los jugadores
    juego.repartirCartas();

    // Imprimir las cartas de cada jugador
    cout << "\nCartas de los jugadores:\n";
    juego.imprimirCartasJugadores();

    // Imprimir los puntajes de cada jugador
    cout << "\nPuntajes de los jugadores:\n";
    juego.imprimirPuntajesJugadores();

    // Ordenar las cartas de cada jugador
    juego.ordenarCartasDeJugadores();
    cout << "\nCartas de los jugadores (ordenadas por número y color):\n";
    juego.imprimirCartasJugadores();

    return 0;
}

