#include "batalla_naval.h"
#include <iostream>

using namespace std;

void inicialitzaResultat(EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    for (int i = 0; i < N_FILES; i++)
    {
        for (int j = 0; j < N_COLUMNES; j++)
        {
            taulerResultat[i][j] = ESTAT_NUL;
        }
    }
}

void mostraResultat(EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    for (int i = 0; i < N_FILES; i++)
    {
        for (int j = 0; j < N_COLUMNES; j++)
        {
            switch (taulerResultat[i][j])
            {
            case ESTAT_NUL:
                cout << "-";
                break;
            case ESTAT_AIGUA:
                cout << "X";
                break;
            case ESTAT_TOCAT:
                cout << "T";
                break;
            case ESTAT_ENFONSAT:
                cout << "E";
                break;
            }
        }
        cout << endl;
    }
}

bool comprovaEnfonsat(EstatTauler taulerInicial[N_FILES][N_COLUMNES], int fila, int columna, Direccio& direccioVaixell, int& posInicial, int& posFinal)
{
    bool enfonsat = true;
    int i = columna;
    bool tocat = true;
    while ((tocat) && (enfonsat) && (i >= 0))
    {
        if (taulerInicial[fila][i] == ESTAT_VAIXELL)
            enfonsat = false;
        else if (taulerInicial[fila][i] == ESTAT_AIGUA)
            tocat = false;
        else
            i--;
    }
    if (enfonsat)
    {
        posInicial = i + 1;
        i = columna;
        tocat = true;
        while ((tocat) && (enfonsat) && (i < N_COLUMNES))
        {
            if (taulerInicial[fila][i] == ESTAT_VAIXELL)
                enfonsat = false;
            else if (taulerInicial[fila][i] == ESTAT_AIGUA)
                tocat = false;
            else
                i++;
        }
        if (enfonsat)
        {
            posFinal = i - 1;
            if (posFinal - posInicial > 0)
                direccioVaixell = HORIZONTAL;
            else
            {
                int i = fila;
                tocat = true;
                while ((tocat) && (enfonsat) && (i >= 0))
                {
                    if (taulerInicial[i][columna] == ESTAT_VAIXELL)
                        enfonsat = false;
                    else if (taulerInicial[i][columna] == ESTAT_AIGUA)
                        tocat = false;
                    else
                        i--;
                }
                if (enfonsat)
                {
                    posInicial = i + 1;
                    i = fila;
                    tocat = true;
                    while ((tocat) && (enfonsat) && (i < N_FILES ))                    {
                        if (taulerInicial[i][columna] == ESTAT_VAIXELL)
                            enfonsat = false;
                        else if (taulerInicial[i][columna] == ESTAT_AIGUA)
                            tocat = false;
                        else
                            i++;
                    }
                    if (enfonsat)
                    {
                        posFinal = i - 1;
                        direccioVaixell = VERTICAL;
                    }
                }
            }
        }
    }
    return enfonsat;
}

void marcaEnfonsatInicial(EstatTauler taulerInicial[N_FILES][N_COLUMNES], Direccio direccioVaixell, int fila, int columna, int posInicial, int posFinal)
{
    if (direccioVaixell == HORIZONTAL)
    {
        for (int i = posInicial; i <= posFinal; i++)
        {
            taulerInicial[fila][i] = ESTAT_ENFONSAT;
        }
    }
    else
    {
        for (int i = posInicial; i <= posFinal; i++)
        {
            taulerInicial[i][columna] = ESTAT_ENFONSAT;
        }
    }
}


