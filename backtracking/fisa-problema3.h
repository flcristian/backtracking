#include <iostream>

using namespace std;

// Sa se genereze toate numerele cu cifre distincte
// impare. Sa se spuna cate numere sunt.

int x[5] = { 1,3,5,7,9 };
int s[100];
int c;

void tipar(int m) {
	for (int i = 0; i < m; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] == s[k]) {
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
	for (int i = 0; i < 5 && m <= 5; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k, m)) {
				tipar(m);
				back(k + 1, m + 2);
				c++;
			}
			else {
				back(k + 1, m);
			}
		}
	}
}

void rezolvare() {
	c = 0;
	back(0, 1);
	cout << "\nS-au format " << c << " numere." << endl;
}