#include <iostream>
#include <vector>

using namespace std;

long long findMaxPairwiseProduct(vector<int>& numbers) {
	int max_idx1 = -1;
	for (int i = 0; i < numbers.size(); i++) {
		if (max_idx1 != -1 && numbers[i] > numbers[max_idx1]) max_idx1 = i;
	}
	int max_idx2 = -1;
	for (int i = 0; i < numbers.size(); i++) {
		if (max_idx2 != -1 && max_idx2 != max_idx1 && numbers[i] > numbers[max_idx2]) max_idx2 = i;
	}
	return ((long long)(numbers[max_idx1])) * numbers[max_idx2];
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
