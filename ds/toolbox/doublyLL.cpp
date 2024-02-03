#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

// DOUBLY LINKED LIST
template<typename T>
struct NodeDoubleLL {
	NodeDoubleLL<T> *back=NULL, *front=NULL;
	T value;

	NodeDoubleLL(T value);
	void print();
};

template<typename T>
NodeDoubleLL<T>::NodeDoubleLL(T value) : value(value) {};

template<typename T>
void NodeDoubleLL<T>::print() {
	cout << value << ' ';
};

template<typename T>
struct DoublyLL {
	NodeDoubleLL<T>* head = NULL, *tail = NULL;
	int size = 0;

	void pushFront(T value);
	T topFront();
	T popFront();
	void pushBack(T value);
	T topBack();
	T popBack();
	bool empty();
	void print();
};

template<typename T>
void DoublyLL<T>::pushFront(T value) {
	size++;
	NodeDoubleLL<T>* newNode = new NodeDoubleLL<T>(value);
	if (head == NULL || tail == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->front = head;
	head->back = newNode;
	head = newNode;
}

template<typename T>
T DoublyLL<T>::topFront() {
	if (head == NULL) {
		throw invalid_argument("EMPTY LIST");
	}
	return head->value;
}

template<typename T>
T DoublyLL<T>::popFront() {
	T front = topFront();
	size--;
	if (head == NULL || head->front == NULL) {
		head = NULL;
		tail = NULL;
		return front;
	}
	head = head->front;
	head->back = NULL;
	return front;
}

template<typename T>
void DoublyLL<T>::pushBack(T value) {
	NodeDoubleLL<T>* newNode = new NodeDoubleLL<T>(value);
	size++;
	if (head == NULL || tail == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->back = tail;
	tail->front = newNode;
	tail = newNode;
}

template<typename T>
T DoublyLL<T>::topBack() {
	if (tail == NULL) {
		throw invalid_argument("EMPTY LIST");
	}
	return tail->value;
}

template<typename T>
T DoublyLL<T>::popBack() {
	T back = topBack();
	size--;
	if (tail == NULL || tail->back == NULL) {
		head = NULL;
		tail = NULL;
		return back;
	}
	tail = tail->back;
	tail->front = NULL;
	return back;
}

template<typename T>
bool DoublyLL<T>::empty() {
	return head == NULL || tail == NULL;
}

template<typename T>
void DoublyLL<T>::print() {
	NodeDoubleLL<T> *current = head;

	while (current != NULL) {
		current->print();
		current = current->front;
	}
	cout << endl;
}

