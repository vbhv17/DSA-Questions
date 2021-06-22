Approach: We have an unsorted array, we store every element of this unsorted array with its index 
          in a vector of pairs. Now we sort this vector, we get elements in sorted order.
          No we try to convert this sorted vector to the original array.
          We count the no of swaps we do, in order to do this
                    
 https://www.youtube.com/watch?v=1BxbBgNSwHo&ab_channel=CodeLibrary
           
class Solution
{
public:
  //Function to find the minimum number of swaps required to sort the array.
  int minSwaps(vector<int>&nums)
  {
    int n = nums.size();
    vector<pair<int, int>> v(n) ;

    for (int i = 0; i < n; i++)
      v[i] = {nums[i], i};

    sort(v.begin(), v.end());

    int c = 0;
    for (int i = 0; i < n; i++)
    {
      if (i == v[i].second)
        continue;
      else {
        c++;
        swap(v[i], v[v[i].second]);
        i--;
      }

    }
    return c;
  }
};

TC: O(NlogN)
SC: O(N)
