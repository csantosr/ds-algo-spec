#include <iostream>
#include <vector>

using namespace std;

int getFiboLastDigit(int position) {
	vector<int> lastDigits;
	lastDigits.push_back(0);
	lastDigits.push_back(1);

	for (int i = 2; i <= position; ++i) {
		lastDigits.push_back((lastDigits[i-1] + lastDigits[i-2]) % 10);
	}

	return lastDigits.back();
}

int main() {
	int pos;
	cin >> pos;
	cout << getFiboLastDigit(pos);
}
