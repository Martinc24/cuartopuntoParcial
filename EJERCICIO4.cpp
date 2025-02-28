#include <iostream>
#include <cmath>

using namespace std;

// Definir la estructura de un punto en 2D
struct Point {
    double x, y;
};

// Función para calcular la distancia entre dos puntos (usando referencias constantes)
double calcularDistancia(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n) {
    char respuesta;
    cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    cin >> respuesta;
    
    if (respuesta == 's' || respuesta == 'S') {
        for (int i = 0; i < n; i++) {
            cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        // Usar puntos predeterminados
        cout << "Usando puntos predeterminados...\n";
        for (int i = 0; i < n; i++) {
            puntos[i] = {i * 3.0, i * 4.0}; // Ejemplo de inicialización
        }
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point& pUsuario, int& indiceMasCercano) {
    double distanciaMinima = calcularDistancia(pUsuario, puntos[0]);
    indiceMasCercano = 0;
    
    for (int i = 1; i < n; i++) {
        double distancia = calcularDistancia(pUsuario, puntos[i]);
        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// Función para mostrar el resultado
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia) {
    cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    cout << "La distancia al punto más cercano es: " << distancia << endl;
}

// Función para calcular la distancia total al recorrer los puntos en orden
double calcularDistanciaTotal(Point puntos[], int n) {
    double distanciaTotal = 0.0;
    for (int i = 0; i < n - 1; i++) {
        distanciaTotal += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return distanciaTotal;
}

int main() {
    int n;
    cout << "Ingrese el número de puntos (mínimo 2): ";
    cin >> n;
    
    if (n < 2) {
        cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n];
    leerPuntos(puntos, n);
    
    Point pUsuario;
    cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x y): ";
    cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    mostrarResultado(puntos, indiceMasCercano, distancia);

    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    cout << "La distancia total recorrida entre los puntos en orden es: " << distanciaTotal << endl;
    
    return 0;
}
