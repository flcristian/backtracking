#include <iostream>

using namespace std;

// Se citește un număr natural n. 
// Afișați în ordine crescătoare toate numerele care 
// sunt formate din n cifre distincte și care au 
// mai multe cifre pare decât cifre impare.

int n, c = 0;
int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k) {
	if (s[0] == 0) {
		return 0;
	}
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

int nrPare() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] % 2 == 0) {
			c++;
		}
	}
	return c;
}

int nrImpare() {
	return n - nrPare();
}

bool solutie(int k) {
	if (k == n - 1 && nrPare() > nrImpare()) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 10 && k < n; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
				c++;
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;

	back(0);
	cout << c << " combinatii" << endl;
}