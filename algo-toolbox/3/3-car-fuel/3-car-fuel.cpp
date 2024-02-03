#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int d, m, n;
	cin >> d;
	cin >> m;
	cin >> n;
	int distancePossible = m, refills = 0;
	int last_stop = 0;
	for (int i = 0; i < n; i++) {
		int stop;
		cin >> stop;
		if (stop - last_stop > m) {
			cout << -1;
			return 0;
		}
		if (stop >= distancePossible) {
			refills += 1;
			distancePossible += m;
		}
		last_stop = stop;
	}
	if (d - last_stop > m) {
		cout << -1;
		return 0;
	}
	if (distancePossible < d) refills++;
	cout << refills;
	return 0;
}
