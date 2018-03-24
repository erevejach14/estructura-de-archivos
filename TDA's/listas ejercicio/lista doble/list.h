#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <exception>
#include <string>

#include "node.h"



class ListException : public std::exception {
private:
	std::string msg;
public:
	explicit ListException(const char* message):msg(message){}
	explicit ListException(const std::string message):msg(message){}
	virtual ~ListException()throw(){}
	virtual const char* what() const throw(){return msg.c_str();}

	};




class List {
private:
	Node* anchor;

	bool isEmpty();
	bool isValidPos(Node*);

public:
	List();
	List(const List&);
	~List();

	Node* getFirstPos();
	Node* getLastPos();
	Node* getNextPos(Node*);
	Node* getPrevPos(Node*);
	Node* findData(const int&);

	int& retrieve(Node*);

	void insertData(Node*, const int&);
	void deleteData(Node*);
	void deleteAll();

	void print();

	Node* linearSearch(const int&);

	void writeToDisk(std::string);
	void readFromDisk(std::string);
};

bool List::isEmpty() {
	return anchor == nullptr;
}

bool List::isValidPos(Node* n) {
	Node* aux = anchor;
	while(aux != nullptr) {
		if(aux == n) {
			return true;
		}
		aux = aux->getNext();
	}
	return false;
}

List::List() {
	anchor = nullptr;
}

List::List(const List& l) : List() {
	Node* aux = l.anchor;
	while(aux != nullptr) {
		insertData(getLastPos(), aux->getData());
		aux = aux->getNext();
	}
}

List::~List() {
	deleteAll();
}

Node* List::getFirstPos() {
	if(isEmpty()) {
		return nullptr;
	}
	return anchor;
}

Node* List::getLastPos() {
	if(isEmpty()) {
		return nullptr;
	}

	Node* aux = anchor;
	while(aux->getNext() != nullptr) {
		aux = aux->getNext();
	}
	return aux;
}

Node* List::getNextPos(Node* p) {
	if(!isValidPos(p)) {
		throw ListException("Error invalid position to obtain the next position");
	}
	return p->getNext();
}

Node* List::getPrevPos(Node* p) {
	if(!isValidPos(p)) {
		throw ListException("Error invalid position to obtain thee prev position");
	}

	return p->getPrev();
}

Node* List::findData(const int& e) {
	Node* aux = anchor;
	while(aux != nullptr and aux->getData() != e) {
		aux = aux->getNext();
	}
	return aux;
}

int& List::retrieve(Node* p) {
	if(!isValidPos(p)) {
		throw ListException("Error invalid position to make retrieve");
	}
	return p->getData();
}

void List::insertData(Node* p, const int& e) {
	if (p != nullptr and !isValidPos(p)) {
		throw ListException("Error invalid position to insert");
	}

	Node* aux = new Node(e);

	if (aux == nullptr) {
		throw ListException("Error memory insufficent to insert");
	}

	if (p == nullptr) {
		aux->setNext(anchor);
		if (anchor != nullptr) {

			anchor->setPrev(aux);

		}
		anchor = aux;
	}

	else {
		aux->setPrev(p);
		aux->setNext(p->getNext());

		if (p->getNext() != nullptr) {

			p->getNext()->setPrev(aux);

		}

		p->setNext(aux);
	}

}

void List::deleteData(Node* p) {
	if (!isValidPos(p)) {
		throw ListException("Error invalid position to delete");
	}

	if (p->getPrev() != nullptr) {

		p->getPrev()->setNext(p->getNext());

	}

	if (p->getNext() != nullptr) {

		p->getNext()->setPrev(p->getPrev());

	}

	if (p == anchor){

		anchor = anchor->getNext();

	}

	delete p;

}

void List::deleteAll() {
	Node* aux;
	while(anchor != nullptr) {
		aux = anchor;
		anchor = anchor->getNext();
		delete aux;
	}
}

void List::print() {
	Node* aux = anchor;
	while(aux != nullptr) {

		std::cout << aux->getData() <<std::endl;

		aux = aux->getNext();
	}
}

Node* List::linearSearch(const int& e) {
	Node* aux = anchor;
	while(aux->getData() != e and aux != nullptr) {
		aux = aux->getNext();
	}
	return aux;
}

void List::writeToDisk(std::string fileName) {
	std::ofstream file(fileName.c_str());
	if(!file.is_open()) {
		throw ListException("Error, can't open the file");
	}
	Node* aux = anchor;
	while (aux != nullptr) {
		file << aux->getData();
		aux = aux->getNext();
	}
	file.close();
}

void List::readFromDisk(std::string fileName) {

	std::ifstream file(fileName.c_str());

	if (!file.is_open()) {
		throw ListException("Error, can't read the file");
	}

	deleteAll();

	int myint;
	try {
		while(file >> myint) {
			insertData(getLastPos(),myint);
		}
	}catch(ListException ex) {
		file.close();
		std::string newMsg = "Error can't insert sings froms the disk";
		newMsg += ex.what();
		throw ListException(newMsg);
	}
	file.close();
}


#endif
