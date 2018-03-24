#ifndef NODE_H
#define NODE_H

#include "music.h"

class Node {
private:
	Music data;
	Node* next;
	Node* prev;

public:
	Node();
	Node(const Music&);

	Music& getData();
	Node* getNext();
	Node* getPrev();

	void setData(const Music&);
	void setNext(Node*);
	void setPrev(Node*);
	//~Node();
	
};

Node::Node() {
	next = nullptr;
	prev = nullptr;
}

Node::Node(const Music& m) : Node() {
	data = m;
}

Music& Node::getData() {
	return data;
}

Node* Node::getNext() {
	return next;
}

Node* Node::getPrev() {
	return prev;
}

void Node::setData(const Music& m) {
	data = m;
}

void Node::setNext(Node* n) {
	next = n;
}

void Node::setPrev(Node* p) {
	prev = p;
}

#endif