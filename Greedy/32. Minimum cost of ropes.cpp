https://www.youtube.com/watch?v=2pH6E9th0EY&ab_channel=CodeLibrary


Approach: We just follow greedy approach, at every step we need to connect two ropes with minimum value,
          so that cost is minimized.
          We use minheap to store all the ropes, at any point of time 2 ropes with minimum lengths,
          will be present at the top of the minheap
          
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<int>> pq;   //declaring a minheap 
        
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        
        long long cost=0; 
       //until we have 2 ropes to add, in the minheap if we have only 1 rope in minheap that means we have added all ropes into a single rope
        while(pq.size()>=2)               
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            cost = cost + first + second;
            pq.push(first+second);
        }
        
        return cost;
    }
};

TC: O(NLogN)  ~ For sorting
SC:O(N)   ~ For MinHeap
