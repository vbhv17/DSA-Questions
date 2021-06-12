https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1#

Approach 1: Naive
Simply traverse the array and find x, if x is found return its index else return -1
Here we are not using the idea that adjacent elements differ by atmost k


Approach 2: Efficient Solution
https://www.youtube.com/watch?v=KtrAWsfyBaA&ab_channel=CodeLibrary
https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

At every iteration we calculate the minimum number of steps that can be skipped to reach x by the formula abs((x - arr[i]) / k  where x is the target and
                                                                                                              k is the max diff between adjacent elements
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
  int i = 0;
  while (i < n)
  {
    if (arr[i] == x)
      return i;

    //calculating minimum steps that can be jumped to reach x
    //in worst case we have to skip minimum one step
    int minSteps = max(1, abs((x - arr[i]) / k));
    i = i + minSteps;
  }

  return -1;
}

  TC: O(N)  ~ But we skip a lot of comparisons so complexity is much lesser than O(N)
  SC: O(1)                                                                                                           
                                                                                                              
                                                                                                              
                                                                                                              
