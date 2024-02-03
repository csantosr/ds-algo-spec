#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Compound {
public:
	int weight;
	int cost;
	float ratio;

	Compound(int w, int c) {
		weight = w;
		cost = c;
		ratio = (float)(c)/w;
	}
	
	bool operator<(Compound const &other) const {
		return (ratio > other.ratio);
	}
};

int main() {
	cout << fixed;
	cout << setprecision(4);
	int n, W;
	cin >> n >> W;
	vector<Compound> compounds;
	for (int i = 0; i < n; ++i) {
		int w, c;
		cin >> c >> w;
		Compound newCompound = Compound(w,c);
		compounds.push_back(newCompound);
	}
	sort(compounds.begin(), compounds.end());
	float total = 0.0;
	float weightLeft = (float)W;
	for (auto const &c : compounds) {
		if (weightLeft == 0) {
			break;
		}
		float weightGrabbed = weightLeft > c.weight ? c.weight : weightLeft;
		total += weightGrabbed * c.ratio;
		weightLeft -= weightGrabbed;
	}
	cout << total;
	return 0;
}
