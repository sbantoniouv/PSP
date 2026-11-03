#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14;

const int OPCION_DETERMINAR = 1;
const int OPCION_AREA = 2;
const int OPCION_SALIR = 3;

const int FIGURA_NINGUNA = 0;
const int FIGURA_CUADRADO = 1;
const int FIGURA_RECTANGULO = 2;
const int FIGURA_CIRCULO = 3;
const int FIGURA_EQUILATERO = 4;
const int FIGURA_ESCALENO = 5;
const int FIGURA_ISOSCELES = 6;

void mostrarMenu();
void leerValores(double &ladoA, double &ladoB, double &ladoC);
bool esTriangulo(double ladoA, double ladoB, double ladoC);
int determinarFigura(double ladoA, double ladoB, double ladoC);
void mostrarFigura(int tipoFigura);
double calcularArea(int tipoFigura, double ladoA, double ladoB, double ladoC);
void mostrarArea(int tipoFigura, double area);

int main()
{
    int opcion = 0;
    int tipoFigura = FIGURA_NINGUNA;
    double ladoA = 0;
    double ladoB = 0;
    double ladoC = 0;
    double area = 0;

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
            case OPCION_DETERMINAR:
            {
                leerValores(ladoA, ladoB, ladoC);
                tipoFigura = determinarFigura(ladoA, ladoB, ladoC);
                mostrarFigura(tipoFigura);
                break;
            }
            case OPCION_AREA:
            {
                if (tipoFigura == FIGURA_NINGUNA)
                {
                    cout << "Primero deberá determinar la figura en la opción 1" << endl;
                }
                else
                {
                    area = calcularArea(tipoFigura, ladoA, ladoB, ladoC);
                    mostrarArea(tipoFigura, area);
                }
                break;
            }
            case OPCION_SALIR:
            {
                cout << "Hasta la próxima" << endl;
                break;
            }
            default:
            {
                cout << "Opción no válida" << endl;
                break;
            }
        }
    } while (opcion != OPCION_SALIR);

    return 0;
}

// Muestra el menú principal
void mostrarMenu()
{
    cout << endl;
    cout << "1. Determine figura" << endl;
    cout << "2. Calcule área" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

// Solicita los tres valores al usuario
void leerValores(double &ladoA, double &ladoB, double &ladoC)
{
    cout << "Ingrese A: ";
    cin >> ladoA;
    cout << "Ingrese B: ";
    cin >> ladoB;
    cout << "Ingrese C: ";
    cin >> ladoC;
}

// Indica si los tres valores forman un triángulo válido
bool esTriangulo(double ladoA, double ladoB, double ladoC)
{
    return (ladoA > 0) && (ladoB > 0) && (ladoC > 0)
        && (ladoA + ladoB > ladoC)
        && (ladoA + ladoC > ladoB)
        && (ladoB + ladoC > ladoA);
}

// Clasifica la figura según los valores y devuelve su código
int determinarFigura(double ladoA, double ladoB, double ladoC)
{
    int tipoFigura = FIGURA_NINGUNA;

    if ((ladoA > 0) && (ladoB == 0) && (ladoC == 0))
    {
        tipoFigura = FIGURA_CIRCULO;
    }
    else if ((ladoA > 0) && (ladoB > 0) && (ladoC == 0))
    {
        if (ladoA == ladoB)
        {
            tipoFigura = FIGURA_CUADRADO;
        }
        else
        {
            tipoFigura = FIGURA_RECTANGULO;
        }
    }
    else if (esTriangulo(ladoA, ladoB, ladoC))
    {
        if ((ladoA == ladoB) && (ladoB == ladoC))
        {
            tipoFigura = FIGURA_EQUILATERO;
        }
        else if ((ladoA == ladoB) || (ladoA == ladoC) || (ladoB == ladoC))
        {
            tipoFigura = FIGURA_ISOSCELES;
        }
        else
        {
            tipoFigura = FIGURA_ESCALENO;
        }
    }

    return tipoFigura;
}

// Muestra el mensaje de la figura determinada
void mostrarFigura(int tipoFigura)
{
    switch (tipoFigura)
    {
        case FIGURA_CUADRADO:
        {
            cout << "La figura es un cuadrado" << endl;
            break;
        }
        case FIGURA_RECTANGULO:
        {
            cout << "La figura es un rectángulo" << endl;
            break;
        }
        case FIGURA_CIRCULO:
        {
            cout << "La figura es un círculo" << endl;
            break;
        }
        case FIGURA_EQUILATERO:
        {
            cout << "La figura es un triángulo equilátero" << endl;
            break;
        }
        case FIGURA_ESCALENO:
        {
            cout << "La figura es un triángulo escaleno" << endl;
            break;
        }
        case FIGURA_ISOSCELES:
        {
            cout << "La figura es un triángulo isósceles" << endl;
            break;
        }
        default:
        {
            cout << "Los valores no indican figura" << endl;
            break;
        }
    }
}

// Calcula el área de la figura (triángulos con la fórmula de Herón)
double calcularArea(int tipoFigura, double ladoA, double ladoB, double ladoC)
{
    double area = 0;
    double semiperimetro = 0;

    switch (tipoFigura)
    {
        case FIGURA_CUADRADO:
        {
            area = ladoA * ladoA;
            break;
        }
        case FIGURA_RECTANGULO:
        {
            area = ladoA * ladoB;
            break;
        }
        case FIGURA_CIRCULO:
        {
            area = PI * ladoA * ladoA;
            break;
        }
        default:
        {
            semiperimetro = (ladoA + ladoB + ladoC) / 2;
            area = sqrt(semiperimetro * (semiperimetro - ladoA)
                * (semiperimetro - ladoB) * (semiperimetro - ladoC));
            break;
        }
    }

    return area;
}

// Muestra el área calculada
void mostrarArea(int tipoFigura, double area)
{
    cout << fixed << setprecision(2);

    switch (tipoFigura)
    {
        case FIGURA_CUADRADO:
        {
            cout << "El área del CUADRADO es " << area << endl;
            break;
        }
        case FIGURA_RECTANGULO:
        {
            cout << "El área del RECTÁNGULO es " << area << endl;
            break;
        }
        case FIGURA_CIRCULO:
        {
            cout << "El área del CÍRCULO es " << area << endl;
            break;
        }
        case FIGURA_EQUILATERO:
        {
            cout << "El área del TRIÁNGULO EQUILÁTERO es " << area << endl;
            break;
        }
        case FIGURA_ESCALENO:
        {
            cout << "El área del TRIÁNGULO ESCALENO es " << area << endl;
            break;
        }
        case FIGURA_ISOSCELES:
        {
            cout << "El área del TRIÁNGULO ISÓSCELES es " << area << endl;
            break;
        }
    }
}
