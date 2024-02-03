#include <iostream>

using namespace std;

long euclidean(long a, long b) {
	if (b == 0) {
		return a;
	}
	int a_prime = a % b;
	return euclidean(b, a_prime);
}

int main() {
	long a, b;
	cin >> a >> b;
	cout << euclidean(a, b);
	return 0;
}
