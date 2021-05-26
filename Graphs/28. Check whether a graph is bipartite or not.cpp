Solution: We use BFS traversal to check if the graph is bipartite or not, instead of visited array here, we use a 
          color array which is initialized to -1. We color the source as 0, and its adjacents as 1
          If we encounter a vertex whose adjacent is the also of the same color, we return false.


bool checkBipartite(int src, vector<int>adj[], vector<int> &color)
    {
        
	    queue<int> q;
	    q.push(src);
	    color[src]=0;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto it : adj[node])
	        {
	            if(color[it]==-1)
	            {
	                color[it]=!color[node];
	                q.push(it);
	            }
	            
	            if(color[it]==color[node])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	            if(!checkBipartite(i, adj, color))
	                return false;
	    }
	    
	    return true;
	    
	}

TC: O(V+E)  //same as BFS 
SC: O(V)


Solution 2: Using DFS       //Same logic as BFS
bool checkBipartite(int node, vector<int>adj[], vector<int> &color)
{

  for (auto it : adj[node])
  {
    if (color[it] == -1)
    {
      color[it] = !color[node];

      if (!checkBipartite(it, adj, color))
        return false;
    }

    else if (color[it] == color[node])
      return false;

  }

  return true;
}
bool isBipartite(int V, vector<int>adj[]) {
  vector<int> color(V + 1, -1);
  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
      if (!checkBipartite(i, adj, color))
        return false;
  }

  return true;

}
