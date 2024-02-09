#include <iostream>
#include <stdlib.h>
#include <cString>
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
				resp = resp + punteromat[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {
				resp = resp + punteromat[i][j];
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
		else {
			cout << "n debe ser mayor o igual que 4." << endl;
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


// metodos del ejercicio2 
void reservarMatriz(char**& matriz, int filas, int columnas) {
	matriz = new char* [filas];
	for (int i = 0; i < filas; ++i) {
		matriz[i] = new char[columnas];
	}
}

void llenarMatriz(char** matriz, int filas, int columnas) {
	srand(time(NULL));
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			matriz[i][j] = 'a' + rand() % 26; 
			cout << "[" << matriz[i][j] << "] ";
		}
		cout << endl; 
	}
}


bool buscarPalabra(char** matriz, int filas, int columnas, string palabra) {
	// Búsqueda horizontal
	for (int i = 0; i < filas; ++i) {
		string horizontal;
		for (int j = 0; j < columnas; ++j) {
			horizontal += matriz[i][j];
		}
		if (horizontal == palabra) {
			return true;
		}
	}

	// Búsqueda vertical
	for (int j = 0; j < columnas; ++j) {
		string vertical;
		for (int i = 0; i < filas; ++i) {
			vertical += matriz[i][j];
		}
		if (vertical == palabra) {
			return true;
		}
	}

	return false;
}

void ejercicio2() {
	int filas, columnas;
	bool vali = false;
	while (!vali) {
		cout << "Ingrese el numero de filas: ";
		cin >> filas;
		cout << "Ingrese el numero de columnas: ";
		cin >> columnas;

		if (filas >= 4 && columnas >= 4) {
			vali = true;
		}
		else {
			cout << "El numero de filas y columnas debe ser mayor o igual que 4." << endl;
		}
	}
	char** matriz;
	reservarMatriz(matriz, filas, columnas);
	cout << "Matriz generada:" << endl;
	llenarMatriz(matriz, filas, columnas);

	string palabra;
	cout << "Ingrese la palabra que desea buscar: ";
	cin >> palabra;
	if (buscarPalabra(matriz, filas, columnas, palabra)) {
		cout << "La palabra se encontró en la sopa de letras." << endl;
	}
	else {
		cout << "La palabra no se encontró en la sopa de letras." << endl;
	}
	for (int i = 0; i < filas; ++i) {
		delete[] matriz[i];
	}
	delete[] matriz;
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
