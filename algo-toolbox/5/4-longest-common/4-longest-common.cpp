#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(int *A, int aPointer, int *B, int bPointer, vector<vector<int>> &dp) {
	if (aPointer == 0 || bPointer == 0) {
		return 0;
	}
	if (A[aPointer-1] == B[bPointer-1]) {
		return dp[aPointer][bPointer] = longestCommonSubsequence(A, aPointer-1, B, bPointer-1, dp) + 1;
	}
	if (dp[aPointer][bPointer] != -1) {
		return dp[aPointer][bPointer];
	}
	return dp[aPointer][bPointer] = max(longestCommonSubsequence(A, aPointer-1, B, bPointer, dp), longestCommonSubsequence(A, aPointer, B, bPointer-1, dp));
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i<n; i++) {
		cin >> A[i];
	}
	int m;
	cin >> m;
	int B[m];
	for (int i = 0; i<m; i++) {
		cin >> B[i];
	}
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	cout << longestCommonSubsequence(A, n, B, m, dp);
	return 0;
}
