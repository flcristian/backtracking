#include <iostream>

using namespace std;

// Se dă o mulțime cu n elemente, numere naturale. 
// Afișați în ordine lexicografică toate permutările mulțimii 
// date în care nu există două elemente prime alăturate.

int n;
int x[100], s[100];

int countDiv(int x) {
	int c = 0;
	for (int i = x; i > 0; i--) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool prim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

void bubbleSort() {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (prim(s[i]) && prim(s[i + 1])) {
			return 0;
		}
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

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
	bubbleSort();
	back(0);
}