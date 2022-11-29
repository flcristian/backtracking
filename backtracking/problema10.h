#include <iostream>
#include <string>

using namespace std;

// Se dă un cuvânt din cel mult 8 litere distincte. 
// Să se afișeze, în ordine alfabetică, toate anagramele acestui cuvânt.

string cuvant;
int dim;
char x[100], s[100];

void atribuire() {
	dim = 0;
	while (cuvant[dim] > 65) {
		x[dim] = cuvant[dim];
		dim++;
	}
}

void tipar() {
	for (int i = 0; i < dim; i++) {
		cout << s[i];
	}
	cout << endl;
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
	if (k == dim - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void problema10() {
	cout << "Introduceti cuvantul : ";
	cin >> cuvant;
	atribuire();

	back(0);
}