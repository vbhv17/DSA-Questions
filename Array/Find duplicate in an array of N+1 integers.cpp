https://leetcode.com/problems/find-the-duplicate-number/submissions/

// Naive approach: Sort the array and check if ith is equal to i+1th element. Return nums[i] if equal.
// TC: O(NlogN) SC: O(1)
  
Better Solution: Using Set 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        map<int,int>m;        // creates a map for all the elements present in nums
        for(auto i : nums)
        {
           if(m[i]==1)  // if the element -> i is already present
           {
               ans = i;
               break;
           }
           m[i]=1;  // to show the element-> i  is present 
        }
        return ans; 
    }
};



Best Solution: Linked List Cycle Method
https://www.youtube.com/watch?v=32Ll35mhWg0&ab_channel=takeUforward

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];     
        }
        
        return slow;
    }
};

TC: O(N)  SC:O(1)
  
  
  
// Tricky Solution:
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums)
//     {
//         int i=0;
//         while(nums[i]>0){
//             nums[i]*=-1;
//             i=abs(nums[i]);
//         }
//         return i;
//     }
// };

// ***This solution modifies the array***
