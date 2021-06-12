Naive Solution:  Traverse all subarrays and update the minimum subarray with sum > x encountered so far. 
//code by vbhv17
class Solution {
public:

  int sb(int arr[], int n, int x)
  {
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
        sum = sum + arr[j];
        if (sum > x)
        {
          ans = min(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};
 TC: O(N*N)
 SC: O(1)
 
 Efficient Solution: https://www.youtube.com/watch?v=jKF9AcyBZ6E&t=455s&ab_channel=NickWhite
 Based on: 2 pointer, Sliding Window
 class Solution {
public:

  int sb(int arr[], int n, int x)
  {
    int sum = 0;
    int left = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; right++)
    {
      sum += arr[right];

      while (sum > x)
      {
        ans = min(ans, right - left + 1);
        sum -= arr[left];
        left++;
      }
    }

    return ans;
  }
};

TC: O(N)
 SC: O(1)
 
