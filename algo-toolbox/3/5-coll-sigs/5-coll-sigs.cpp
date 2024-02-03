#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct Segment {
	unsigned int left;
	unsigned int right;

	Segment(unsigned int l, unsigned int r) {
		left = l;
		right = r;
	}

	bool operator<(Segment const &other) const {
		return (right < other.right);
	}

	bool isContained(unsigned int point) {
		return left <= point && right >= point;
	}
};

int main() {
	int n;
	cin >> n;

	vector<Segment> unusedSegments;
	vector<unsigned int> pointsUsed;
	for (int i = 0; i < n; ++i) {
		unsigned int l, r;
		cin >> l >> r;
		unusedSegments.push_back(Segment(l,r));
	}
	sort(unusedSegments.begin(), unusedSegments.end());
	while (unusedSegments.size() > 0) {
		unsigned int point = unusedSegments[0].right;
		pointsUsed.push_back(point);
		vector<Segment> filtered;
		copy_if(unusedSegments.begin(), unusedSegments.end(), back_inserter(filtered), [point](Segment s) {
			return !s.isContained(point);
		});
		unusedSegments = filtered;
	}
	cout << pointsUsed.size() << endl;
	for (auto p : pointsUsed) {
		cout << p << ' ';
	}
	return 0;
}
