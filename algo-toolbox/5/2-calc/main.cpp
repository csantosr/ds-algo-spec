#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int findOperations(int n) {
	int dp[n+1];
	dp[1] = 0; // initial state
	vector<int> inter;
	for(int i = 2; i <= n; i++) {
		dp[i] = INT_MAX;


		if (i%2 == 0) {
			int x = dp[i/2];
			if (x+1 < dp[i]) {
				dp[i] = x+1;
			}
		}
		if (i%3 == 0) {
			int x = dp[i/3];
			if (x+1 < dp[i]) {
				dp[i] = x+1;
			}
		}
		int x = dp[i-1];
		if (x+1 < dp[i]) {
			dp[i] = x+1;
		}
	}
	int currentPointer = n;
	while(currentPointer > 1) {
		int candidateToCurrent;
		if (currentPointer % 2 == 0 && dp[currentPointer] == dp[currentPointer/2]+1) {
			candidateToCurrent = currentPointer/2;
		}
		if (currentPointer % 3 == 0 && dp[currentPointer] == dp[currentPointer/3]+1) {
			candidateToCurrent = currentPointer/3;
		}
		if (dp[currentPointer] == dp[currentPointer-1]+1) {
			candidateToCurrent = currentPointer-1;
		}
		inter.push_back(candidateToCurrent);
		currentPointer = candidateToCurrent;
	}
	cout << dp[n] << endl;
	for(int i = inter.size()-1; i >= 0; i--) {
		cout << inter[i] << ' ';
	}
	cout << n << endl;
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	findOperations(n);
	return 0;
}
