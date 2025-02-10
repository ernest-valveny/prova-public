#include <iostream>

using namespace std;

const int N_FILES = 9;
const int N_COLUMNES = 9;

int llegeixNumero ()
{
    int numero;

    do
    {
        cout << "Introdueix un numero entre 1 i 9: ";
        cin >> numero;
    } while ((numero < 1) || (numero > 9));
    return numero;
}

bool esValidFila(  )
{
}

bool esValidColumna( )
{
}

bool esValidQuadrat()
{
}


int main()
{
    int tauler[N_FILES][N_COLUMNES] = { {0,0,0,0,6,0,3,5,0},
                                        {6,4,0,0,0,0,0,2,0},
                                        {1,0,9,0,0,8,7,0,0},
                                        {0,0,2,9,0,7,0,0,0},
                                        {9,0,0,0,0,0,0,0,5},
                                        {0,0,0,1,0,2,8,0,0},
                                        {0,0,6,5,0,0,1,0,9},
                                        {0,2,0,0,0,0,0,7,4},
                                        {0,9,8,0,7,0,0,0,0}
                                        };

    cout << "Introdueix fila: " << endl;
    int fila = llegeixNumero();
    cout << "Introdueix columna: " << endl;
    int columna = llegeixNumero();
    cout << "Introdueix numero: " << endl;
    int numero = llegeixNumero();
    bool valid = esValidFila(tauler, fila, numero) &&
                esValidColumna(tauler, columna, numero) &&
                esValidQuadrat(tauler, fila, columna, numero);
    if (valid)
        cout << "Numero valid" << endl;
    else
        cout << "Numero NO valid" << endl;
    return 0;
}
