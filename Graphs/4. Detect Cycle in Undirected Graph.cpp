Using BFS
    bool detectCycle(int s, int V, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        q.push({s, -1});
        vis[s]=1;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            
            q.pop();
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    q.push({it, node});
                    vis[it]=1;
                }
                
                else if(it!=par)
                {
                    return true;
                }
            }
            
        }
        
        return false;
        
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(detectCycle(i, V, adj, vis))
	              return true;
	        }
	    }
	}

Using DFS

bool detectCycle(int node , int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(detectCycle(it, node, adj, vis))
                    return true;
            }
            
            else if(it!=parent)
            {
                return true;
            }
        }
       
        return false;
        
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1 ,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(detectCycle(i, -1, adj, vis))
	              return true;
	        }
	    }
	    
	    return false;
	}

TC:O(V+E)  AS:O(V)
