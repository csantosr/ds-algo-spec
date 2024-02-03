#include <iostream>
#include <vector>

using namespace std;

long long findMaxPairwiseProduct(vector<int>& numbers) {
	long long max = 0;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (((long long)numbers[i]) * numbers[j] > max) {
				max =  ((long long)numbers[i]) * numbers[j];
			}
		}
	}
	return max;
}

int main () {
	int n;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	cout << findMaxPairwiseProduct(numbers) << endl;
	return 0;
}
