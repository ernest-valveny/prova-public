#include <iostream>
using namespace std;

int IndexZeroArray(    )
{
}

const int LONGITUD = 10;

int main()
{
	int array1[LONGITUD] = { 1, 2, 4, 4, 5, 6, 7, 8, 9, 10 };
	int array2[LONGITUD] = { 1, 2, 4, 0, 5, 6, 7, 8, 9, 10 };

	int index = IndexZeroArray(array1, LONGITUD);
	cout << "Index: " << index << endl;

	index = IndexZeroArray(array2, LONGITUD);
	cout << "Index: " << index << endl;

	return 0;
}