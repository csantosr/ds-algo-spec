#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using std::pow;
using std::make_pair;
using std::sort;

class DisjointSet {
private:
  vector<int> parents;
public:
  DisjointSet(int size) {
    for (size_t i = 0; i < size; i++) {
      parents.push_back(i);
    }
  }

  int find(int x) {
    if (parents[x] == x) return x;
    return find(parents[x]);
  }

  void unionSets(int x, int y) {
    int parentX = find(x), parentY = find(y);
    parents[parentX] = parentY;
  }
};

struct Edge {
  int idX, idY;
  double cost;

  Edge(int ix, int iy, pair<int, int> f, pair<int, int> t) : idX{ix}, idY{iy} {
    cost = sqrt(pow(f.first - t.first, 2) + pow(f.second - t.second, 2));
  }
};

bool compareEdges(const Edge &a, const Edge &b) {
  return a.cost < b.cost;
}

double minimum_distance(vector<int> x, vector<int> y) {
  vector<Edge> edges;
  for (size_t i = 0; i < x.size(); i++) {
    for (size_t j = i; j < x.size(); j++) {
      edges.push_back(
        Edge (
          i,
          j,
          make_pair(x[i], y[i]),
          make_pair(x[j], y[j])
        )
      );
    }
  }
  sort(edges.begin(), edges.end(), compareEdges);

  double result = 0.;
  DisjointSet forest(x.size());

  for(Edge e : edges) {
    if (forest.find(e.idX) != forest.find(e.idY)) {
      result += e.cost;
      forest.unionSets(e.idX, e.idY);
    }
  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << std::fixed << minimum_distance(x, y) << std::endl;
}
