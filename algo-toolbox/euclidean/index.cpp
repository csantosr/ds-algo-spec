#include <iostream>

using namespace std;

int euclidean(int a, int b) {
	if (b == 0) {
		return a;
	}
	int a_prime = a % b;
	return euclidean(b, a_prime);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "gcd(" << a << "," << b << "): " << euclidean(a, b);
	return 0;
}
