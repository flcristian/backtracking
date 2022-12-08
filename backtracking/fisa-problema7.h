#include <iostream>

using namespace std;

// Sa se genereze toate sirurile de n cifre binare (n<=7)
// care au cel mult 2 cifre 0 alaturate. Sa se spuna cate
// solutii incep cu cifra 0 si cate solutii sunt in total.

int n;
int s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

// Nu inca.