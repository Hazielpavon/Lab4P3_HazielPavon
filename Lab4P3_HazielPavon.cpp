#include <iostream>
#include <stdlib.h>
using namespace std;
void reservarMatrizEntero(int**& puntero_matriz, int n) {
	puntero_matriz = new int* [n];
	for (int i = 0; i < n; i++)
	{
		puntero_matriz[i] = new int[n]; // columnas 
	}
}

void LlenarMatrizEnteros(int**& punteromat, int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ran = 1 + (rand() % 98);
			*&punteromat[i][j] = ran;

			if (j == 0) {
				cout << " " << "[" << punteromat[i][j];
			}
			else if (j == n - 1) {
				cout << punteromat[i][j] << " ]" << " ";
			}
			else {
				cout << " " << punteromat[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int calcularInversaMatematica(int**& punteromat, int n, int resp) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i) {
				resp = punteromat[i][j]; 
			}

			if (j - i == n) {
				resp = punteromat[i][j];
			}
		}
	}
	return resp; 
}


void ejercicio1() {
	int num;
	bool val = false;
	while (!val) {
		cout << "Ingrese n: ";
		num = 0;
		cin >> num;
		if (num >= 3) {
			val = true;
		}
	}
	int resp = 0;
	int** puntero_matriz;
	reservarMatrizEntero(puntero_matriz, num);
	LlenarMatrizEnteros(puntero_matriz, num);
	resp = calcularInversaMatematica(puntero_matriz, num, resp);

	cout << ""

		for (int i = 0; i < num; i++) {
			delete[] puntero_matriz[i];
		}
	delete[] puntero_matriz;
}

void ejercicio2() {

}
int main()
{
	bool seguir = true;
	while (seguir) {
		cout << "Ingrese una opcion" << endl;
		cout << "1. Ejercicio 1" << endl;
		cout << "2. Ejercicio 2" << endl;
		cout << "3. Salir" << endl;
		int op;
		cin >> op;

		switch (op) {
		case 1:
			ejercicio1();
			break;

		case 2:
			ejercicio2();
			break;

		case 3:
			seguir = false;
			break;

		default:
			cout << "ingrese un dato correcto" << endl;
		}





	}
}
