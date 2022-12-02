#include <iostream>

using namespace std;

// Se citesc un număr natural n având cifrele diferite 
// două câte două și o cifră c. 
// Afișați în ordine crescătoare numerele formate din 
// c cifre distincte care se pot obține din cifrele lui n.

int n, c;
int s[100];

int x[100];
int dim;

void atribuire() {
	dim = 0;
	while (n != 0) {
		x[dim] = n % 10;
		dim++;
		n /= 10;
	}
}

void bubbleSort() {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < dim - 1; i++) {
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
	for (int i = 0; i < c; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == c - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
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

void problema25() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti numarul de cifre : ";
	cin >> c;
	atribuire();
	bubbleSort();
	back(0);
}