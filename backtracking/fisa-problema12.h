#include <iostream>

using namespace std;

// Scrieti un program care citeste de la
// tastatura un numar natural nenul n
// (n<=20) si construieste toate numerele
// formate din n cifre impare cu proprietatea
// ca oricare doua cifre alaturate dintr-un
// numar generat sunt consecutive in multimea
// cifrelor impare.
// Exemplu pentru 4 : 1313, 1353, 1356, ..., 7979...

int n;
int x[5] = { 1, 3, 5, 7, 9 };
int s[100];

void atribuire() {
	for (int i = 1, j = 0; j < n; i += 2, j++) {
		x[j] = i;
	}
}

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool consecutive(int a, int b) {
	int i = 0;
	while (x[i] != a) {
		i++;
	}
	if (x[i - 1] != b && x[i + 1] != b) {
		return 0;
	}
	return 1;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (!consecutive(s[i], s[i + 1])) {
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
	for (int i = 0; i < 5; i++) {
		s[k] = x[i % 5];
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

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	atribuire();

	back(0);
}