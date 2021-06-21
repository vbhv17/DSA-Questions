https://www.youtube.com/watch?v=4ggF3tXIAp0
https://leetcode.com/problems/4sum/submissions/

Naive Solution:
Use 4 nested loops and store the answer in as et since we dont need duplicate quads
TC: O(N^4) SC: O()
  
Approach 2: 
3 ptr + Binary Search
We use 3 ptrs to select first 3 elements of the quad, for the last element,
we apply binary search over remaining array.
  
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    int n = nums.size();
    int currsum = 0;
    int rem = 0;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
      for (int j = i + 1; j < n - 2; j++)
      {
        for (int k = j + 1; k < n - 1; k++)
        {
          currsum = nums[i] + nums[j] + nums[k];
           
            if (currsum > target) continue;   //Boundary case
            
          //Applying Binary Search on right of k to find rem
          rem = target - currsum;

          int low = k + 1;
          int high = n - 1;

          while (low < high)
          {
            int mid = (low + high) / 2;

            if (nums[mid] == rem)
            {
              vector<int> quad(4, 0);
              quad.push_back(nums[i]);
              quad.push_back(nums[j]);
              quad.push_back(nums[k]);
              quad.push_back(nums[mid]);
              ans.push_back(quad);
              continue;
            }

            else if (nums[mid] < rem)
            {
              low = mid + 1;
            }

            else
            {
              high = mid - 1;
            }
          }


        }
      }
    }

    return ans;
        
    }
};

TC: O(N^3LogN) + O(NLogN)
SC: O(1)
  
Approach 3: Efficient: Two pointer with left and right pointer

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size();

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
      for (int j = i + 1; j < n - 2; j++)
      {

        int target2 = target - nums[i] - nums[j];

        int left = j + 1;
        int right = n - 1;

        while (left < right)
        {
          if (nums[left] + nums[right] < target2)
            left++;
          else if (nums[left] + nums[right] > target2)
            right--;
          else
          {
            vector<int> quad(4, 0);
            quad[0] = nums[i];
            quad[1] = nums[j];
            quad[2] = nums[left];
            quad[3] = nums[right];
            ans.push_back(quad);

            while (left < right and nums[left] == quad[2])
              left++;

            while (left < right and nums[right] == quad[3])
              right--;
          }
        }

        while (j + 1 < n and nums[j + 1] == nums[j])    //for corner case [2,2,2,2,2]  https://youtu.be/4ggF3tXIAp0?t=1050
          ++j;
      }

      while (i + 1 < n and nums[i + 1] == nums[i])
        ++i;
    }

    return ans;
  }

};

TC: O(N^3) + O(NLogN)
SC: O(1)
