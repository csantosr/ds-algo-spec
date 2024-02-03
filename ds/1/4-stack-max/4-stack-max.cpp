#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 100000;

template<typename T>
class Stack {
	T *arr;
	int head = 0;
	int capacity = SIZE;

public:
	Stack();
	~Stack();

	void push(T p);
	T* top();
	T* pop();
	bool empty();
};

template<typename T>
Stack<T>::Stack() {
	arr = new T[SIZE];
}

template<typename T>
Stack<T>::~Stack() {
	delete [] arr;
}

template<typename T>
void Stack<T>::push(T p) {
	if (head > SIZE) return;
	arr[head] = p;
	head++;
}

template<typename T>
T* Stack<T>::top() {
	if (head < 1) return NULL;
	return &arr[head-1];
}

template<typename T>
T* Stack<T>::pop() {
	T* lastTop = top();
	head--;
	return lastTop;
}

template<typename T>
bool Stack<T>::empty() {
	return head == 0;
}

int main() {
	Stack<int> s = Stack<int>();
	Stack<int> max = Stack<int>();
	vector<int> toPrint;
	int n;
	cin >> n;
	for (int i=0; i<=n; ++i) {
		string query;
		getline(cin, query);
		if (query[0] == 'p' && query[1] == 'u') {
			int toPush = stoi(query.substr(5));
			s.push(toPush);
			int* maxPtr = max.top();
			if (maxPtr == NULL || toPush > *maxPtr) {
				max.push(toPush);
			} else {
				max.push(*maxPtr);
			}
		} else if (query[0] == 'p') {
			s.pop();
			max.pop();
		} else if (query[0] == 'm') {
			int* maxPtr = max.top();
			if (maxPtr == NULL) {
				toPrint.push_back(-1);
				continue;
			}
			toPrint.push_back(*maxPtr);
		}
	}
	for (int p : toPrint) {
		cout << p << endl;
	}
	return 0;
}
