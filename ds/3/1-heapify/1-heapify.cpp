#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

struct swapElement {
	int from, to;
};

void swap(int* a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
} 

void heapify(int arr[], int size, int i, vector<swapElement>& swaps) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if (left<size && arr[left] < arr[largest]) {
		largest = left;
	}
	if (right<size && arr[right] < arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		swapElement s;
		s.from = i;
		s.to = largest;
		swaps.push_back(s);
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest, swaps);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	vector<swapElement> swaps;
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	int lastParent = (n/2)-1;
	for (int i=lastParent; i>=0; --i) {
		heapify(arr, n, i, swaps);
	}
	cout << swaps.size() << endl;
	for (auto sw : swaps) {
		cout << sw.from << ' ' << sw.to << endl;
	}
	return 0;
}
