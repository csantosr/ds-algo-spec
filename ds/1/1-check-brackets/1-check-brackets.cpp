#include <cstddef>
#include <iostream>
#include <string>

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
	Stack<char> s = Stack<char>();
	Stack<int> openers = Stack<int>();
	string inp;
	cin >> inp;

	for (int i = 0; i < inp.size(); ++i) {
		if (inp[i] == '(' || inp[i] == '[' || inp[i] == '{') {
			s.push(inp[i]);
			openers.push(i);
		} else if (inp[i] == ')' || inp[i] == ']' || inp[i] == '}') {
			char *topPtr = s.pop();
			if (topPtr == NULL) {
				cout << i + 1;
				return 0;
			}
			char top = *topPtr;
			switch (top) {
				case '(':
					if (inp[i] != ')') {
						cout << i+1;
						return 0;
					}
					break;
				case '[':
					if (inp[i] != ']') {
						cout << i+1;
						return 0;
					}
					break;
				case '{':
					if (inp[i] != '}') {
						cout << i+1;
						return 0;
					}
					break;
			}
			openers.pop();
		}
	}

	if (s.empty()) {
		cout << "Success";
		return 0;
	}
	if (openers.top() == NULL) {
		cout << 1;
		return 0;
	}
	cout << *openers.top() + 1;
	return 0;
}
