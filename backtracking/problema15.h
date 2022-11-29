#include <iostream>

using namespace std;

// Se citește un număr natural n având cifrele diferite două câte două.
// Afișați în ordine crescătoare numerele care se pot obține din 
// cifrele lui n și care au același număr de cifre ca n.

int n, dim = 0;
int x[100], s[100];

void atribuire() {
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
	for (int i = 0; i < dim; i++) {
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
	if (k == dim - 1) {
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

void problema15() {
	cout << "Introduceti n : ";
	cin >> n;
	atribuire();

	bubbleSort();
	back(0);
}