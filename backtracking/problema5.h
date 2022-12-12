#include <iostream>

using namespace std;

// Se citeşte un număr natural nenul n, apoi n numere naturale distincte. 
// Să se afişeze, în ordine lexicografică, șirurile din cele n valori 
// cu proprietatea că oricare două valori învecinate sunt prime între ele.

int n;
int x[100];
int s[100];

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

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

int cmmdc(int a, int b) {
	if (a > b) {
		int r = a;
		a = b;
		b = r;
	}

	for (int i = b; i > 1; i--) {
		if (b % i == 0 && a % i == 0) {
			return i;
		}
	}
	return 1;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (cmmdc(s[i], s[i + 1]) != 1) {
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