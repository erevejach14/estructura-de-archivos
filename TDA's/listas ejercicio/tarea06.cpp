
#include <iostream>

#include "music.h"
#include "menu.h"
#include "list.h"

using namespace std;

int main(int argc, char const *argv[]) {
	List myLista;
	new Menu(myLista);
	return 0;
}