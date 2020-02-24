#include <fstream>
#include <iostream>
#include "windows.h"
#include <iomanip>

using namespace std;

void userinfo();
void line();
void outmatr(int** a, int n, int m);
void outincf(int** a, int** b, int n, int m);
void outsumf(int** a, int** b, int n, int m);
void outincs(int** a, int** b, int n, int m);
void outsums(int** a, int** b, int n, int m);
void powhighpoint(int** a, int n);
void fourthtask(int** a, int n);
void halfpow(int** a, int n, int m);

int main()
{
	SetConsoleOutputCP(1251);
	userinfo();
}

void userinfo() {
	int info = 3;
	while (info != 0) {
		cout << "Оберіть частину завдання між 1 та 2. Щоб вийти напишіть 0. : "; cin >> info;

		if (info == 1) {
			system("cls");
			ifstream in("not_orient.txt");
			if (in.is_open()) {
				int count = 0, temp, count_space = 0;
				char symb;
				while (!in.eof()) {
					in >> temp;

					count++;
				}
				in.seekg(0, ios::beg);
				in.clear();
				while (!in.eof()) {

					in.get(symb);
					if (symb == ' ') {
						count_space++;
					}
					if (symb == '\n') {
						break;
					}

				}
				in.seekg(0, ios::beg);
				in.clear();
				int l1 = count / (count_space + 1);
				int cordinates[2];
				for (int i = 0; i < 2; i++) {
					in >> cordinates[i];
				}
				for (int i = 0; i < 2; i++) {
					cout << cordinates[i] << " ";
				}
				cout << endl;
				int** pairs = new int* [l1 - 1];
				for (int i = 0; i < l1 - 1; i++) {
					pairs[i] = new int[2];
				}
				for (int i = 0; i < l1 - 1; i++) {
					for (int j = 0; j < 2; j++) {
						in >> pairs[i][j];
					}
				}
				for (int i = 0; i < l1 - 1; i++) {
					for (int j = 0; j < 2; j++) {
						cout << pairs[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				int** matrinc = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					matrinc[i] = new int[cordinates[1]];
				}
				int** matrsum = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					matrsum[i] = new int[cordinates[0]];
				}
				outsumf(matrsum, pairs, cordinates[0], cordinates[1]);
				outincf(matrinc, pairs, cordinates[0], cordinates[1]);
				powhighpoint(matrsum, cordinates[0]);
				fourthtask(matrsum, cordinates[0]);
			}
			
			
			
		}
		if (info == 2) {
			system("cls");
			ifstream in("not_orient.txt");
			if (in.is_open()) {
				int count = 0, temp, count_space = 0;
				char symb;
				while (!in.eof()) {
					in >> temp;

					count++;
				}
				in.seekg(0, ios::beg);
				in.clear();
				while (!in.eof()) {

					in.get(symb);
					if (symb == ' ') {
						count_space++;
					}
					if (symb == '\n') {
						break;
					}

				}
				in.seekg(0, ios::beg);
				in.clear();
				int l1 = count / (count_space + 1);
				int cordinates[2];
				for (int i = 0; i < 2; i++) {
					in >> cordinates[i];
				}
				for (int i = 0; i < 2; i++) {
					cout << cordinates[i] << " ";
				}
				cout << endl;
				int** pairs = new int* [l1 - 1];
				for (int i = 0; i < l1 - 1; i++) {
					pairs[i] = new int[2];
				}
				for (int i = 0; i < l1 - 1; i++) {
					for (int j = 0; j < 2; j++) {
						in >> pairs[i][j];
					}
				}
				for (int i = 0; i < l1 - 1; i++) {
					for (int j = 0; j < 2; j++) {
						cout << pairs[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				int** matrinc = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					matrinc[i] = new int[cordinates[1]];
				}
				int** matrsum = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					matrsum[i] = new int[cordinates[0]];
				}
				outsums(matrsum, pairs, cordinates[0], cordinates[1]);
				outincs(matrinc, pairs, cordinates[0], cordinates[1]);
				halfpow(matrinc, cordinates[0], cordinates[1]);
			}
		}
		

	}
	if (info == 0) {
		system("cls");
		cout << "Дякую за увагу! Допобачення!" << endl;
		exit;
	}

}

void outmatr(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
}

void line() {
	int q = 0;
	while (q != 27) {
		cout << "=";
		q++;
	}
	cout << endl;
}


void outincf(int** a, int** b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
			a[b[j][0] - 1][j] = 1;
			a[b[j][1] - 1][j] = 1;
		}

	}
	cout << "Матриця інцидентності: " << endl;
	outmatr(a, n, m);
	line();
}

void outincs(int** a, int** b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
			if (b[j][0] == b[j][1]) {
				a[b[j][0] - 1][j] = 2;
			}
			else {
				a[b[j][0] - 1][j] = -1;
				a[b[j][1] - 1][j] = 1;
			}
		}

	}
	cout << "Матриця інцидентності: " << endl;
	outmatr(a, n, m);
	line();
}

void outsumf(int** a, int** b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
			for (int k = 0; k < m; k++) {

				a[b[k][0] - 1][b[k][1] - 1] = 1;
				a[b[k][1] - 1][b[k][0] - 1] = 1;
			}
		}
	}

	cout << "Матриця суміжності: " << endl;
	outmatr(a, n, n);
	line();
}

void outsums(int** a, int** b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
			for (int k = 0; k < m; k++) {

				a[b[k][0] - 1][b[k][1] - 1] = 1;
			}
		}
	}

	cout << "Матриця суміжності: " << endl;
	outmatr(a, n, n);
	line();
}


void powhighpoint(int** a, int n) {
	int* c = new int[n];
	for (int i = 0; i < n; i++) {
		int q = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				q++;
			}
			else {}
		}
		c[i] = q;
		cout << "Степінь вершини №" << i + 1 << ": " << q << "." << endl;
		q = 0;
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (c[0] != c[i]) {
			l++;
		}
	}
	if (l == 0) {
		cout << "Граф є однорідним. Степінь однорідності: " << c[0] << endl;
	}

	line();
}

void fourthtask(int** a, int n) {
	int v = 0, iz = 0;
	for (int i = 0; i < n; i++) {
		int q = 0;

		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				q++;
			}
			else {}
		}
		if (q == 1) {
			cout << "Вершина №" << i + 1 << " є висячою." << endl;
			v++;
		}
		if (q == 0) {
			cout << "Вершина №" << i + 1 << " є ізольованою." << endl;
			iz++;
		}
		q = 0;
	}
	if (v == 0 && iz > 0) {
		cout << "Немає висячих вершин." << endl;
	}
	if (iz == 0 && v > 0) {
		cout << "Немає ізольованих вершин." << endl;
	}
	if (v == 0 && iz == 0) {
		cout << "Немає висячих та ізольованих вершин." << endl;
	}
	line();
}

void halfpow(int** a, int n, int m) {
	int za = 0, v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				za++;
			}
			if (a[i][j] == -1) {
				v++;
			}
			if (a[i][j] == 2) {
				v++;
				za++;
			}
		}
	}
	cout << "Напівстепені виходу: " << v << " та заходу: " << za << endl;
	line();
}



