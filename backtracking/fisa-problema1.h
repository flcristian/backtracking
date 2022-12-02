#include <iostream>

using namespace std;

// Sa se genereze numerele naturale cu cifre din multimea
// {1,2,3,4,5,6,7} de n cifre (n<=5) in ordine strict
// crescatoare.

int x[7] = { 1,2,3,4,5,6,7 };
int n;
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
	for (int i = 0; i < 7; i++) {
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
	cout << "Introduceti n (n <= 5) : ";
	cin >> n;
	back(0);
}