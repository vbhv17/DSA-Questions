Using DFS:
// We maintain a dfsvis vector this time alongwith vis.
// As we traverse in dfs order we keep on marking vis and dfsvis as 1.
// If we have traversed a paricular node and we go back to the parent function, then we mark dfsvis of this node as 0.
  
Algorithm: 
// Create the graph using the given number of edges and vertices.
// Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
// Mark the current node as visited and also mark the index in recursion stack.
// Find all the vertices which are not visited and are adjacent to the current node. 
// Recursively call the function for those vertices, If the recursive function returns true, return true.
// If the adjacent vertices are already marked in the recursion stack then return true.
// Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. 
// Else if for all vertices the function returns false return false.

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool checkCycle(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
	{
	    vis[node]=1;
	    dfsvis[node]=1;
	
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	            if(checkCycle(it, vis, dfsvis, adj))
	                return true;
	        } 
	        else if(dfsvis[it]==1)
	        {
	            return true;
	        }    
	    }
	    
	    dfsvis[node]=0;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> vis(V,0);
	   	vector<int> dfsvis(V,0);
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	        if(checkCycle(i, vis, dfsvis, adj))
	   	            return true;
	   	    }    
	   	}
	   	return false;
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
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)                    //loop for calculating indegree of each vertex
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;                    
	        }
	    }
	    
	    for(int i=0;i<V;i++)                 //we push those vertexes with 0 indegree into the queue
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    int count=0;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        count++;
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    if (count==V) return false;                      //if number of vertexes in topological sort is equal to the number of vertex in the graph, it means that the graph is acyclic(no cycles), since topological sort is only for DAG. 
	    return true;
	}
	
};
