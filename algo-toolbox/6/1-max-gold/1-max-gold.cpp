#include <iostream>
#include <vector>

using namespace std;

int maxGold(int W, int n, vector<int> gold) {
	vector<vector<int>> dp(W+1, vector<int>(n+1, 0));
	for (int i = 0; i <= W; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = 0;
	}

	for (int i=1; i<=n; ++i) {
		for (int w=1; w<=W; ++w) {
			dp[w][i] = dp[w][i-1];
			if (gold[i-1] <= w) {
				int val = dp[w - gold[i-1]][i-1] + gold[i-1];
				if (dp[w][i] < val) {
					dp[w][i] = val;
				}
			}
		}
	}
	return dp[W][n];
}

int main() {
	int W, n;
	cin >> W >> n;
	vector<int> gold;
	for (int i=0; i < n; ++i) {
		int v;
		cin >> v;
		gold.push_back(v);
	}
	cout << maxGold(W, n, gold);
	
	return 0;
}
