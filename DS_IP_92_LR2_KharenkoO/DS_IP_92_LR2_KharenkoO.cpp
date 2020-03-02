#include <fstream>
#include <iostream>
#include "windows.h"
#include <iomanip>


using namespace std;

void userinfo();
void line();
void outmatr(int** a, int n, int m);
void outvidf(int** a, int** b, int** c, int** d, int n, int m);
int diam(int** a, int n);
int radius(int** a, int n);
void center(int** a, int n, int r);
void yarusy(int** a, int n, int b);
void outvids(int** a, int** b, int** c, int** d, int n, int m);
void outdist(int** a, int** b, int n);
void orientzv(int** a, int** b, int n);
void multi(int** a, int** b, int n);


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
				in.close();
				for (int i = 0; i < l1 - 1; i++) {
					for (int j = 0; j < 2; j++) {
						cout << pairs[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				int** vid = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					vid[i] = new int[cordinates[0]];
				}
				int** aftmult = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					aftmult[i] = new int[cordinates[0]];
				}
				int** msum = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					msum[i] = new int[cordinates[0]];
				}
				int** dist = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					dist[i] = new int[cordinates[0]];
				}
				system("pause");
				system("cls");
				outvidf(vid, pairs, aftmult, msum, cordinates[0], cordinates[1]);
				outdist(vid, dist, cordinates[0]);
				system("pause");
				system("cls");
				int max = diam(vid, cordinates[0]);
				int rad = radius(vid, cordinates[0]);
				center(vid, cordinates[0], rad);
				yarusy(vid, cordinates[0], max);
				for (int i = 0; i < cordinates[0]; i++) {
					delete[] vid[i];
					delete[] msum[i];
					delete[] aftmult[i];
					delete[] dist[i];
				}
				delete[] dist;
				delete[] vid;
				delete[] msum;
				delete[] aftmult;
				for (int i = 0; i < l1 - 1; i++) {
					delete[] pairs[i];
				}
				delete[] pairs;
			}
			
			
			
		}
		if (info == 2) {
			system("cls");
			ifstream in("orient3.txt");
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
				in.close();
				system("pause");
				system("cls");
				int** vid = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					vid[i] = new int[cordinates[0]];
				}
				int** msum = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					msum[i] = new int[cordinates[0]];
				}
				int** aftmult = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					aftmult[i] = new int[cordinates[0]];
				}
				int** dist = new int* [cordinates[0]];
				for (int i = 0; i < cordinates[0]; i++) {
					dist[i] = new int[cordinates[0]];
				}
				outvids(vid, pairs, aftmult, msum, cordinates[0], cordinates[1]);
				outdist(vid, dist, cordinates[0]);
				system("pause");
				system("cls");
				orientzv(vid, msum, cordinates[0]);
				for (int i = 0; i < cordinates[0]; i++) {
					delete[] vid[i];
					delete[] msum[i];
					delete[] aftmult[i];
					delete[] dist[i];
				}
				delete[] dist;
				delete[] vid;
				delete[] msum;
				delete[] aftmult;
				for (int i = 0; i < l1 - 1; i++) {
					delete[] pairs[i];
				}
				delete[] pairs;
			}
		}
		

	}
	if (info == 0) {
		system("cls");
		cout << "Дякую за увагу! Допобачення!" << endl;
		exit;
	}

}

void multi(int** a, int** b, int n) {
	int** sum = new int*[n];
	for (int i = 0; i < n; i++) {
		sum[i] = new int[n];
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				s += a[i][k] * b[k][j];
			}
			sum[i][j]=s;
			s = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = sum[i][j];
		}
		delete [] sum[i];
	}
	delete [] sum;
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

void outvidf(int** a, int** b, int** c, int** d, int n, int m) {
	cout << "-1 == infinity" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1;
			for (int k = 0; k < m; k++) {

				a[b[k][0] - 1][b[k][1] - 1] = 1;
				a[b[k][1] - 1][b[k][0] - 1] = 1;
			}
			if (i == j) {
				a[i][j] = 0;
				d[i][j] = 0;
				c[i][j] = 0;
			}
		}
	}
	cout << "Матриця суміжності: " << endl;
	outmatr(a, n, n);
	line();
	for (int k = 1; k < n; k++) {
		multi(c, d, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == -1 && c[i][j] != 0 && i != j && a[i][j] < k) {
					a[i][j] = k + 1;
				}
			}
		}
	}
	cout << "Матриця відстаней: " << endl;
	outmatr(a, n, n);
	line();
}

