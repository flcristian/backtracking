#include <iostream>

using namespace std;

// Se citesc două numere naturale n și m. 
// Afișați în ordine lexicografică toate cuvintele care sunt formate 
// din m litere folosind primele n litere mari din alfabet și care 
// au literele ordonate alfabetic strict crescător.

int n, m;
char x[100], s[100];

void atribuire() {
	for (int i = 0; i < n; i++) {
		x[i] = 65 + i;
	}
}

void tipar() {
	for (int i = 0; i < m; i++) {
		cout << s[i];
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
	for (int i = 0; i < n && k < m; i++) {
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

void problema18() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	atribuire();

	back(0);
}