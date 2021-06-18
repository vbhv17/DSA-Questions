Approach:  A graph is bipartite if we can color whole all nodes of graph with 2 colors such that
           No two adjacent nodes should have the same color.
  
  Inference: Graph with a odd length cycle can never be a bipartite graph,
             and a graph which does not have a odd length cycle is for sure a bipartite graph

https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=10&ab_channel=takeUforwardtakeUforward

Using BFS: We take a color[] array and initialize it to -1 (indicating that no node is colred yet)
           Then we check for every node in the graph,  if it is not colored,
            we call bfsBipartite for it and color it with 1.
            Then we iterate over all its adjacents and check if they are colored with opposte color or not
              If they are already colored with the same color then we can say that the graph is not a bipartite graph.
       
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


Using DFS: https://www.youtube.com/watch?v=uC884ske2uQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11&ab_channel=takeUforwardtakeUforward
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
