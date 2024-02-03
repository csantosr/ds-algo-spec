#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int src = 0;
  vector<int> dist(adj.size(), -1);
  dist[src] = 0;

  for (size_t i = 0; i < adj.size() - 1; i++) {
    for (size_t from = 0; from < adj.size(); from++) {
      for(size_t toIdx = 0; toIdx < adj[from].size(); toIdx++) {
        int to = adj[from][toIdx];
        int w = cost[from][toIdx];
        if (dist[from] != -1 && (dist[to] == -1 || dist[from] + w < dist[to]))
          dist[to] = dist[from] + w;
      }
    }
  }

  for (size_t from = 0; from < adj.size(); from++) {
    for(size_t toIdx = 0; toIdx < adj[from].size(); toIdx++) {
      int to = adj[from][toIdx];
      int w = cost[from][toIdx];
      if (dist[from] != -1 && (dist[to] == -1 || dist[from] + w < dist[to]))
        return 1;
    }
  }
  
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
