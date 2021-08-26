class Solution {
public:

   bool subsetSum(vector<int> nums, int sum, int n)
   {
      bool dp[n + 1][sum + 1];

     //initializing first row
      for (int j = 0; j < sum + 1; j++)
         dp[0][j] = false;
    
     //initializing first column
      for (int i = 0; i < n + 1; i++)
         dp[i][0] = true;

      for (int i = 1; i < n + 1; i++) {
         for (int j = 1; j < sum + 1; j++) {
            if (nums[i - 1] <= j) {
               dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }

            else
               dp[i][j] = dp[i - 1][j];
         }
      }

      return dp[n][sum];
   }

   bool canPartition(vector<int>& nums) {

      int n = nums.size();

      //we cant divide odd sum array in two equal parts

      int sum = 0;
      for (int i = 0; i < n; i++)
         sum += nums[i];

      if (sum & 1)
         return false;

      return subsetSum(nums, sum / 2, n);
   }
};

TC: O(n*sum)
SC: O(n*sum)
