https://www.youtube.com/watch?v=oNTsS8lGDHw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21&ab_channel=takeUforwardtakeUforward

Bruteforce: O(N*N) approach:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n, e;
  cin >> n >> e;
  vector<pair<int, int>> adj[n];

  for (int i = 0; i < e; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});

  }

  int key[n], parent[n];
  bool mst[n];
  for (int i = 0; i < n; i++)
  {
    key[i] = INT_MAX;
    mst[i] = false;
    parent[i] = -1;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int edges = 0; edges < n - 1; edges++)
  {
    int u, mini = INT_MAX;

    for (int v = 0; v < n; v++)          //traversing over key array and finding minimum which is not a part of mst
    {
      if (mst[v] == false && key[v] < mini)
      {
        mini = key[v];
        u = v;
      }
    }

    mst[u] = true;

    for (auto it : adj[u])
    {
      int v = it.first;
      int w = it.second;
      if (mst[v] == false && w < key[v])
      {
        parent[v] = u;
        key[v] = w;
      }

    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << parent[i] << " - " << i << " - " << key[i] << endl;
  }

}

TC: O(N*N) SC:O(N)
  
  
  
Optimised Approach (Using Min Heap)
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

TC: O(NLogN)
SC: O(N)
