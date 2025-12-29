#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>

using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarAhorcado(int intentos) {
    cout << "\n -----" << endl;
    cout << " |   |" << endl;

    if (intentos <= 5)
        cout << " O   |" << endl;
    else
        cout << "     |" << endl;

    if (intentos <= 4) {
        if (intentos <= 3) {
            if (intentos <= 2)
                cout << "/|\\  |" << endl;
            else
                cout << "/|   |" << endl;
        } else {
            cout << " |   |" << endl;
        }
    } else {
        cout << "     |" << endl;
    }

    if (intentos <= 1) {
        if (intentos == 0)
            cout << "/ \\  |" << endl;
        else
            cout << "/    |" << endl;
    } else {
        cout << "     |" << endl;
    }

    cout << "     |" << endl;
    cout << "======" << endl;
}

int main() {
    string palabraSecreta = "amigos";
    string palabraMostrada = "";
    int intentos = 6;
    vector<char> letrasUsadas;

    for (int i = 0; i < palabraSecreta.length(); i++) {
        palabraMostrada += '_';
    }

    cout << "=== JUEGO DEL AHORCADO ===" << endl;
    cout << "Adivina la palabra secreta letra por letra." << endl;
    cout << "Tienes " << intentos << " intentos disponibles." << endl;

    while (intentos > 0 && palabraMostrada != palabraSecreta) {
        limpiarPantalla();
        mostrarAhorcado(intentos);

        cout << "\nPalabra: ";
        for (char c : palabraMostrada) {
            cout << c << " ";
        }
        cout << endl;

        cout << "Intentos restantes: " << intentos << endl;

        cout << "Letras usadas: ";
        for (char l : letrasUsadas) {
            cout << l << " ";
        }
        cout << endl;

        cout << "Ingresa una letra: ";
        char letra;
        cin >> letra;

        letra = tolower(letra);

        bool usada = false;
        for (char l : letrasUsadas) {
            if (l == letra) {
                usada = true;
                break;
            }
        }

        if (usada) {
            cout << "Ya usaste esa letra. Intenta otra." << endl;
            system("pause");
            continue;
        }

        letrasUsadas.push_back(letra);

        bool acierto = false;
        for (int i = 0; i < palabraSecreta.length(); i++) {
            if (palabraSecreta[i] == letra) {
                palabraMostrada[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentos--;
            cout << "Letra incorrecta." << endl;
        } else {
            cout << "Acertaste una letra." << endl;
        }

        system("pause");
    }

    limpiarPantalla();
    mostrarAhorcado(intentos);

    if (palabraMostrada == palabraSecreta) {
        cout << "\nGanaste. La palabra era: " << palabraSecreta << endl;
    } else {
        cout << "\nPerdiste. La palabra correcta era: " << palabraSecreta << endl;
    }

    cout << "\nGracias por jugar al Ahorcado." << endl;
    system("pause");
    return 0;
}
