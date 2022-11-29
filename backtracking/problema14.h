#include <iostream>
#include <string>

using namespace std;

// Se citește de la tastatură un cuvânt s format din cel 
// mult 11 litere mici distincte. Să se genereze în ordine 
// alfabetică și să se afișeze toate anagramele cuvântului s 
// în care consoanele sunt puncte fixe.

string cuvant;
int dim;
char x[100], s[100];
char vocale[5] = { 'a', 'e', 'i', 'o', 'u' };

bool esteVocala(char x) {
	for (int i = 0; i < 5; i++) {
		if (x == vocale[i]) {
			return 1;
		}
	}
	return 0;
}

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
	for (int i = 0; i <= k; i++) {
		if (!esteVocala(x[i]) && x[i] != s[i]) {
			return 0;
		}
	}
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

void problema14() {
	cout << "Introduceti cuvantul : ";
	cin >> cuvant;
	atribuire();

	back(0);
}