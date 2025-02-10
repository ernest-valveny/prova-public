#include "..\source\batalla_naval.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;



int main()
{
    EstatTauler taulerInicial[N_FILES][N_COLUMNES] = 
    {
        {ESTAT_VAIXELL, ESTAT_VAIXELL, ESTAT_VAIXELL, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA},
        {ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_VAIXELL},
        {ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_AIGUA, ESTAT_VAIXELL},
        {ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_VAIXELL, ESTAT_AIGUA, ESTAT_VAIXELL}
    };

    stringstream input;
    input.str("2 1 1 2 2 2 1 3 1 4 1 5 1 1 3 5 3 4 4 5 5 5 3 3 4 1 5 1 5 3");
    streambuf *bufferOriginal = cin.rdbuf(input.rdbuf());
    int nIntents = 20;
     EstatTauler taulerResultat[N_FILES][N_COLUMNES];

     batallaNaval(taulerInicial, nIntents, taulerResultat);

     cin.rdbuf(bufferOriginal);

	return 0;
}
