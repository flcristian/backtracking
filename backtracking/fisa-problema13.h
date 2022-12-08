#include <iostream>

using namespace std;

// Se citeste un numar natural n.
// Sa se afiseze permutarile multimii
// {1,2,3...,n} in care oricare doua
// elemente alaturate nu au fost alaturate in
// multime.

int n, m;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool alaturate(int a, int b) {
	if (a + 1 == b || a - 1 == b) {
		return 1;
	}
	return 0;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i] || alaturate(s[i], s[i + 1])) {
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
