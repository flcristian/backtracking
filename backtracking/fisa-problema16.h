#include "fisa-problema16-structuri.h"

// Aranjati in toate modurile n pisici
// si m caini astfel incat nicio pisica
// sa nu fie asezata intre 2 caini.

Animal A("C");
Animal B("P");

int n, m, total;
total = n + m;
Animal animale = { A, B };
Animal s[100];

void tipar() {
	for (int i = 0; i < total; i++) {
		cout << s[i].tip << " ";
	}
	cout << endl;
}

bool valid(int k) {
	if (s[k].tip == "P" && s[k + 1].tip == s[k - 1].tip && s[k - 1].tip == "C") {
		return 0;
	}
	return 1;
}

bool solutie(int k) {
	if (k == total - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < total; i++) {

	}
}

// ? ? ? 