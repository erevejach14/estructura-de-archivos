#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "multimedia.h"

class Delimit{
	private:
		Multimedia me;
	public:
		Delimit();
		~Delimit();

		void menu();

		void addMedia();
		void modifyMedia();
		void deleteMedia();
		void showMedia();
		void searchMedia();
};