int diam(int** a, int n){
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	cout << "Діаметр графа: " << max << "." << endl;
	line();
	return max;
}

int radius(int** a, int n) {
	int min = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min && a[i][j] != 1 && a[i][j] != 0) {
				min = a[i][j];
			}
		}
	}
	cout << "Радіус графа: " << min << "." << endl;
	line();
	return min;
}

void center(int** a, int n, int r) {
	int* p = new int[n];
	int q = 0, k = 0, c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == r) {
				c = i + 1;
				p[q] = c;
				q++;
				break;
			}
		}
	}
	cout << "Центри графа: ";
	while (k < q ) {
		cout << p[k] << " ";
		k++;
	}
	cout << endl;
	line();
}

void yarusy(int** a, int n, int b) {
	int k = 1;
	while (k <= b) {
		for (int i = 0; i < n; i++)
		{
			cout << "Ярус " << k << " для вершини " << i + 1 << ": ";
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == k) {
					cout << j + 1 << ", ";
				}
			}
			cout << endl;
		}
		line();
		k++;
	}
}

void outvids(int** a, int** b,int** c, int** d, int n, int m) {
	cout << "-1 == infinity" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (i != (b[k][0] - 1) || j != (b[k][1] - 1)) {
					a[i][j] = -1;
					d[i][j] = 0;
					c[i][j] = 0;
				}
				a[b[k][0] - 1][b[k][1] - 1] = 1;
				d[b[k][0] - 1][b[k][1] - 1] = 1;
				c[b[k][0] - 1][b[k][1] - 1] = 1;
			}
			if (i == j) {
				a[i][j] = 0;
				d[i][j] = 0;
				c[i][j] = 0;
			}
		}
	}
	cout << "Матриця суміжності: " << endl;
	outmatr(a, n, n);
	line();
	for (int k = 1; k < n; k++) {
		multi(c, d, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == -1 && c[i][j] != 0 && i != j && a[i][j] <k) {
					a[i][j] = k+1;
				}
			}
		}	
	}	
	cout << "Матриця відстаней: " << endl;
	outmatr(a, n, n);
	line();
}

void outdist(int** a,int** b, int n) {
	cout << "Матриця досягнення: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j];
			if (i != j && a[i][j] == -1) {
				b[i][j] = 0;
			}
			else {
				b[i][j] = 1;
			}
		}
	}
	outmatr(b, n, n);
	line();
}

void orientzv(int** a, int** b,  int n) {
	int** add = new int* [n];
	for (int i = 0; i < n; i++) {
		add[i] = new int[n];
	}
	int** add2 = new int* [n];
	for (int i = 0; i < n; i++) {
		add2[i] = new int[n];
	}
	int** slab = new int* [n];
	for (int i = 0; i < n; i++) {
		slab[i] = new int[n];
	}
	int sz = 0, oz = 0, slz = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			add[i][j] = a[i][j] + a[j][i];
			add2[i][j] = b[i][j] + b[j][i];
			if (i == j) {
				add2[i][j] += 1;
			}
			if (a[i][j] ==1 ) {
				sz += 1;
			}
			if (add[i][j]>0) {
				oz += 1;
			}
		}
	}
	if (sz == n*n) {
		cout << "Сильнозв'язний граф." << endl;
	}
	if (oz == n*n) {
		cout << "Однобічно-зв'язний граф." << endl;
	}
	if (oz != n * n && sz != n * n) {
		for (int i = 1; i < n-1; i++) {
			multi(add2, add2, n);
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				if (add2[j][k] > 0) {
					slz += 1;
				}
			}
		}	
	}
	if (slz == n*n) {
		cout << "Слабкозв'язний граф." << endl;
	}
	if (oz != n * n && sz != n * n && slz != n * n) {
		cout << "Граф не зв'язний!" << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] add[i];
		delete[] add2[i];
		delete[] slab[i];
	}
	delete[] add;
	delete[] add2;
	delete[] slab;
}


