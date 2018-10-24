#include "List.h"
#include <sstream>

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

List::List(const List& other) : List() {
	this->addAll(other);
}

int List::first() const {
    if(this->head != nullptr){
        return this->head->getValue();
    }else{
        return 0;
    }
}

void List::add(int value) {
	Node* newNode = new Node(value, nullptr, nullptr);
	if(this->head != nullptr){
        this->tail->setNext(newNode);
	}else{
        this->head = newNode;
	}

	this->tail = newNode;
	this->size++;
}

void List::addAll(const List& other) {
    Node* otherHead = other.head;
	while (otherHead != nullptr) {
		this->add(otherHead->getValue());
		otherHead = otherHead->getNext();
	}
}

void List::removeFirst() {
    if(this->head != nullptr){
        Node* toRemove = this->head;
        if(toRemove->getNext() != nullptr){
            this->toRemove->getNext()->setPrev(nullptr);
            this->head = this->toRemove->getNext();
        }else{
            this->head = nullptr;
            this->tail = nullptr
        }

        delete toRemove;
        this->size--;
    }
}

void List::removeAll(){
    Node* node = this->head;
    while(node != nullptr){
        Node* toDelete = node;
        node = node->getNext();
        delete toDelete;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

size_t List::getSize() const {
  return this->size;
}

bool List::isEmpty() const {
  return this->size == 0;
}

std::string List::toString() const {
  std::ostringstream os;
  Node* node = this->head;
  while (node != nullptr) {
    os << node->getValue() << ' ';
    node = node->getNext();
  }
  return os.str();
}

List List::getReversed(List list) {
  List reversed;
  Node* node = list.tail;
  while (node != nullptr) {
    reversed.add(node->getValue());
    node = node->getPrev();
  }
  return reversed;
}

List& List::operator<<(const int& value) {
  this->add(value);
  return *this;
}

List& List::operator<<(const List& other) {
  this->addAll(other);
  return *this;
}

List& List::operator=(const List& other) {
  if (this != &other) {
    this->removeAll();
    this->addAll(other);
  }
  return *this;
}

List::~List(){
    this->removeAll();
}
