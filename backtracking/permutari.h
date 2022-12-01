#include "structuri.h"

Persoana A("Marian", "Barbu", 21);
Persoana B("Alex", "Radulescu", 22);
Persoana C("Andrei", "Popa", 30);
Persoana D("Paul", "Adrian", 15);
Persoana E("Darius", "Alexandru", 32);

Persoana persoane[5] = { A, B, C, D, E };
Persoana solutii[100];

int dim = 3;

// Exemplu primul copil sa aiba varsta impara, iar ultimul par.

void tipar() {
	for (int i = 0; i < dim; i++) {
		cout << solutii[i].nume << " ";
		
	}
	cout << endl << "============================" << endl;
}

bool valid(int k) {
	//if (k==0 && solutii[k].varsta % 2 == 0) {
	//	return 0;
	//}
	//if (k == dim - 1 && solutii[k].varsta % 2 == 1) {
	//	return 0;
	//}	
	for (int i = 0; i < k; i++) {
		if (solutii[k].nume == solutii[i].nume) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (dim - 1 == k) {
		return true;
	}
	return false;
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		solutii[k] = persoane[i];
		if (valid(k)) {
			if (solutie(k)){
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

