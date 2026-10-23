#include <iostream>
using namespace std;

int main() {
    double ladoA, ladoB, ladoC;

    cout << "Ingrese el valor de A: ";
    cin >> ladoA;
    cout << "Ingrese el valor de B: ";
    cin >> ladoB;
    cout << "Ingrese el valor de C: ";
    cin >> ladoC;

    if (ladoA == 0 && ladoB == 0 && ladoC == 0) {
        cout << "Los valores no indican figura" << endl;
    } else if (ladoA != 0 && ladoB == 0 && ladoC == 0) {
        cout << "La figura es un círculo" << endl;
    } else if (ladoA != 0 && ladoB != 0 && ladoC == 0) {
        if (ladoA == ladoB) {
            cout << "La figura es un cuadrado" << endl;
        } else {
            cout << "La figura es un rectángulo" << endl;
        }
    } else if (ladoA != 0 && ladoB != 0 && ladoC != 0) {
        // Primero se valida el triangulo, despues se clasifica
        if (ladoA < ladoB + ladoC && ladoB < ladoA + ladoC && ladoC < ladoA + ladoB) {
            if (ladoA == ladoB && ladoB == ladoC) {
                cout << "La figura es un triángulo equilátero" << endl;
            } else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
                cout << "La figura es un triángulo isósceles" << endl;
            } else {
                cout << "La figura es un triángulo escaleno" << endl;
            }
        } else {
            cout << "Los valores no indican figura" << endl;
        }
    } else {
        cout << "Los valores no indican figura" << endl;
    }

    return 0;
}
