#include <iostream>
#include <vector>

using namespace std;

long long fiboNumber(int position) {
	vector<long long> F;
	if (position == 0) {
		return 0;
	}
	F.push_back(0);
	F.push_back(1);
	for (int i = 2; i <= position; ++i) {
		F.push_back(F[i-1] + F[i-2]);
	}
	return F.back();
}

int main() {
	int n;
	cin >> n;
	cout << fiboNumber(n);
	return 0;
}
