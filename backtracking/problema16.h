#include <iostream>

using namespace std;

// Se citeşte un număr natural nenul n şi o permutare a 
// mulţimii M = { 1,2,..,n }. Să se afişeze, în ordine lexicografică, 
// toate permutările mulţimii M care nu conţin elemente alăturate care 
// au fost alăturate şi în permutarea dată.

int n;
int x[100];
int r[100];
int s[100];

void bubbleSort() {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

void atribuire() {
	for (int i = 0; i < n; i++) {
		r[i] = x[i];
	}
}

bool alaturate(int a, int b) {
	for (int i = 0; i < n - 1; i++) {
		if ((a == r[i] && b == r[i + 1]) || (b == r[i] && a == r[i + 1])) {
			return 1;
		}
	}
	return 0;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (alaturate(s[i], s[i + 1])) {
			return 0;
		}
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

void problema16() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti x[" << i << "] : ";
		cin >> x[i];
	}
	atribuire();
	bubbleSort();
	back(0);
}