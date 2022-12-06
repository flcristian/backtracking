#include <iostream>

using namespace std;

// Generati numerele de n cifre care sa respect
// proprietatile: cifrele sa fie in ordine crescatoare
// si sa nu fie doua cifre alaturate de aceeasi paritate.
// Daca nu exista solutii afisati mesaj. 
// ? (Nu exista solutii decat in cazul n = 0 ?) ?

int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i];
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
		if (s[i] >= s[i + 1] || par(s[i]) == par(s[i + 1])) {
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
			i++;
		}

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
	cout << "Introduceti n : ";
	cin >> n;
	
	back(0);
}