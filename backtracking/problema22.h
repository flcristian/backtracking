#include <iostream>

using namespace std;

// Se dau n numere naturale, unde n este un număr par.
// Se grupează cele n numere în perechi şi pentru fiecare 
// pereche de numere se află restul împărţirii unui număr 
// din pereche la celălalt.
// Se cere să se afle valoarea minimă a sumei acestor resturi.

int n;
int x[100];
int s[100];
int solutii[100][100];
int dim;

void bubbleSort() {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void atribuire() {
	for (int i = 0; i < n; i++) {
		solutii[dim][i] = s[i];
	}
	dim++;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				atribuire();
			}
			else {
				back(k + 1);
			}
		}
	}
}

int restMinim() {
	int min = 999999999;
	for (int i = 0; i < dim; i++) {
		int suma = 0;
		int r = -1;
		for (int j = 0; j < n - 1; j++) {
			if (solutii[i][j] != r) {
				int a = solutii[i][j], b = solutii[i][j + 1];
				if (a > b) {
					int aux = a;
					a = b;
					b = aux;
				}
				suma += b % a;
				r = solutii[i][j + 1];
			}
		}
		if (suma < min) {
			min = suma;
		}
	}
	return min;
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
	bubbleSort();
	back(0);
	cout << "Restul minim este : " << restMinim();
}