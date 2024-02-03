#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(int v, vector<vector<int>> &adj, vector<int> &ccs, int cc) {
  ccs[v] = cc;
  for(int n : adj[v]) {
    if (ccs[n] == 0) {
      explore(n, adj, ccs, cc);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 1;
  vector<int> ccs(adj.size(), 0);
  for (size_t i = 0; i < adj.size(); i++) {
    if (ccs[i] == 0) {
      explore(i, adj, ccs, res);
      res++;
    }
  }
  
  return res - 1;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
