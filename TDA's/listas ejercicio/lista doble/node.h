#ifndef NODE_H
#define NODE_H


class Node {
private:
	int data;
	Node* next;
	Node* prev;

public:
	Node();
	Node(const int&);

	int& getData();
	Node* getNext();
	Node* getPrev();

	void setData(const int&);
	void setNext(Node*);
	void setPrev(Node*);
	//~Node();

};

Node::Node() {
	next = nullptr;
	prev = nullptr;
}

Node::Node(const int& m) : Node() {
	data = m;
}

int& Node::getData() {
	return data;
}

Node* Node::getNext() {
	return next;
}

Node* Node::getPrev() {
	return prev;
}

void Node::setData(const int& m) {
	data = m;
}

void Node::setNext(Node* n) {
	next = n;
}

void Node::setPrev(Node* p) {
	prev = p;
}

#endif
