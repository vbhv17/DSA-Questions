Using DFS

DFSRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s]=true;
    for(int u: adj[s])
    {
        if(visited[u]==false)
            if(DFSRec(adj,u,visited,s)==true)
                return true;

        else if(u!=parent)
            return true;    
    }
    return false;
}

DFS(vector<int> adj, int v)
{
    for(int i=0;i<v;i++)
       visited[v]=false;

    for(int i=0;i<v;i++)
        if(visited[v]=false)
            if(DFSRec(adj,i,visited,-1)==true)
                return true;

    return false;        
}

TC:O(V+E)  AS:O(V)
