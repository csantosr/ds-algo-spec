#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(int *A, int aPointer, int *B, int bPointer, int *C, int cPointer, vector<vector<vector<int>>> &dp) {
	if (aPointer == 0 || bPointer == 0 || cPointer == 0) {
		return 0;
	}
	if (A[aPointer-1] == B[bPointer-1] && A[aPointer-1] == C[cPointer-1]) {
		return dp[aPointer][bPointer][cPointer] = longestCommonSubsequence(A, aPointer-1, B, bPointer-1, C, cPointer-1, dp) + 1;
	}
	if (dp[aPointer][bPointer][cPointer] != -1) {
		return dp[aPointer][bPointer][cPointer];
	}
	int a = longestCommonSubsequence(A, aPointer-1, B, bPointer,   C, cPointer,   dp);
	int b = longestCommonSubsequence(A, aPointer,   B, bPointer-1, C, cPointer,   dp);
	int c = longestCommonSubsequence(A, aPointer,   B, bPointer,   C, cPointer-1, dp);
	int maxi = a;
	if (b > maxi) maxi = b;
	if (c > maxi) maxi = c;

	return dp[aPointer][bPointer][cPointer] = maxi;
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
	int l;
	cin >> l;
	int C[l];
	for (int i = 0; i<l; i++) {
		cin >> C[i];
	}
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1, -1)));
	cout << longestCommonSubsequence(A, n, B, m, C, l, dp);
	return 0;
}
