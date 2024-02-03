#include <climits>
#include <iostream>

using namespace std;

int findOperations(int n) {
	int dp[n+1];
	dp[1] = 0; // initial state
	
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
		cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << findOperations(n);
	return 0;
}
