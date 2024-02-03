#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Response {
	int min, max;
};

int calculate(int a, int b, char op) {
	if (op == '+') return a+b;
	else if (op == '-') return a-b;
	return a*b;
}

Response getMinMax(vector<vector<int>> M, vector<vector<int>> m, int i, int j, vector<char> operators) {
	int min_value = INT_MAX, max_value = INT_MIN;
	for (int k=i; k<j; k++) {
		int a = calculate(M[i][k], M[k+1][j], operators[k]);
		int b = calculate(M[i][k], m[k+1][j], operators[k]);
		int c = calculate(m[i][k], M[k+1][j], operators[k]);
		int d = calculate(m[i][k], m[k+1][j], operators[k]);
		min_value = min({a, b, c, d, min_value});
		if (a > max_value) max_value = a;
		if (b > max_value) max_value = b;
		if (c > max_value) max_value = c;
		if (d > max_value) max_value = d;
	}
	Response r;
	r.min = min_value;
	r.max = max_value;
	return r;
}

int getMaxValue(vector<int> operands, vector<char> operators) {
	int n = operands.size();
	vector<vector<int>> m(n+1, vector<int>(n+1, 0)), M(n+1, vector<int>(n+1, 0));
	for (int i=0; i<n; ++i) {
		m[i][i] = operands[i];
		M[i][i] = operands[i];
	}

	for (int s=1; s<n; s++) {
		for (int i=0; i<n-s; ++i) {
			int j = i + s;
			Response r = getMinMax(M, m, i, j, operators);
			m[i][j] = r.min;
			M[i][j] = r.max;
		}
	}

	return M[0][n-1];
}

int main() {
	vector<char> operators;
	vector<int> operands;
	string expression;
	cin >> expression;
	for (int i=0; i < expression.length(); ++i) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
			operators.push_back(expression[i]);
		} else {
			operands.push_back(expression[i] - '0');
		}
	}
	cout << getMaxValue(operands, operators);
}
