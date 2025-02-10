#include <iostream>

using namespace std;

const int TAMANY = 10;

bool estaOrdenat(int v[], int nElements)
{
}

int maxim(int v[], int nElements)
{
}

int main()
{
    int v1[TAMANY] = {0,1,2,3,4,5,6,7,8,10};
	int v2[TAMANY] = { 0,1,2,3,10,5,25,7,8,10 };

    bool ordenat = estaOrdenat(v1, TAMANY);
    if (ordenat)
        cout << "Array ordenat" << endl;
    else
        cout << "Array NO ordenat" << endl;
	int m = maxim(v1, TAMANY);
	cout << "Valor maxim de l'array: " << m << endl;

	ordenat = estaOrdenat(v2, TAMANY);
	if (ordenat)
		cout << "Array ordenat" << endl;
	else
		cout << "Array NO ordenat" << endl;
	m = maxim(v2, TAMANY);
	cout << "Valor maxim de l'array: " << m << endl;

    return 0;
}
