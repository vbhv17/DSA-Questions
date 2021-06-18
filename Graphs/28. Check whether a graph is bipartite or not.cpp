          A graph is bipartite if we can color whole all nodes of graph with 2 colors such that
           No two adjacent nodes should have the same color.
		  
             Inference: Graph with a odd length cycle can never be a bipartite graph,
             and a graph which does not have a odd length cycle is for sure a bipartite graph

Approach: We use BFS traversal to check if the graph is bipartite or not, instead of visited array here, we use a 
          color array which is initialized to -1. We color the source as 0, and its adjacents as 1
          If we encounter a vertex whose adjacent is the also of the same color, we return false.

BFS  https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10&ab_channel=takeUforwardtakeUforward

#include<bits/stdc++.h>
using namespace std;

bool bfsBipartite(int src, int V, vector<int> adj[], int color[])
{
  queue<int> q;
  color[src] = 1;
  q.push(src);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int it : adj[node])
    {
      if (color[it] == -1)
      {
        color[it] = 1 - color[node];
        q.push(it);
      }

      else if (color[it] == color[node])
      {
        return false;
      }
    }
  }

  return true;
}

bool isBipartite(int V, vector<int> adj[])
{
  int color[V];
  memset(color, -1, sizeof(color));

  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
      if (!bfsBipartite(i, V, adj, color))
        return false;
  }

  return true;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> adj[n];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isBipartite(n, adj))
    cout << "Bipartite";

  else
    cout << "Not bipartite";

  return 0;
}


TC: O(V+E)  //same as BFS 
SC: O(V+E) ~ Adjacency List
    O(V) ~ Color array
    O(V) ~ Queue


Solution 2: Using DFS       //Same logic as BFS
	https://www.youtube.com/watch?v=uC884ske2uQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11&ab_channel=takeUforwardtakeUforward

#include<bits/stdc++.h>
using namespace std;

bool dfsBipartite(int src, int V, vector<int> adj[], int color[])
{
  if (color[src] == -1)
    color[src] = 1;

  for (int it : adj[src])
  {
    if (color[it] == -1) {

      color[it] = 1 - color[src];
      if (!dfsBipartite(it, V, adj, color))
        return false;
    }

    else if (color[it] == color[src])
      return false;
  }

  return true;
}

bool isBipartite(int V, vector<int> adj[])
{
  int color[V];
  memset(color, -1, sizeof(color));

  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
      if (!dfsBipartite(i, V, adj, color))
        return false;
  }

  return true;
}


int main() {

  int n, m;
  cin >> n >> m;

  vector<int> adj[n];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isBipartite(n, adj))
    cout << "Bipartite";

  else
    cout << "Not bipartite";

  return 0;
}

TC: O(V+E) ~ DFS
SC: O(V+E) ~ Adjacency List
    O(V) ~ Color array
    O(V) ~ Recursion stack
