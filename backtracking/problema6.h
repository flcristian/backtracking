#include <iostream>

using namespace std;

// Se citeşte un număr natural nenul n. 
// Să se afişeze, în ordine lexicografică, permutările 
// fără puncte fixe ale mulţimii {1,2,..,n}.
// Fie mulţimea M = { 1,2,..,n } şi P(1), P(2), ..., P(n) 
// o permutare a ei.Elementul x din M se numeşte punct fix dacă P(x) = x.

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i <= k; i++) {
		if (s[i] == i + 1) {
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

void problema6() {
	cout << "Introduceti n : ";
	cin >> n;

	back(0);
}