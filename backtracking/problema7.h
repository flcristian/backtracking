#include <iostream>

using namespace std;

// Se citește un număr natural n (n<16). 
// Afișați în ordine lexicografică toate permutările mulțimii 
// {1,2,…,n} în care elementele pare sunt puncte fixe (nu își schimbă poziția).

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i <= k; i++) {
		if (i % 2 == 1 && s[i] != i + 1) {
			return 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
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

void problema7() {
	cout << "Introduceti n : ";
	cin >> n;

	back(0);
}