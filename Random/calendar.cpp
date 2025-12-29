#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
    string month, startDay;
    int monthDay, initialPos = 0;

    cout << "Ingrese el nombre del mes: ";
    cin >> month;

    cout << "Ingrese la cantidad de dias del mes (28, 29, 30 o 31): ";
    cin >> monthDay;

    cout << "Ingrese el dia de la semana en que inicia el mes (lunes, martes, miercoles, jueves, viernes, sabado, domingo): ";
    cin >> startDay;

    if      (startDay == "lunes")     initialPos = 1;
    else if (startDay == "martes")    initialPos = 2;
    else if (startDay == "miercoles") initialPos = 3;
    else if (startDay == "jueves")    initialPos = 4;
    else if (startDay == "viernes")   initialPos = 5;
    else if (startDay == "sabado")    initialPos = 6;
    else if (startDay == "domingo")   initialPos = 7;
    else 
    {
        cout << "Dia de inicio no valido." << endl;
        return 0;
    }

    cout << "\n\t\t" << month << endl;
    cout << "----------------------------------" << endl;
    cout << setw(4) << "Lun"
         << setw(4) << "Mar"
         << setw(4) << "Mie"
         << setw(4) << "Jue"
         << setw(4) << "Vie"
         << setw(4) << "Sab"
         << setw(4) << "Dom" << endl;

    int dia = 1;

    for (int i = 1; i < initialPos; i++) 
    {
        cout << setw(4) << " ";
    }

    for (int i = initialPos; dia <= monthDay; i++) 
    {
        cout << setw(4) << dia;
        if (i % 7 == 0) cout << endl;
        dia++;
    }

    cout << endl;
    return 0;
}
