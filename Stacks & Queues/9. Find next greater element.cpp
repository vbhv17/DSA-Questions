https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

Naive Approach: 
# For every element we traverse to its right and as soon as we find a greater element on right, we break the loop and print that element.
  
  vector<long long> nextLargerElement(vector<long long> arr, int n) {

    vector<long long> ans;
    for (int i = 0; i < n; i++)
    {
      int j;
      for (j = i + 1; j < n; j++)
      {
        if (arr[j] > arr[i])
        {
          ans.push_back(arr[j]);
          break;
        }
      }

      if (j == n)
        ans.push_back(-1);
    }

    return ans;
  }

TC:O(N*N)  SC:O(1)
  
  
Efficient Solution: Using stacks
// Based on stock span problem 
# Refer Notes

  vector<long long> nextLargerElement(vector<long long> arr, int n) {

    vector<long long> ans;
    stack <long long> s;
    s.push(arr[n - 1]);

    ans.push_back(-1);

    for (int i = n - 2 ; i >= 0 ; i--)
    {
      while (!s.empty() && arr[i] >= s.top())
        s.pop();

      if (s.empty())
        ans.push_back(-1);
      else
        ans.push_back(s.top());

      s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;

  }
  
TC:O(N)  SC:O(N)
