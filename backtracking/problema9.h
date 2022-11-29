#include <iostream>

using namespace std;

// Scrieți un program care citește un număr natural n cu 
// cifre distincte și care să calculeze și să afișeze suma S a 
// tuturor numerelor obținute prin rearanjarea cifrelor lui n.

int n, dim, suma = 0;
int x[100], s[100];

void atribuire() {
	dim = 0;
	while (n != 0) {
		x[dim] = n % 10;
		dim++;
		n /= 10;
	}
}

void adaugareSuma() {
	int numar = 0;
	for (int i = 0; i < dim; i++) {
		numar = numar * 10 + s[i];
	}
	suma += numar;
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
				adaugareSuma();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void problema9() {
	cout << "Introduceti n : ";
	cin >> n;
	atribuire();

	back(0);
	cout << "Suma tuturor combinatilor este : " << suma << endl;
}
