First Version: When Source is given
void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] == false;

    queue<int> q;
    visited[s] = true;                 //marking source as visited
    q.push(s);                         //pushing source in the queue
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])          //traversing through all adjacents of u
        {
            if (visited[v] == false)  //if an adjacent is not visited
            {
                visited[v] = true;
                q.push(v);            //mark as visited and push it into the queue
            } 
        }
    }
}

TC: O(V+E)   AS:O(N)
  
  
Second Version: When Source is not given
void BFS(vector<int> adj[], int s, bool visited[])
{

    queue<int> q;
    visited[s] = true;                 //marking source as visited
    q.push(s);                         //pushing source in the queue
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])          //traversing through all adjacents of u
        {
            if (visited[v] == false)  //if an adjacent is not visited
            {
                visited[v] = true;
                q.push(v);            //mark as visited and push it into the queue
            }
        }
    }
}


void BFSDis(vector<int> adj[], int v)
{
    bool visited[v + 1];

    for (int i = 0; i < v; i++)
        visited[i] == false;

    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            BFS(adj, i, visited);
}
  
