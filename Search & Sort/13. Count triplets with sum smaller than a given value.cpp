Refer Array Question 28 for naive and better solution:

Naive Approach : Find all possible triplets using 3 nested for loops
Better Approach: Find two elements with two nested loops and do binary search for third element
                 Check if sum of all three elements is less than given value

Optimal Solution: 
OP Explanation https://www.youtube.com/watch?v=9455buJlb_k&ab_channel=CodeLibrary
class Solution {
public:
  long long countTriplets(long long arr[], int n, long long X)
  {
    long long ans = 0;

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
      int left = i + 1;
      int right = n - 1;

      while (left < right) {

        int sum = arr[i] + arr[left] + arr[right];

        if (sum < X)
        {
          //all values on left will give total sum less than given sum since the array is sorted
          //so add all left triplets to ans 
          //and then increment left to check for next triplet
          ans += right - left;    
          left++;
        }

        else {
          right--;
        }
      }
    }
    return ans;
  }
};

TC: O(N^2)
SC :O(1)
