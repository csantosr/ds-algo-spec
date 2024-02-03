#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(string A, string B) {
	int aSize = A.length(), bSize = B.length();
	int dp[aSize + 1][bSize + 1];
	for (int i = 0; i <= aSize; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= bSize; j++) {
		dp[0][j] = j;
	}
	for (int j = 1; j <= bSize; ++j) {
		for (int i = 1; i <= aSize; ++i) {
			int insertion = dp[i][j-1] + 1;
			int deletion = dp[i-1][j] + 1;
			int match = dp[i-1][j-1];
			int mismatch = dp[i-1][j-1] + 1;
			if (A.at(i-1) == B.at(j-1)) {
				dp[i][j] = min({insertion, deletion, match});
			} else {
				dp[i][j] = min({insertion, deletion, mismatch});
			}
		}
	}
	return dp[aSize][bSize];
}

int main() {
	string A, B;
	cin >> A;
	cin >> B;
	cout << editDistance(A, B);
	return 0;
}
