#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[n+1];
	dp[0] = 0;
	
	for (int i = 1; i <= n; ++i) {
		int one = dp[i-1] + 1, two = INT_MAX, four = INT_MAX;
		if (i-2 >= 0) {
			two = dp[i-2] + 1;
		}
		if (i-4 >= 0) {
			four = dp[i-4] + 1;
		}
		dp[i] = min({one, two, four});
	}
	cout << dp[n];

	return 0;
}
