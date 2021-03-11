Approach: We traverse every element from left to right and we dind out maximum subarray that must end with this element. Our final ans is the maximum of this element and this element + subarray till this element

int maxSubarraySum(int arr[], int n)
{
  int res = arr[0];
  for (int i = 0; i < n; i++)
  {
    int curr = 0;

    for (int j = i; j < n; j++)
    {
      curr = curr + arr[i];
      res = max(res, curr);
    }

  }

  return res;
}

TC:O(N) AS:O(1)
