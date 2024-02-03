/*
Munir Jojo - Verge
04 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			3_maximum_advertisement_revenue
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
