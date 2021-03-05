Approach One: Find all subarray sums starting from every element.
  Return the max sum as result
  
  int maxSubarraySum(int arr[], int n)
{
  int res = arr[0];
  for (int i = 0; i < n; i++)
  {
    int curr = 0;

    for (int j = 0; j < n; j++)
    {
      curr = curr + arr[i];
      res = max(res, curr);
    }

  }

  return res;
}

TC:O(N*N)  AS:O(1)
  
  
Approach 2: Kadane's Algorithm
  Traverse from left to right and for every element we find out max sum of a subarray that must end with this element
  Final answer is maximum out of both these elements.
    int maxSubarraySum(int arr[], int n) {

  int res = arr[0];
  int maxEnding = arr[0];

  for (int i = 1; i < n; i++)
  {
    maxEnding = max(maxEnding + arr[i], arr[i]);
    res = max(res, maxEnding);

  }

  return res;

}

TC:O(N)  AS:O(1)
