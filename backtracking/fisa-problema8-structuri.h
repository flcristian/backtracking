#include <iostream>
#include <string>

using namespace std;

struct Elev {
	string nume = "";
	bool fata = 0;

	Elev() {
	}

	Elev(string nume, bool fata) {
		this->nume = nume;
		this->fata = fata;
	}
};