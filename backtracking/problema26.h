#include <iostream>

using namespace std;

// Se citesc două numere naturale nenule n și m.
// Să se afişeze, în ordine lexicografică, submulțimile 
// de câte m elemente ale mulţimii{ 1,2,..,n }.

int n, m;
int s[100];

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
	cout << "Introduceti m : ";
	cin >> m;

	back(0);
}