Naive: Find all possible pairs 
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j] == k)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};

Efficient Solution: Using hashing
//code by vbhv17
class Solution {
public:
  int getPairsCount(int arr[], int n, int sum) {

    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int rem = sum - arr[i];

      if (mp.find(rem) != mp.end())
      {
        int count = mp[rem];
        for (int i = 0; i < count; i++)
        {
          ans++;
        }
      }

      mp[arr[i]]++;
    }
    return ans;
  }
};

TC: O(N) SC:O(N)
