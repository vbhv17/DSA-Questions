https://leetcode.com/problems/longest-consecutive-sequence/submissions/

# Naive Solution: Sort the array and check if ith element is a repeating element or not, if it is not then check if it is making a consective subsequence i.e element on its right is
#  1 greater than ith element. Keep on incrementing curr till this condition is true, if it becomes false update the res and change curr to 1.

int longestConsecutive(vector<int>& nums) {

    if (nums.size() == 0)
      return 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] != nums[i - 1])
      {
        if (nums[i] == nums[i - 1] + 1)
          curr++;
        else
        {
          res = max(res, curr);
          curr = 1;
        }

      }
    }
    res = max(res, curr);
    return res;
  }

TC:O(nlogn) AS:O(1)
  
Efficient Solution: 
int longestConsecutive(vector<int>& nums) {

      if (nums.size() == 0)
        return 0;
      int n = nums.size();

      unordered_set<int> s;
      for (int num : nums)
        s.insert(num);

      int res = 0;

      for (int num : nums)
      {
        if (!s.count(num - 1))
        {
          int currNum = num;
          int currStreak = 1;

          while (s.count(currNum + 1))
          {
            currNum += 1;
            currStreak += 1;
          }

          res = max(res, currStreak);
        }
      }
      return res;

    }
TC:O(N)  TC:O(N)
Refer Strivers video 
