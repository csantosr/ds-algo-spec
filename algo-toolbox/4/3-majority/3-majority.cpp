#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unsigned int n;
	cin >> n;
	unordered_map<unsigned int, unsigned int> map;
	for (unsigned int i = 0; i < n; ++i) {
		unsigned int num;
		cin >> num;
		map[num]++;
		if (map[num] > n/2) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
