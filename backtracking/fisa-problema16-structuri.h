#include <iostream>

using namespace std;

struct Animal {
	string tip = "";

	Animal() {
	}

	Animal(string tip) {
		this->tip = tip;
	}
};