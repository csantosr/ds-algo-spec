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
	T top();
	T pop();
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
T Stack<T>::top() {
	if (head < 1) return ' ';
	return arr[head-1];
}

template<typename T>
T Stack<T>::pop() {
	char lastTop = top();
	head--;
	return lastTop;
}

template<typename T>
bool Stack<T>::empty() {
	return head == 0;
}

