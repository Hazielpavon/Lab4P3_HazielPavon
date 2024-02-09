#include <iostream>
#include <stdlib.h>
using namespace std;
void reservarMatrizEntero(int**& puntero_matriz, int n) {
	puntero_matriz = new int* [n]; // filas
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
				cout << punteromat[i][j] << "]";
			}
			else {
				cout << " " << punteromat[i][j] << " ";
			}
		}
		cout << endl;
	}
	// aca lleno la matriz y de paso la imprimo 
}
int calcularInversaMatematica(int**& punteromat, int n) {
	int resp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				resp += punteromat[i][j];
			}
		}
	}
	for (int p = 0; p < n; p++) {
		for (int l = 0; l < n; l++) {
			if (p + l == n - 1) {
				resp += punteromat[p][l];
			}
		}
	}

	return resp;
// hago los calculos necesarios 
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

	int** puntero_matriz;
	reservarMatrizEntero(puntero_matriz, num);
	LlenarMatrizEnteros(puntero_matriz, num);
	// consigue cada dato 
	cout << "La suma de la diagonal regular y la inversa es: " << calcularInversaMatematica(puntero_matriz, num) << endl;
	for (int i = 0; i < num; i++) {
		delete[] puntero_matriz[i];
	}
	delete[] puntero_matriz;
	// liberando memoria
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
