#include <iostream>

using namespace std;

int s[100];
int a, b;
int dim;

void tipar() {
	for (int i = 0; i < dim; i++) {
		cout << s[i] << " ";
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
	if (k != dim - 1) {
		return 0;
	}
	return 1;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		s[k] = a + i;
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
	cout << "Introduceti a : ";
	cin >> a;
	cout << "Introduceti b : ";
	cin >> b;
	dim = b - a + 1;

	back(0);
}
