Approach: We have to basically find the number of disconnected components in the graph
          If no of wires is less than the number of computers-1 then we can return -1
          
class Solution {
public:

  void dfs(int node, vector<int> adj[], vector<int> &vis)
  {
    vis[node] = 1;

    for (auto it : adj[node])
    {
      if (!vis[it])
        dfs(it, adj, vis);
    }
  }


  int makeConnected(int n, vector<vector<int>>& connections) {

    vector<int> adj[n];
    int m = connections.size();

    if (m < n - 1) return -1;

    for (int i = 0; i < connections.size(); i++)
    {
      int n1 = connections[i][0];
      int n2 = connections[i][1];

      adj[n1].push_back(n2);
      adj[n2].push_back(n1);
    }

    int count = 0;

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        count++;
        dfs(i, adj, vis);
      }
    }

    return count - 1;
  }
};

TC:O(V+E) ~ DFS
SC:O(V+E) ~ Adjacency list 
