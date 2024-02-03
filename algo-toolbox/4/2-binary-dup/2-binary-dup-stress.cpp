#include <chrono>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

short findIndex(unsigned int *numbers, unsigned short size, int find) {
	int minIndex = 0, maxIndex = size - 1;
	while (maxIndex >= minIndex) {
		int midIndex = floor((maxIndex + minIndex)/2);
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
	while(1) {
		auto start = chrono::high_resolution_clock::now();
		unsigned short n = rand()%(30000) + 1;
		cout << "n=" << n << endl;
		unsigned int numbers[n];
		for (unsigned short i = 0; i < n; ++i) {
			unsigned int num = rand()%(1000000000) + 1;
			numbers[i] = num;
		}
		unsigned short m = rand()%(100000) + 1;
		cout << "m=" << m << endl;
		short found[m];
		for (unsigned short j = 0; j < m; ++j) {
			unsigned int find = rand()%(1000000000) + 1;
			found[j] = findIndex(numbers, n, find);
			while(found[j] > 0 && numbers[found[j]] == numbers[found[j]-1]) found[j]--;
		}
		for (short f : found) {
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
		cout << "Durateion: " << duration.count() << endl;
	}
	return 0;
}
