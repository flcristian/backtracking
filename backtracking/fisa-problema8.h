#include "fisa-problema8-structuri.h"

using namespace std;

// Se formeaza echipe de 3 elevi, doi baieti si o fata
// dinte vectorul de mai jos. Ordinea din echipa conteaza.
// In cate echipe Alin si Bogdan sunt coechipieri?
// Cate echipe sunt in total?

Elev A("Alin", 0);
Elev B("Bogdan", 0);
Elev C("Calin", 0);
Elev D("Dana", 1);
Elev E("Elena", 1);
Elev F("Flavia", 1);

Elev x[6] = { A,B,C,D,E,F };
int c1 = 0, c2 = 0;
Elev s[100];

void tipar() {
	for (int i = 0; i < 3; i++) {
		cout << s[i].nume << " ";
	}
	cout << endl;
}

bool apareOFataSiDoiBaieti() {
	int countFete = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i].fata) {
			countFete++;
		}
	}

	if (countFete == 1) {
		return 1;
	}
	return 0;
}

bool valid(int k) {
	if (k == 2 && !apareOFataSiDoiBaieti()) {
		return 0;
	}
	for (int i = 0; i < k; i++) {
		if (s[i].nume >= s[i + 1].nume) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == 2) {
		return 1;
	}
	return 0;
}

bool aparAlinSiBogdan() {
	bool apareAlin = 0, apareBogdan = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i].nume == "Alin") {
			apareAlin = 1;
		}
		if (s[i].nume == "Bogdan") {
			apareBogdan = 1;
		}
	}
	if (apareAlin == 1 && apareBogdan == 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < 6; i++) {
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
				c1++;
				if (aparAlinSiBogdan()) {
					c2++;
				}
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	back(0);
	cout << "S-au format " << c1 << " echipe." << endl;
	cout << "Alin si Bogdan apar in " << c2 << " echipe." << endl;
}