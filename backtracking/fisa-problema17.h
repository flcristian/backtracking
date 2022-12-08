#include <iostream>

using namespace std;

// Se dau n camile numerotate de la 1-n. Aranjati n
// camile astfel incat sa generati toate posibilitatile
// de camile de paritati diferite pe pozitii consecutive.

int n;
int x[100];
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool par(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	return 0;
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
	for (int i = 0; i < n; i++) {
		s[k] = i + 1;
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

	back(0);
}