// We use Topological Sorting. 
// We initialize distances to all vertices as minus infinite and distance to source as 0,
// then we find a topological sorting of the graph. 
// Topological Sorting of a graph represents a linear ordering of the graph (Veryex with 0 indegree comes first in topological sort order)
// Once we have topological order (or linear representation), we one by one process all vertices in topological order. 
// For every vertex being processed, we update distances of its adjacent using distance of current vertex.
  
// We find topo sort and store that order in stack, then we pass this stack to shortest path function which processes
// all the elements of the stack and sets the longest distances of its adjacents. Does this until the stack is not empty.

Solution:

#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
  vis[node] = 1;

  for (auto it : adj[node])
  {
    if (!vis[it.first])
    {
      findTopoSort(it.first, vis, adj, st);
    }
  }

  st.push(node);

}
void shortestPath(int src, int v, vector<pair<int, int>>adj[])
{
  vector<int> vis(v, 0);
  stack<int> st;

  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      findTopoSort(i, vis, adj, st);
    }
  }

  vector<int> dist(v, INT_MIN);
  dist[src] = 0;

  while (!st.empty())
  {
    int node = st.top();
    st.pop();

    if (dist[node] != INT_MIN)
    {
      for (auto it : adj[node])
      {
        if (dist[node] + it.second > dist[it.first])
        {
          dist[it.first] = dist[node] + it.second;
        }
      }
    }

  }

  for (int i = 0; i < v; i++)
  {
    if (dist[i] == INT_MIN)
      cout << "INF" << " ";
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

  vector<pair<int, int >> adj[v];

  for (int i = 0; i < e; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
  }

  shortestPath(src, v, adj);
  return 0;

}

TC: O(V+E)  ~ For topo sort and O(V+E) for BFS Like Algo for finding longest path  ~ O(V+E)
SC: O(V) for stack + O(V) for distance array ~ O(V)
