#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Persoana {
	string prenume;
	string nume;
	int varsta;

	Persoana() {
		nume = "";
		prenume = "";
		varsta = -1;
	}

	Persoana(string prenume, string nume, int varsta) {
		this->prenume = prenume;
		this->nume = nume;
		this->varsta = varsta;
	}
};
