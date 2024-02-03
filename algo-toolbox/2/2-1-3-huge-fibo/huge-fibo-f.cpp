#include <iostream>
#include <deque>

using namespace std;

int hugeFiboNumber(long position, int modulo) {
	deque<int> lefts;
	lefts.push_back(0);
	lefts.push_back(1);
	lefts.push_back(1);
	long offset = 0;
	for (long i = 3; i <= position; ++i) {
		lefts.push_back((lefts[i-offset-1] + lefts[i-offset-2]) % modulo);
		lefts.pop_front();
		offset++;
	}
	return lefts.back();
}


int doubleFibonacci(long position, int modulo); 
int doubleFibonacciOdd(long position, int modulo) {
	long n = (position+1) / 2;
	long fn = (long)doubleFibonacci(n, modulo);
	long fn1 = (long)doubleFibonacci(n-1, modulo);
	return ((fn1 * fn1) + (fn * fn)) % modulo;
}


int doubleFibonacciEven(long position, int modulo) {
	long n = position / 2;
	long fn = (long)doubleFibonacci(n, modulo);
	long fn1 = (long)doubleFibonacci(n-1, modulo);
	return (fn * ((2*fn1) + fn)) % modulo;
}

int doubleFibonacci(long position, int modulo) {
	if (position <= 1) return position;
	if (position < 1000) return hugeFiboNumber(position, modulo);
	if ((position & 1) == 0) return doubleFibonacciEven(position, modulo);
	return doubleFibonacciOdd(position, modulo);
}

long pisano(int modulo) {
	long prev = 0;
	long curr = 1;
	long result = 0;

	for (int i = 0; i < modulo*modulo; i++) {
		long temp = curr;
		curr = (prev + curr) % modulo;
		prev = temp;

		if (prev == 0 && curr == 1) result = i+1;
	}
	return result;
}

int main() {
	long pos;
	int modulo;
	cin >> pos >> modulo;
	cout << pisano(modulo) << endl;
	if (modulo > 3) {
		pos = pos % pisano(modulo);
	}	
	cout << hugeFiboNumber(pos, modulo) << endl;
	return 0;
}
