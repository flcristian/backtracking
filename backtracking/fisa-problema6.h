#include <iostream>

using namespace std;

// Sa se genereze toate numerele de n
// cifre distincte si strict crescatoare.
// Sa se spuna cate solutii sunt. Daca n este
// 5 sa se spuna cate numere incep cu cifra 4.

int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
int n, c, c2;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
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
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 10; i++) {
		if (k == 0 && i == 0) {
			i = 1;
		}

		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
				c++;
				if (n == 5 && s[0] == 4) {
					c2++;
				}
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
	c = 0;

	if (n == 5) {
		c2 = 0;
	}

	back(0);

	cout << "S-au format " << c << " numere." << endl;
	if (n == 5) {
		cout << "(n este 5)" << endl;
		cout << "Exista " << c2 << " numere cu 4 la inceput." << endl;
	}
}