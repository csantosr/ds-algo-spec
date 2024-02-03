#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int comparePapers(string a, string b) {
	int ab = stoi(a + b), ba = stoi(b + a);
	return ab > ba ? 1 : 0;
}

int main () {
	int n;
	cin >> n;
	vector<string> papers;
	for (int i = 0; i < n; ++i) {
		string p;
		cin >> p;
		papers.push_back(p);
	}
	sort(papers.begin(), papers.end(), comparePapers);
	for (string p : papers) {
		cout << p;
	}
	return 0;
}
