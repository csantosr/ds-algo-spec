#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> prices, clicks;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		prices.push_back(p);
	}
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		clicks.push_back(c);
	}
	sort(prices.begin(), prices.end());
	sort(clicks.begin(), clicks.end());
	long result = 0;

	for (int i = 0; i < n; ++i) {
		result += prices[i]*clicks[i];
	}
	cout << result;
	return 0;
}
