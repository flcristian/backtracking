#include <iostream>

using namespace std;

// Se citește un număr natural n. 
// Afișați în ordine lexicografică toate 
// submulțimile mulțimii {1, 2, ..., n} 
// care sunt formate dintr-un număr impar de elemente.

int n;
int s[100];

void tipar(int m) {
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

bool solutie(int k, int m) {
	if (k == m - 1) {
		return 1;
	}
	return 0;
}

void back(int k, int m) {
	for (int i = 0; i < n && m <= n; i++) {
		s[k] = i + 1;
		if (valid(k)) {
			if (solutie(k, m)) {
				tipar(m);
				back(k + 1, m + 2);
			}
			else {
				back(k + 1, m);
			}
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;

	back(0, 1);
}
