Naive Approach : Find all possible triplets using 3 nested for loops
bool find3Numbers(int A[], int n, int X)
{
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (A[i] + A[j] + A[k] == X)
          return true;
      }
    }
  }
  return false;
}
TC: O(N^3)
SC :O(1)
  
Better Approach: Find two elements with two nested loops and do binary search for third element
bool find3Numbers(int A[], int n, int X)
{
  sort(A, A + n);     //Since we are gonna do binary search

  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      int rem = X - A[i] - A[j];

      int left = j + 1;
      int right = n - 1;

      while (left < right)
      {
        int mid = (left + right) / 2;

        if (A[mid] < rem) {
          left = mid + 1;
        }

        else if (A[mid] > rem) {
          right = mid - 1;
        }

        else {
          return true;
        }
      }

      if (left == right and A[left] == rem)
        return true;
    }
  }
  return false;
}

TC: O(N^2LogN)
SC : O(1)
  
Optimal Solution: Find first element with one loop and then use two pointer to find
                  if remaining two elements are present in the array
                  
  class Solution {
public:
  //Function to find if there exists a triplet in the
  //array A[] which sums up to X.
  bool find3Numbers(int A[], int n, int X)
  {

    sort(A, A + n);   //since we are gonna use 2 pointer

    for (int i = 0; i < n - 2; i++)
    {
      int left = i + 1;
      int right = n - 1;
      int rem = X - A[i];

      while (left < right)
      {
        if (A[left] + A[right] > rem) {
          right--;
        }

        else if (A[left] + A[right] < rem) {
          left++;
        }

        else {
          return true;
        }
      }
    }

    return false;
  }
};

TC: O(N^2 + NLognN)
SC: O(1)
