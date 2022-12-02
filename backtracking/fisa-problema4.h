#include <iostream>

using namespace std;

// Sa se genereze numerele naturale de
// n cifre distincte (n<=5) care au cifrele
// alaturate de paritate diferita. Sa se spuna cate
// solutii sunt.

int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
int s[1000];
int n, c;

bool par(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
}

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i] || par(s[i]) == par(s[i + 1])) {
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
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	cout << "Introduceti n (n <= 5) : ";
	cin >> n;
	c = 0;

	back(0);

	cout << "S-au format " << c << " numere." << endl;
}