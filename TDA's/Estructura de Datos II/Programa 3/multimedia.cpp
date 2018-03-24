#include "multimedia.h"

Multimedia::Multimedia(){
	
}

Multimedia::~Multimedia(){

}

	 	
char* Multimedia::getURL(){
	return URL;
}

void Multimedia::setURL(char* url){
	URL = url;
}

char* Multimedia::getName(){
	return name;
}

void Multimedia::setName(char*name){
	this->name = name;
	comprubName(name);
}

char* Multimedia::getDate(){
	return date;
}

void Multimedia::setDate(char* date){
	this->date = date;
}


bool Multimedia::comprubName(char* name){
	bool point = false;
	int count = 0;
	int noMoreCharacteres = 0;

	for(int i = 0; i < sizeof(name); i++){
		if(name[i] == '.')
			point = true;
		if(point == true and posiblesExt(URL))
			noMoreCharacteres++;
		if(point == true and !posiblesExt(URL))
			return false;
	}
	if(noMoreCharacteres > 4 or noMoreCharacteres < 3)
		return false;
	if(point != true)
		return false;
	return true;
}

bool Multimedia::posiblesExt(char* pos){
	for(int i = 0;i < URL.lentgh() ;i++)
		for (int j = 0; j < 26; ++j)
			if(pos[i] == posi[j])
				return true;
	return false;
}