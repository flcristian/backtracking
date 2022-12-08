#include <iostream>

using namespace std;

// Sa se genereze numerele de n cifre (n<=5)
// folosind doar cifrele {3,5,7}.
// Cate solutii sunt?
// Care sunt ultimele 3 solutii generate?

int x[3] = { 3,5,7 };
int n, c = 0;
int s[100];
int solutii[10000][10000];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << solutii[c][i];
	}
	cout << endl;
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void adaugareSolutie() {
	for (int i = 0; i < n; i++) {
		solutii[c][i] = s[i];
	}
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i % 3];
		if (solutie(k)) {
			adaugareSolutie();
			tipar();
			c++;
		}
		else {
			back(k + 1);
		}
	}
}

void AfisareUltimile3Solutii() {
	for (int i = c - 3; i < c ; i++) {
		for (int j = 0; j < n; j++) {
			cout << solutii[i][j];
		}
		cout << endl;
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	
	back(0);

	cout << "S-au format " << c << " numere." << endl;
	cout << "Ultimele 3 solutii sunt : " << endl;
	AfisareUltimile3Solutii();
}

// ? ? ? ? (Conditia de validitate)