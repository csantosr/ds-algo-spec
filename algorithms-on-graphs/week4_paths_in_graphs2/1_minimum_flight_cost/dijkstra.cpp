#include <iostream>
#include <vector>
#include <queue>
#define NODE pair<int, int>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;
using std::greater;
using std::make_pair;

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  vector<int> dist(adj.size(), -1);
  vector<int> prev(adj.size(), -1);

  priority_queue<NODE, vector<NODE>, greater<NODE>> pq;
  pq.push(make_pair(0, s));
  dist[s] = 0;

  while (!pq.empty()) {
    int curr = pq.top().second;
    pq.pop();

    for (size_t i = 0; i < adj[curr].size(); i++) {
      int v = adj[curr][i];
      int w = cost[curr][i];

      if (dist[v] == -1 || dist[v] > dist[curr] + w) {
        dist[v] = dist[curr] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  return dist[t];
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
