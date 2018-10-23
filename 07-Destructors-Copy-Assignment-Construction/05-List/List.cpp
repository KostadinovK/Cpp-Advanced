#include "List.h"

List::Node::Node(int value, Node* prev, Node* next) : value(value), prev(prev), next(next) {}

int List::Node::getValue() const {
	return this->value;
}

void List::Node::setValue(int value) {
	this->value = value;
}

List::Node* List::Node::getNext() const {
	return this->next;
}

void List::Node::setNext(List::Node* next) {
	this->next = next;
}

List::Node* List::Node::getPrev() const {
	return this->prev;
}

void List::Node::setPrev(List::Node* prev) {
	this->prev = prev;
}

List::List() : size(0),head(nullptr),tail(nullptr) {}

List::List(const List& other) {
	this->size = other.size;
	
	this->head = new Node(0,nullptr,nullptr);
	this->head->setValue(other.head->getValue());
	this->head->setPrev(other.head->getPrev());
	this->head->setNext(other.head->getNext());

	this->tail = new Node(0,nullptr,nullptr);
	this->tail->setValue(other.tail->getValue());
	this->tail->setPrev(other.tail->getPrev());
	this->tail->setNext(other.tail->getNext());
}

int List::first() const {
	return this->head->getValue();
}

void List::add(int value) {
	Node* newNode = new Node(value, nullptr, nullptr);
	this->tail->setNext(newNode);
	newNode->setPrev(this->tail);
	this->tail = newNode;
}

void List::addAll(const List& other) {
	while (other.tail->getNext() != nullptr) {
		add(other.tail->getValue());
		other.tail = other.tail->getNext();
	}
}