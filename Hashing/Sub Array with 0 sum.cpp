Naice Approach:
# Consider every element as starting of a subarray and find the sum of all the sub arrays. If at any point sum equals 0 return true else return false
bool subArrayExists(int arr[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      int curr_sum = 0;
      for (int j = i; j < n; j++)
      {
        curr_sum += arr[j];
        if (curr_sum == 0)
          return true;
      }
    }

    return false;
  }

TC: O(nxn) AS:O(1) 
  
Efficient Solution: 
# Refer Notes
  bool subArrayExists(int arr[], int n)
  {
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
      pre_sum += arr[i];
      if (s.find(pre_sum) != s.end())
        return true;

      if (pre_sum == 0)
        return true;

      s.insert(pre_sum);

    }
    return false;
  }

TC:O(N)  AS:O(N)
