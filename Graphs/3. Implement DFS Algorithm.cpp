void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
        if (visited[u] == false)
            DFSRec(adj, u, visited);
}

void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    DFSRec(adj, s, visited);
}

When graph is disconnected, DFSRec function remains same only DFS function changes
void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
        if (visited[u] == false)
            DFSRec(adj, u, visited);
}

void DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    
    for (int i = 0; i < v; i++)   //checking if any vertex is unvisited (a vertex can be disconnected in case of disconnected graph)
      if(visited[i] = false;)
          DFSRec(adj, i , visited);
}
