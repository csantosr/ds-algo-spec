#include <cstddef>
#include <iostream>

using namespace std;

void swapInArr(unsigned int a, unsigned int b, unsigned int* arr) {
	unsigned int aVal = arr[a], bVal = arr[b];
	arr[a] = bVal;
	arr[b] = aVal;
}

void quick3(unsigned int* num, unsigned int start, unsigned int end) {
	if (end - start <= 0) {
		return;
	}
	unsigned int p = rand()%(end-start+1) + start;
	swapInArr(start, p, num);
	p = start;
	unsigned int eq = start, ls = start, gt = start;
	for (unsigned int i=start+1; i<=end; ++i) {
		if (num[i] == num[p]) {
			swapInArr(i, eq+1, num);
			eq++;
			gt++;
		} else if (num[i] > num[p]) {
			swapInArr(i, gt+1, num);
			gt++;
		} else {
			swapInArr(i, eq+1, num);
			gt++;
			swapInArr(eq+1, ls+1, num);
			eq++;
			ls++;
		}
	}
	if (p < ls) {
		swapInArr(p, ls, num);
		unsigned int newP = ls, newLs = p;
		p = newP;
		ls--;
	}
	if (start < ls) quick3(num, start, ls);
	if (eq+1 < gt) quick3(num, eq+1, gt);
}

int main() {
	unsigned int n;
	cin >> n;
	unsigned int numbers[n];
	for (unsigned int i=0; i<n; ++i) {
		cin >> numbers[i];
	}
	quick3(numbers, 0, n-1);
	for (unsigned int x : numbers) {
		cout << x << ' ';
	}
	cout << endl;
}
