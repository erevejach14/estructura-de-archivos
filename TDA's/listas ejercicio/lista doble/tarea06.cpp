
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "list.h"

using namespace std;

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	List myLista;
	for (int i = 0; i < 10; ++i) {
		myLista.insertData(nullptr, rand()%101);
	}
	myLista.print();
	return 0;
}
