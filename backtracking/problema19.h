#include <iostream>

using namespace std;

// Se citește un număr natural n. 
// Afișați în ordine lexicografică toate cuvintele care 
// sunt formate din n litere mari, care au literele ordonate 
// alfabetic strict crescător și în care numărul de vocale 
// este mai mare decât numărul de consoane.

int n, c = 0;
char x[26], s[100];
char vocale[5] = {'A','E','I','O','U'};

void atribuire() {
	for (int i = 0; i < 26; i++) {
		x[i] = 65 + i;
	}
}

void tipar() {
	for (int i = 0; i < n; i++) {
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

bool esteVocala(char x) {
	for (int i = 0; i < 5; i++) {
		if (x == vocale[i]) {
			return 1;
		}
	}
	return 0;
}

int nrVocale() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (esteVocala(s[i])) {
			c++;
		}
	}
	return c;
}

int nrConsoane() {
	return n - nrVocale();
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 26 && k < n; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				if (nrVocale() > nrConsoane()) {
					tipar();
					c++;
				}
			}
			else {
				back(k + 1);
			}
		}
	}
}

void problema19() {
	cout << "Introduceti n : ";
	cin >> n;
	atribuire();

	back(0);
	cout << c << " combinatii" << endl;
}