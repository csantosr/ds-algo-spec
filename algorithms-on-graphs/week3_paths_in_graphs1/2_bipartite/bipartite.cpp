#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int> color(adj.size(), -1);

  for (size_t i = 0; i < adj.size(); i++) {
    if (color[i] == -1) {
      color[i] = 0;
      queue<int> Q;
      Q.push(i);
      while (Q.size() != 0) {
        int curr = Q.front();
        Q.pop();
        for(int v : adj[curr]) {
          if (v == curr) return 0;
          if (color[v] == -1) {
            Q.push(v);
            color[v] = color[curr] == 0 ? 1 : 0;
          } else if (color[curr] == color[v]) {
            return 0;
          }
        }
      }
    }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
