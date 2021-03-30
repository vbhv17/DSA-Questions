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
