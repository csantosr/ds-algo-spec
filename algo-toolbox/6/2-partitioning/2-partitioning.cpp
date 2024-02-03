#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isItPossible(int* items, int n, int a, int b, int c, unordered_map<string, bool> &dp) {
	if (a==0 && b==0 && c==0) return true;

	if (n < 0) return false;

	string key = to_string(a) + '#' + to_string(b) + '#' + to_string(c);
	if (dp.count(key) != 0) {
		return dp.at(key);
	}

	bool A = false, B = false, C = false;
	if (a - items[n] >= 0) {
		A = isItPossible(items, n-1, a - items[n], b, c, dp);
	}
	if (!A && b - items[n] >= 0) {
		B = isItPossible(items, n-1, a, b - items[n], c, dp);
	}
	if (!A && !B && c - items[n] >= 0) {
		C = isItPossible(items, n-1, a, b, c - items[n], dp);
	}
	dp[key] = A || B || C;
	return A || B || C;
}

int main() {
	int n;
	cin >> n;
	int items[n];
	int sum = 0;
	unordered_map<string, bool> dp;
	for (int i=0; i<n; i++) {
		cin >> items[i];
		sum += items[i];
	}
	if (sum%3 != 0 || n < 3 || !isItPossible(items, n-1, sum/3, sum/3, sum/3, dp)) {
		cout << 0;
		return 0;
	}

	cout << 1;

	return 0;
}
