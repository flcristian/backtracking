#include "structuri.h"

Persoana A("Mihai", "Gabriel", 19);
Persoana B("Florin", "Georgescu", 22);
Persoana C("Sorin", "Andrei", 20);
Persoana D("Daria", "Anghel", 18);
Persoana E("Alex", "Marescu", 19);

Persoana Persoane1[3] = { A, B, C };
Persoana Persoane2[2] = { D, E };
int n = 3, m = 2;
int nr;

Persoana solutii[100];

// Sa se faca produsul cartezian dintre Persoane1 si Persoane2.
// 
// Conditii :
//		-varsta persoanelor din Persoane1 sa nu fie divizibila cu 10.

void tipar() {
	for (int i = 0; i < 2; i++) {
		cout << solutii[i].prenume << " ";
	}
	cout << endl;
}

bool valid(int k) {
	if (k == 0 && solutii[k].varsta % 10 == 0) {
		return 0;
	}
	return 1;
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
		(k == 0 ? solutii[k] = Persoane1[i] : solutii[k] = Persoane2[i]);

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
	back(0);
}