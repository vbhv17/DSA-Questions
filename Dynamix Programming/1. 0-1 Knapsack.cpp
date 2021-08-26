Method 1 :- Recursive Code:
int knapSack(int W, int wt[], int val[], int n) 
    { 
        //Base Condition
        if(n==0 || W==0)
          return 0;
        
        if(wt[n-1]<=W){
            return max((val[n-1]+knapSack(W-wt[n-1], wt, val, n-1)), knapSack(W, wt, val, n-1));
        }
        
        else
          return knapSack(W, wt, val, n-1);
          
    }

It should be noted that the above function computes the same sub-problems again and again. 
The time complexity of this naive recursive solution is exponential (2^n).  
    



Time Complexity: O(2n). 
As there are redundant subproblems.
Auxiliary Space :O(1). 
As no extra data structure has been used for storing values.
    

METHOD 2:- Memoization (Top-Down)
class Solution
{
public:
   //Function to return max value that can be put in knapsack of capacity W.
   int dp[1001][1001];
   int solve(int W, int wt[], int val[], int n) {
      //Base Condition
      if (n == 0 || W == 0)
         dp[][]

         if (dp[n][W] != -1)
            return dp[n][W];


         else if (wt[n - 1] <= W) {
            return dp[n][W] = max((val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)), knapSack(W, wt, val, n - 1));
         }

         else
            return dp[n][W] = knapSack(W, wt, val, n - 1);
   }

   int knapSack(int W, int wt[], int val[], int n)
   {
      dp[n + 1][W + 1];
      memset(dp, -1, sizeof (dp));
      return solve(W, wt, val, n);
   }
};

Time Complexity: O(N*W). 
As redundant calculations of states are avoided.
Auxiliary Space: O(N*W). 
The use of 2D array data structure for storing intermediate states



METHOD3:- Optimised using DP (Bottom Up)
class Solution
{
public:
   //Function to return max value that can be put in knapsack of capacity W.
   int dp[1001][1001];
   int solve(int W, int wt[], int val[], int n) {

      for (int i = 0; i < n + 1; i++)
         dp[i][0] = 0;

      for (int j = 0; j < W + 1; j++)
         dp[0][j] = 0;

      for (int i = 1; i < n + 1; i++) {
         for (int j = 1; j < W + 1; j++) {
            if (wt[i - 1] <= j) {
               dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }

            else {
               dp[i][j] = dp[i - 1][j];
            }
         }
      }

      return dp[n][W];
   }

   int knapSack(int W, int wt[], int val[], int n)
   {
      dp[n + 1][W + 1];
      memset(dp, -1, sizeof (dp));
      return solve(W, wt, val, n);
   }
};

Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
    
    
Method 4 :-  We use the dynamic programming approach but with optimized space complexity .
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
	// making and initializing dp array
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],
							dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W]; // returning the maximum value of knapsack
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}

Time Complexity: O(N*W). As redundant calculations of states are avoided.
Auxiliary Space: O(W) As we are using 1-D array instead of 2-D array.
