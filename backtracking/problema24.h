#include <iostream>

using namespace std;

// Se citesc trei numere naturale a b n. 
// Să se afișeze, în ordine lexicografică, 
// șirurile cu n elemente distincte din mulțimea {a, a + 1, ..., b}.

int a, b, n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
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
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = a; i <= b; i++) {
		s[k] = i;
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

void problema24() {
	cout << "Avem intervalul inchis [a, b]" << endl;
	cout << "Introduceti a : ";
	cin >> a;
	cout << "Introduceti b : ";
	cin >> b;
	cout << "\nIntroduceti n : ";
	cin >> n;

	back(0);
}