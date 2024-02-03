#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = (rand() % 1000) + 1;
	vector<int> prices, clicks;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int p = (rand() % 100000);
		prices.push_back(p);
		cout << p << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		int c = (rand() % 100000);
		clicks.push_back(c);
		cout << c << ' ';
	}
	cout << endl;
	sort(prices.begin(), prices.end());
	sort(clicks.begin(), clicks.end());
	long result = 0;

	for (int i = 0; i < n; ++i) {
		result += prices[i]*clicks[i];
	}
	cout << result;
	return 0;
}
