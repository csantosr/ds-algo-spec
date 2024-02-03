#include <iostream>

using namespace std;

void changePositions(int* a) {
	int f = a[0], s = a[1];
	a[0] = s;
	a[1] = f;
}

int main() {
	int arr[2] = {1,2};
	for (int n : arr) {
		cout << n << ' ';
	}
	cout << endl;
	changePositions(arr);
	for (int n : arr) {
		cout << n << ' ';
	}
	cout << endl;
}
