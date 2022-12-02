#include <iostream>

using namespace std;

// Să se determine toate submulţimile cu m 
// elemente ale mulţimii divizorilor unui număr natural x dat.

int x, m;
int s[100];

int valori[100];
int dim;

void atribuire() {
	dim = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			valori[dim] = i;
			dim++;
		}
	}
}

void tipar() {
	for (int i = 0; i < m; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == m - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		s[k] = valori[i];
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

void problema31() {
	cout << "Introduceti x : ";
	cin >> x;
	cout << "Introduceti m : ";
	cin >> m;
	atribuire();
	back(0);
}