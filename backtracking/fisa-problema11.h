#include <iostream>

using namespace std;

// Se citeste un numar natural n>=4. Sa se afiseze
// toate permutarile multimii {1,2,3..,n} care au
// proprietatea ca oricare doua elemente alaturate au
// diferenta absoluta cel putin egala cu 2.

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool diferentaAbsolutaMin2(int a, int b) {
	if (a > b) {
		int r = a;
		a = b;
		b = r;
	}

	if (b - a < 2) {
		return 0;
	}
	return 1;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i] || !diferentaAbsolutaMin2(s[i], s[i + 1])) {
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
		s[k] = i + 1;
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

	back(0);
}