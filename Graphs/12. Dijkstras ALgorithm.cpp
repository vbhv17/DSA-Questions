// We have to find the shortest path between a source and every other node.
// Here the edge weights are different and the graph in undirected.
// We use a priorty queue (min-heap) which has the pair of {node, shortest distance} only
// We also have a distance array.

Solution:
#include<bits/stdc++.h>
using namespace std;
#define ll long long


void dijkstra(int src, int v, vector<pair<int, int>> adj[])
{
  vector<int> dist(v + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[src] = 0;
  pq.push({src, dist[src]});

  while (!pq.empty())
  {
    int node = pq.top().first;
    int weight = pq.top().second;
    pq.pop();

    for (auto it : adj[node])
    {
      if (dist[node] + it.second < dist[it.first])
      {
        dist[it.first] = dist[node] + it.second;
        pq.push({it.first, dist[it.first]});
      }
    }
  }

  for (int i = 1; i < v + 1; i++)
  {
    if (dist[i] == INT_MAX)
    {
      cout << "INF" << " ";
    }

    else
      cout << dist[i] << " ";
  }
}


int main()
{
  int v, e;
  cin >> v >> e;

  int src;
  cin >> src;

  vector<pair<int, int>> adj[v + 1];
  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijkstra(src, v, adj );
  return 0;

}

TC: O(V+E*LogV)   //logv due to priority queue
SC: O(V)          //Distance array and priority queue
