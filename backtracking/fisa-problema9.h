#include <iostream>

using namespace std;

// Cate numere de exact 3 cifre pot
// fi construite folosind doar cifre pare?

int x[5] = { 0,2,4,6,8 };
int c = 0;
int s[100];

void tipar() {
	for (int i = 0; i < 3; i++) {
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
	if (k == 2) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 5; i++) {
		if (k == 0 && i == 0) {
			i++;
		}

		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
				c++;
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	back(0);

	cout << "S-au format " << c << " numere." << endl;
}