void marcaEnfonsatResultat(EstatTauler taulerResultat[N_FILES][N_COLUMNES], Direccio direccioVaixell, int fila, int columna, int posInicial, int posFinal)
{
    if (direccioVaixell == HORIZONTAL)
    {
        if (posInicial > 0)
        {
            taulerResultat[fila][posInicial - 1] = ESTAT_AIGUA; 
            if (fila > 0)
                taulerResultat[fila - 1][posInicial - 1] = ESTAT_AIGUA;
            if (fila < N_FILES - 1)
                taulerResultat[fila + 1][posInicial - 1] = ESTAT_AIGUA;
        }
        for (int i = posInicial; i <= posFinal; i++)
        {
            taulerResultat[fila][i] = ESTAT_ENFONSAT;
            if (fila > 0)
                taulerResultat[fila - 1][i] = ESTAT_AIGUA;
            if (fila < (N_FILES - 1))
                taulerResultat[fila + 1][i] = ESTAT_AIGUA;
        }
        if (posFinal < (N_FILES - 1))
        {
            taulerResultat[fila][posFinal + 1] = ESTAT_AIGUA;
            if (fila > 0)
                taulerResultat[fila - 1][posFinal + 1] = ESTAT_AIGUA;
            if (fila < N_FILES - 1)
                taulerResultat[fila + 1][posFinal + 1] = ESTAT_AIGUA;
        }
    }
    else
    {
        if (posInicial > 0)
        {
            taulerResultat[posInicial - 1][columna] = ESTAT_AIGUA; 
            if (columna > 0)
                taulerResultat[posInicial - 1][columna - 1] = ESTAT_AIGUA;
            if (columna < N_COLUMNES - 1)
                taulerResultat[posInicial - 1][columna + 1] = ESTAT_AIGUA;
        }
        for (int i = posInicial; i <= posFinal; i++)
        {
            taulerResultat[i][columna] = ESTAT_ENFONSAT;
            if (columna > 0)
                taulerResultat[i][columna - 1] = ESTAT_AIGUA;
            if (columna < (N_COLUMNES - 1))
                taulerResultat[i][columna + 1] = ESTAT_AIGUA;
        }
        if (posFinal < (N_COLUMNES - 1))
        {
            taulerResultat[posFinal + 1][columna] = ESTAT_AIGUA;
            if (columna > 0)
                taulerResultat[posFinal + 1][columna - 1] = ESTAT_AIGUA;
            if (columna < N_COLUMNES - 1)
                taulerResultat[posFinal + 1][columna + 1] = ESTAT_AIGUA;
        }
    }
}

void actualitzaPosicio(EstatTauler taulerInicial[N_FILES][N_COLUMNES], int fila, int columna, EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    if (taulerResultat[fila][columna] == ESTAT_NUL)
    {
        switch (taulerInicial[fila][columna])
        {
        case ESTAT_AIGUA:
            taulerResultat[fila][columna] = ESTAT_AIGUA;
            break;
        case ESTAT_VAIXELL:
            taulerInicial[fila][columna] = ESTAT_TOCAT;
            taulerResultat[fila][columna] = ESTAT_TOCAT;
            Direccio direccioVaixell;
            int posInicial, posFinal;
            bool enfonsat = comprovaEnfonsat(taulerInicial, fila, columna, direccioVaixell, posInicial, posFinal);
            if (enfonsat)
            {
                marcaEnfonsatInicial(taulerInicial, direccioVaixell, fila, columna, posInicial, posFinal);
                marcaEnfonsatResultat(taulerResultat, direccioVaixell, fila, columna, posInicial, posFinal);
            }

            break;
        }
    }
}

bool comprovaFinal(EstatTauler taulerInicial[N_FILES][N_COLUMNES])
{
    bool final = true;
    int i = 0;
    while ((i < N_FILES) && final)
    {
        int j = 0;
        while ((j < N_COLUMNES) && final)
        {
            if ((taulerInicial[i][j] == ESTAT_VAIXELL) || (taulerInicial[i][j] == ESTAT_TOCAT))
                final = false;
            j++;
        }
        i++;
    }
    return final;
}

bool batallaNaval(EstatTauler taulerInicial[N_FILES][N_COLUMNES], int nIntents, EstatTauler taulerResultat[N_FILES][N_COLUMNES])
{
    inicialitzaResultat(taulerResultat);
    bool final = false;
    do
    {
        int fila, columna;

        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        actualitzaPosicio(taulerInicial, fila - 1, columna - 1, taulerResultat);
        mostraResultat(taulerResultat);
        final = comprovaFinal(taulerInicial);
        nIntents--;
    } while ((!final) && (nIntents > 0));
    return final;
}

