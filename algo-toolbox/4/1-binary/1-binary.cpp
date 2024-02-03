#include <iostream>
#include <cmath>
using namespace std;

int findIndex(unsigned int *numbers, unsigned int size, unsigned int find) {
	int minIndex = 0, maxIndex = size - 1;
	while (maxIndex >= minIndex) {
		int midIndex = (maxIndex + minIndex)/2;
		if (numbers[midIndex] == find) {
			return midIndex;
		} else if (numbers[midIndex] < find) {
			minIndex = midIndex + 1;
		} else {
			maxIndex = midIndex - 1;
		}
	}
	return -1;
}

int main() {
	unsigned int n;
	cin >> n;
	unsigned int numbers[n];
	for (unsigned short i = 0; i < n; ++i) {
		unsigned int num;
		cin >> num;
		numbers[i] = num;
	}
	unsigned int m;
	cin >> m;
	int found[m];
	for (unsigned int j = 0; j < m; ++j) {
		unsigned int find;
		cin >> find;
		found[j] = findIndex(numbers, n, find);
	}
	for (int f : found) {
		cout << f << ' ';
	}
	return 0;
}
