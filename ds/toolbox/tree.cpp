#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

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

// QUEUE
template<typename T>
class Queue{
	DoublyLL<T> list;
public:
	Queue();
	void enqueue(T value);
	T dequeue();
	T peek();
	T rear();
	bool empty();
	int size();
	void print();
};

template<typename T>
Queue<T>::Queue() {}

template<typename T>
void Queue<T>::enqueue(T value) {
	list.pushBack(value);
}

template<typename T>
T Queue<T>::rear() {
	return list.topBack();
}

template<typename T>
T Queue<T>::dequeue() {
	return list.popFront();
}

template<typename T>
T Queue<T>::peek() {
	return list.topFront();
}

template<typename T>
bool Queue<T>::empty() {
	return list.empty();
}

template<typename T>
int Queue<T>::size() {
	return list.size;
}

template<typename T>
void Queue<T>::print() {
	list.print();
}

// TREE
template<typename T>
struct TreeNode {
	T value;
	TreeNode *parent;
	vector<TreeNode *> child;

	TreeNode(T value);
	void addChild(TreeNode* childTreeNode);
	int height();
};

template<typename T>
TreeNode<T>::TreeNode(T value) : value(value) {}

template<typename T>
void TreeNode<T>::addChild(TreeNode<T>* childTreeNode) {
	child.push_back(childTreeNode);
	childTreeNode->parent = this;
}

template<typename T>
int TreeNode<T>::height() {
	Queue<TreeNode<T>*> q;
	q.enqueue(this);
	int h = 0;
	while (!q.empty()) {
		int size = q.size();
		h++;
		while (size > 0) {
			TreeNode<T> *node = q.dequeue();
			for (TreeNode<T> *c : node->child) {
				q.enqueue(c);
			}
			size--;
		}
	}
	return h;
}
