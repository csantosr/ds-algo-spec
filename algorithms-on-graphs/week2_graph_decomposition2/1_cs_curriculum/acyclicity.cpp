#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool isCyclicTool(vector<vector<int> > &adj, vector<bool> &visited, int curr) {
  if (visited[curr]) return true;

  visited[curr] = true;
  bool FLAG = false;
  for (size_t i = 0; i < adj[curr].size(); i++) {
    if (isCyclicTool(adj, visited, adj[curr][i])) {
      return true;
    }
  }
  visited[curr] = false;

  return false;
}

int acyclic(vector<vector<int> > &adj) {
  vector<bool> visited(adj.size(), false);
  for (size_t i = 0; i < adj.size(); i++) {
    visited[i] = true;
    for (size_t j = 0; j < adj[i].size(); j++) {
      if(isCyclicTool(adj, visited, adj[i][j])) {
        return 1;
      }
    }
    visited[i] = false;
  }
  
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
