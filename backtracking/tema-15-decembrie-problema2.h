#include <iostream>

using namespace std;

// Sa se genereze toate functiile injective :
// f:{1,2,...n}->{1,2...,m} (m>=n)

// ? ? ? ?

int n, m;
int numere1[100], numere2[100];
int s[100];

void atribuire() {
	for (int i = 0; i < n; i++) {
		numere1[i] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		numere2[i] = i + 1;
	}
}

void tipar() {
	cout << "f(" << s[0] << ") = ";
	cout << s[1] << endl;
}

bool solutie(int k) {
	if (k == 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	int n_m;
	(k == 0 ? n_m = n : n_m = m);
	for (int i = 0; i < n_m; i++) {
		(k == 0 ? s[k] = numere1[i] : s[k] = numere2[i]);
		if (solutie(k)) {
			tipar();
		}
		else {
			back(k + 1);
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti m : ";
	cin >> m;
	atribuire();
	back(0);
}