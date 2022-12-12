#include <iostream>

using namespace std;

// Se dau două numere naturale nenule n și m.
// Considerăm mulțimea A = { 1,2,..,n }. 
// Să se genereze în ordine lexicografică 
// elementele produsului cartezian A^m = A×A×⋯×A.

struct Multime {
	int x[100];
};

Multime Multimi[1000]; // Multimea cu solutiile retinute dinainte.
Multime MultimiNeadaugate[1000]; // Multimea cu solutiile formate noi.

int n, m;

int nr = 2; // Numarul de valori din solutie.

int cRetinut; // Numarul de solutii vechi.
int c = 0; // Numarul de solutii noi.

int x[100];
Multime s;

void atribuire() { // Atribuire x, unde x = {1,2,3...,n}
	for (int i = 0; i < n; i++) {
		x[i] = i + 1;
	}
}

void tipar() {
	for (int i = 0; i < nr; i++) {
		cout << s.x[i] << " ";
	}
	cout << endl;
}

bool solutie(int k) {
	if (k == nr - 1) {
		return 1;
	}
	return 0;
}

void atribuireSolutie() { // Atribuire valori pentru solutia care este in creare.
	for (int i = 0; i < nr - 1; i++) {
		s.x[i + 1] = Multimi[c%cRetinut].x[i];
	}
}

void adaugareMultimi() { // Override multimi vechi cu cele noi.
	for (int i = 0; i < c; i++) {
		Multimi[i] = MultimiNeadaugate[i];
	}
}

void back(int k) {
	int limita;
	(nr == 2 ? limita = n : limita = n);
	for (int i = 0; i < limita; i++) {
		if (nr == 2) {
			s.x[k] = x[i]; // Formarea primului produs cartezian.
		}
		else {
			if (k == 0) {
				s.x[k] = x[i]; // Se atribuie prima valoare dupa x, unde x = {1,2,3...,n}
			}
			else {
				atribuireSolutie(); // Se atribuie restul de valori din solutia "veche".
			}
		}
		if (solutie(k)) {
			//tipar();
			MultimiNeadaugate[c] = s; // S
			c++;
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

	for (int z = 0; z < m - 1; z++) {
		back(0);
		cRetinut = c;
		adaugareMultimi();
		c = 0;
		nr++;
	}
	
	cout << "\nMultimiile formate dupa AxAxA..xA de m ori sunt : " << endl << endl;
	for (int i = 0; i < cRetinut; i++) {
		for (int j = 0; j < nr - 1; j++) {
			cout << MultimiNeadaugate[i].x[j] << " ";
		}
		cout << endl;
	}
}