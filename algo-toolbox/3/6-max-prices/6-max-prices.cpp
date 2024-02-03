#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int n;
	cin >> n;
	unsigned int sum = 0;
	unsigned int current = 0;
	vector<unsigned int> numbers;
	while (sum < n) {
		current += 1;
		if (sum + current > n) {
			numbers[numbers.size()-1] = n + numbers.back() - sum;
			sum = n;
			break;
		}
		sum += current;
		numbers.push_back(current);
	}
	cout << numbers.size() << endl;
	for (unsigned int i : numbers) {
		cout << i << ' ';
	}
	return 0;
}
