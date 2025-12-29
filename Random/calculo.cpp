#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// -------------------------------------------------------------
//  p(x) = sin(x/2)
//  p'(x) = 0.5 * cos(x/2)
// -------------------------------------------------------------
double track(double x) {
    return sin(x / 2.0);
}

double track_derivative(double x) {
    return 0.5 * cos(x / 2.0);
}

// Classification based on slope
string curve_state(double slope) {
    double absSlope = fabs(slope);

    if (absSlope < 0.2)
        return "RECTO";
    else if (absSlope < 0.5)
        return "CURVA SUAVE";
    else if (absSlope < 0.8)
        return "CURVA PELIGROSA";
    else
        return "CURVA MUY PELIGROSA";
}

// Speed recommendation (simple logic)
int recommended_speed(string state) {
    if (state == "RECTO") return 220;
    if (state == "CURVA SUAVE") return 160;
    if (state == "CURVA PELIGROSA") return 100;
    return 60; // MUY PELIGROSA
}

int main() {
    cout << "===== SIMULADOR DE CARRERAS (DERIVADAS) =====\n";
    cout << "Funcion de pista: p(x) = sin(x/2)\n";
    cout << "Pendiente: p'(x) = 0.5 * cos(x/2)\n\n";

    while (true) {
        double x;
        cout << "Ingresa posicion x del auto (o -999 para salir): ";
        cin >> x;

        if (x == -999) break;

        double y = track(x);
        double slope = track_derivative(x);
        string state = curve_state(slope);
        int speed = recommended_speed(state);

        cout << "\n--- Resultados ---\n";
        cout << "Altura en pista p(x): " << y << "\n";
        cout << "Pendiente p'(x): " << slope << "\n";
        cout << "Estado de la pista: " << state << "\n";
        cout << "Velocidad recomendada: " << speed << " km/h\n";
        cout << "-------------------\n\n";
    }

    cout << "Simulacion finalizada.\n";
    return 0;
}
