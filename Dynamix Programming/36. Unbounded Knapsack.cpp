Its an unbounded knapsack problem as we can use 1 or more instances of any resource. A simple 1D array, say dp[W+1] can be used such that dp[i] stores the maximum value which can achieved using all items and i capacity of knapsack. Note that we use 1D array here which is different from classical knapsack where we used 2D array. Here number of items never changes. We always have all items available.
We can recursively compute dp[] using below formula

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W+1];
        
        memset(dp, 0, sizeof dp);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<W+1;j++){
                if(wt[i]<=j){
                    dp[j]= max(dp[j], dp[j-wt[i]]+val[i]);
                }
            }
        }
        
        return dp[W];
        
    }
};
