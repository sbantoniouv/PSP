#include <iostream>
using namespace std;

int main() {
    double ladoA, ladoB, area;

    cout << "Ingrese el valor del lado A: ";
    cin >> ladoA;
    cout << "Ingrese el valor del lado B: ";
    cin >> ladoB;

    if (ladoA == 0 || ladoB == 0) {
        cout << "Ninguno de los valores puede ser 0" << endl;
    } else {
        area = ladoA * ladoB;
        if (ladoA == ladoB) {
            cout << "El resultado del área es: " << area << " y es un cuadrado" << endl;
        } else {
            cout << "El resultado del área es: " << area << endl;
        }
    }

    return 0;
}
