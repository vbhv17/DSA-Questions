Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv,
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Topological sort using Using DFS and a stack:
// We can modify DFS to find Topological Sorting of a graph. 
// In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices.
// In topological sorting, we use a temporary stack. We don’t print the vertex immediately, 
// we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
// Finally, print contents of the stack. Note that a vertex is pushed to stack 
// only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	 void dfsTopo(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
	 {
	     vis[node]=1;
	     for(auto it : adj[node])
	     {
	         if(!vis[it])
	         {
	             dfsTopo(it, vis, st, adj);
	         }
	     }
	     st.push(node);
	 }
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfsTopo(i, vis, st, adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};


Using BFS: Kahns Algorithm
// A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
// Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length.
// Now let S be the longest path from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u and no outgoing edge from v, 
// if this situation had occurred then S would not have been the longest path
// => indegree(u) = 0 and outdegree(v) = 0

// Algorithm: Steps involved in finding the topological ordering of a DAG:
// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.
    // Increment count of visited nodes by 1.
    // Decrease in-degree by 1 for all its neighboring nodes.
    // If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
// Step 4: Repeat Step 3 until the queue is empty.
// Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
  
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    vector<int> topo;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};
